;----------������´��뱣�浽src\main.asm------------------------------
;----------ѡ��main.sh��src�ļ���->�Ҽ�->ѹ����submit.zip�ύ----------
.386
data segment use16
sth db 10 dup(0)
s db 10 dup('S'), 0; ����ʱ����s�ĳ��ȼ����ݺʹ���������һ��,
                   ; ��sһ����һ������C���Ա�׼���ַ���
data ends

code segment use16
assume cs:code, ds:data
main:
   mov ax, data
   mov ds, ax
;��#1_begin��#1_end֮�䲹�����ʵ��puts(s)��Ч��,����������ַ���s����������,����Ҫ�����0Dh��0Ah
;#1_begin--------------------------------------

   xor bx, bx
   xor ax, ax
   xor dx, dx
output:
   mov ax,word ptr s[bx]
   cmp ax, 0
   je end_output
   mov dl, s[bx]
   mov ah, 02h
   int 21h
   inc bx
   jmp output
end_output:
   mov dl, 0Dh
   mov ah, 02h
   int 21h
   mov dl, 0Ah
   int 21h

;#1_end----------------------------------------
   mov ah, 4Ch
   int 21h
code ends
end main
;----------������ϴ��뱣�浽src\main.asm------------------------------
