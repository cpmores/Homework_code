;����Ҫ��:
comment %
��������һ�����ʽ, �ñ��ʽ�а������ɸ�ʮ���ƷǷ�����(��4294967295)�����������:
   + * /
����ñ��ʽ��ʮ������ֵ��
���г�������ֻ��Ҫ������(��������),
���ʽ�е����������Ҫ�������ȼ���һ�ɰ�������˳����㡣
�����ʽ�е��κ�һ������������32λ(������0FFFFFFFFh),
��ò���������������32λ(������32λ)��
���磺
���룺
12345+56789*54321/9876
�����
0005CD62
=======================================================================%
;==========������´��뱣�浽src\main.asm==============================
;==========ѡ��main.sh��src�ļ���->�Ҽ�->ѹ����submit.zip�ύ==========
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
   mov bl, buf[1]    ; BL=�����ַ����ĳ���
   mov buf[bx+2], 00h; ������Ļس����滻��00h
                     ; buf[2]�����ַ���������
   mov ah, 2
   mov dl, 0Dh
   int 21h           ; ����س�
   mov dl, 0Ah
   int 21h           ; �������
   ;
   lea si, buf[2]    ; ds:si->������ַ���
   ;
;����#1_begin��#1_end֮�䲹�����ʵ�����¹���:
;    ����ds:siָ��ı��ʽ,���������浽����[b]��
;ע��: 
;    ���в����������Զ��庯��������������
;    ����#1_begin��#1_end֮��
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
   call output; ��16���Ƹ�ʽ�������b��ֵ
exit:
   mov ah, 4Ch
   int 21h
code ends
end main
;==========������ϴ��뱣�浽src\main.asm==============================
