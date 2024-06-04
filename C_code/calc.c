#include <stdio.h>
typedef unsigned char byte;
typedef unsigned long int dword;
typedef void FUN(void);
void fun_add(void);
void fun_mul(void);
void fun_div(void);
FUN *fun[4] = {NULL, fun_add, fun_mul, fun_div}; /* fun�Ǻ���ָ������ */
dword b=0, c=0;  /* bΪǰ��ֵ, cΪ��ǰ��ֵ */
byte s[4] = {'\0', '+', '*', '/'};
int prev_op = 1; /* ǰ�����������s�е��±� */

void fun_add(void)
{
   b += c;
   c = 0;
}
   
void fun_mul(void)
{
   b *= c;
   c = 0;
}

void fun_div(void)
{
   b /= c;
   c = 0;
}


/* �㷨����:
   (1) �ٶ����ڴ����ַ���"10*"�е�'*'
   ��֪ǰ��ֵb = 0, ��ǰ��ֵc = 10, ǰ�����������s�е��±�prev_op = 1, 
   ������Ҫ����b = b + c = 0 + 10 = 10, ����c = 0, ���ѵ�ǰ�����'*'
   ������s�е��±�2��ֵ��prev_op, ��prev_op = 2;
   (2) �ٶ����ڴ����ַ���"10*20/"�е�'/'
   ��֪ǰ��ֵb = 10, ��ǰ��ֵc = 20, prev_op = 2, 
   ������Ҫ����b = b * c = 10 * 20 = 200, ����c = 0�Լ�prev_op = 3;
   (3) �ٶ����ڴ����ַ���"10*20/100"�е�'\0'
   ��֪ǰ��ֵb = 200, ��ǰ��ֵc = 100, prev_op = 3,
   ������Ҫ����b = b / c = 200 / 100 = 2, ����c = 0�Լ�prev_op = 0;
   (4) ����⵽prev_op == 0ʱѭ������
 */
void process(byte a)
{
   int i;
   for(i=0; i<sizeof(s); i++)
   {
      if(a == s[i])
         break;
   }
   if(i < sizeof(s)) /* a��һ������� */
   {
      (*fun[prev_op])(); /* ����ǰ�����ѡ����غ�������b+=c��b*=c��b/=c */
      prev_op = i;       /* prev_op = ��ǰ��������±� */
   }
   else              /* a��һ�������ַ� */
   {
      c = c * 10 + (a - '0'); 
   }
}

main()
{
   byte buf[100];
   int i = 0;
   gets(buf);
   do
   {
      process(buf[i++]);
   } while(prev_op != 0);
   printf("%08lX\n", b);
}
