;本题要求:
comment %
键盘输入一个表达式, 该表达式中包含若干个十进制非符号数(≤4294967295)及以下运算符:
   + * /
输出该表达式的十六进制值。
其中除法运算只需要计算商(丢弃余数),
表达式中的运算符不需要考虑优先级即一律按从左到右顺序计算。
若表达式中的任何一步计算结果超过32位(即大于0FFFFFFFFh),
则该步运算结果仅保留低32位(丢弃高32位)。
例如：
输入：
12345+56789*54321/9876
输出：
0005CD62
=======================================================================%
;==========请把以下代码保存到src\main.asm==============================
;==========选中main.sh及src文件夹->右键->压缩成submit.zip提交==========
.386
data segment use16
t db "0123456789ABCDEF"
buf  db 81, 0, 81 dup(0)
b    dd 0
c    dd 0
prev_op  dw 1; 1 means '+', 2 means '*', 3 means '/', 0 means '\0'
fun  dw 0000h, fun_add, fun_mul, fun_div
s    db 00h, '+', '*', '/'
data ends

code segment use16
assume cs:code, ds:data
output:
   push eax
   push ebx
   push ecx
   push edx
   mov bx, offset t
   mov ecx, 8
next:
   rol eax, 4
   push eax
   and eax, 0Fh
   xlat
   mov ah, 2
   mov dl, al
   int 21h
   pop eax
   loop next
   mov ah, 2
   mov dl, 0Dh
   int 21h
   mov dl, 0Ah
   int 21h
   pop edx
   pop ecx
   pop ebx
   pop eax
   ret

main:
   cld
   mov ax, data
   mov ds, ax
   mov ah, 0Ah
   mov dx, offset buf
   int 21h
   xor bx, bx
   mov bl, buf[1]    ; BL=输入字符串的长度
   mov buf[bx+2], 00h; 把输入的回车符替换成00h
                     ; buf[2]起是字符串的内容
   mov ah, 2
   mov dl, 0Dh
   int 21h           ; 输出回车
   mov dl, 0Ah
   int 21h           ; 输出换行
   ;
   lea si, buf[2]    ; ds:si->输入的字符串
   ;
;请在#1_begin和#1_end之间补充代码实现以下功能:
;    计算ds:si指向的表达式,运算结果保存到变量[b]中
;注意: 
;    所有补充代码包括自定义函数及变量均必须
;    放在#1_begin和#1_end之间
;#1_begin-------------------------------------
check:
   xor edx, edx
   xor ebx, ebx
   xor eax, eax
   xor ecx, ecx
   lodsb
   cmp ax, '0'
   jb op_first
   sub eax, '0'
   mov ebx, eax 
   mov eax, [c]
   mov ecx, 0Ah
   mul ecx
   add eax, ebx
   mov [c], eax
   jmp check

op_first:
   cmp ax, '+'
   je add_op
   cmp ax, '*'
   je mul_op
   cmp ax, '/'
   je div_op
   cmp ax, 00h
   je last_operator

add_op:
   mov ax, 1
   jmp operator
mul_op:
   mov ax, 2
   jmp operator
div_op:
   mov ax, 3
   jmp operator

operator:
   cmp prev_op, 1
   je fun_add
   cmp prev_op, 2
   je fun_mul
   cmp prev_op, 3
   je fun_div
   jmp result

last_operator:
   cmp prev_op, 1
   je fun_add_last
   cmp prev_op, 2
   je fun_mul_last
   cmp prev_op, 3
   je fun_div_last
   jmp result

fun_add:
   mov prev_op, ax
   mov ecx, [c]
   mov eax, [b]
   add eax, ecx
   mov [b], eax
   jmp clear

fun_mul:
   mov prev_op, ax
   mov ecx, [c]
   mov eax, [b] 
   mul ecx
   mov [b], eax
   jmp clear

fun_div:
   mov prev_op, ax
   mov ecx, [c]
   mov eax, [b] 
   xor edx, edx
   div ecx
   mov [b], eax
   jmp clear

clear:
   xor eax, eax
   xor ebx, ebx
   xor ecx, ecx
   xor edx, edx
   mov [c], ecx
   jmp check

fun_add_last:
   mov prev_op, ax
   mov ecx, [c]
   mov eax, [b]
   add eax, ecx
   mov [b], eax
   jmp clear_last

fun_mul_last:
   mov prev_op, ax
   mov ecx, [c]
   mov eax, [b] 
   mul ecx
   mov [b], eax
   jmp clear_last

fun_div_last:
   mov prev_op, ax
   mov ecx, [c]
   mov eax, [b]
   xor edx, edx 
   div ecx
   mov [b], eax
   jmp clear_last

clear_last:
   xor eax, eax
   xor ebx, ebx
   xor ecx, ecx
   xor edx, edx
   mov [c], edx
   jmp result


result:
   jmp do_output

;#1_end=======m================================
do_output:
   mov eax, [b]
   call output; 用16进制格式输出变量b的值
exit:
   mov ah, 4Ch
   int 21h
code ends
end main
;==========请把以上代码保存到src\main.asm==============================
