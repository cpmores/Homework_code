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
   mov ecx, 0 ;store loading number
   mov edx, 0 ;store result now
check:
   dec bl
   jz result

   lodsb
   cmp al, '0'
   jb operator


operator:
   cmp prev_op, 1
   je add_op
   cmp prev_op, 2
   je mul_op
   cmp prev_op, 3
   je div_op
   jmp result

add_op:
   mov prev_op, al
   add edx, ecx
   xor ecx, ecx
   jmp check

mul_op:
   mov prev_op, al
   mov eax, edx
   mul ecx
   mov edx, eax
   xor ecx, ecx
   jmp check

div_op:
   mov prev_op, al
   mov eax, edx
   div ecx
   and eax, 0000FFFFh
   mov edx, eax
   xor ecx, ecx
   jmp check   

result:
   mov [b], edx
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
