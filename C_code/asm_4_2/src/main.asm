;==========请把以下代码保存到src\main.asm==============================
;==========选中main.sh及src文件夹->右键->压缩成submit.zip提交==========
.386
data segment use16
sth db 10h dup(0)
n dw 00F00h

s db 10h dup(0)
data ends

code segment use16
assume cs:code, ds:data
;void f(short int n, char s[])
;注意f()的参数通过堆栈传递,其中n就是[bp+4], s就是[bp+6]。
;在函数f()中不可直接引用data段中的变量n及数组s, 否则会产生编译错误。
f proc near
push bp
mov bp, sp
;请在#1_begin和#1_end之间补充代码实现以下功能:
;把16位符号数n转化成十进制字符串保存到数组s中,并在字符串后面填充'′;例如,当n=0FFF0h时,s的内容为:′−′,′1′,′6′,′′;例如,当n=0FFF0h时,s的内容为:′−′,′1′,′6′,′'
;#1_begin-----------=========------------------
   mov ax, [bp+4]
   xor di, di
   mov di, [bp+6]
check:
   and ax, 1000000000000000b
   cmp ax, 1000000000000000b
   je negative
   jmp convert_10000
negative:
   mov cl, '-'
   mov [di], cl
   mov ax, [bp+4]
   not ax
   inc di
   inc ax
   mov [bp+4], ax
   jmp convert_10000_r
convert_10000_r:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 10000
   div cx
   cmp ax, 0
   je convert_1000_r
   mov [bp+4], dx
   add ax, '0'
   mov [di], al
   inc di
   jmp convert_1000_r

convert_1000_r:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 1000
   div cx
   mov bx, di
   sub bx, 1
   cmp bx, [bp+6] 
   jne convert_1000_1_r
   cmp ax, 0
   je convert_100_r
convert_1000_1_r:
   mov [bp+4], dx
   add ax, '0'
   mov [di], al
   inc di
   jmp convert_100_r

convert_100_r:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 100
   div cx
   mov bx, di
   sub bx, 1
   cmp bx, [bp+6] 
   jne convert_100_1_r
   cmp ax, 0
   je convert_10_r
convert_100_1_r:
   mov [bp+4], dx
   add al, '0'
   mov [di], al
   inc di
   jmp convert_10_r

convert_10_r:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 10
   div cx
   mov bx, di
   sub bx, 1
   cmp bx, [bp+6] 
   jne convert_10_1_r
   cmp ax, 0
   je convert_1_r
convert_10_1_r:
   mov [bp+4], dx
   add al, '0'
   mov [di], al
   inc di
   jmp convert_1_r

convert_1_r:
   xor dx, dx
   mov ax, [bp+4]
   add al, '0'
   mov [di], al
   inc di
   mov al, '$'
   mov [di], al
   jmp ed
convert_10000:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 10000
   div cx
   cmp ax, 0
   je convert_1000
   mov [bp+4], dx
   add al, '0'
   mov [di], al
   inc di
   jmp convert_1000

convert_1000:
   xor dx, dx
   xor cx, cx
   mov ax, [bp+4]
   mov cx, 1000
   div cx
   cmp di, [bp+6]
   jne convert_1000_1
   cmp ax, 0
   je convert_100
convert_1000_1:
   mov [bp+4], dx
   add al, '0'
   mov [di], al
   inc di
   jmp convert_100

convert_100:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 100
   div cx
   cmp di, [bp+6]
   jne convert_100_1
   cmp ax, 0
   je convert_10
convert_100_1:
   mov [bp+4], dx
   add al, '0'
   mov [di], al
   inc di
   jmp convert_10

convert_10:
   xor dx, dx
   mov ax, [bp+4]
   mov cx, 10
   div cx
   cmp di, [bp+6]
   jne convert_10_1
   cmp ax, 0
   je convert_1
convert_10_1:
   mov [bp+4], dx
   add al, '0'
   mov [di], al
   inc di
   jmp convert_1

convert_1:
   xor dx, dx
   mov ax, [bp+4]
   add al, '0'
   mov [di], al
   inc di
   mov al, '$'
   mov [di], al
   jmp ed

ed:
;#1_end-------------=========------------------
pop bp
ret
f endp

main:
   mov ax, data
   mov ds, ax
   mov ax, offset s
   push ax
   push [n]
   call f
   add sp, 4
   mov ah, 9
   mov dx, offset s
   int 21h
   mov ah, 4Ch
   int 21h
code ends
end main
;==========请把以上代码保存到src\main.asm==============================