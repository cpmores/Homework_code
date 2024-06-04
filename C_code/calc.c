#include <stdio.h>
typedef unsigned char byte;
typedef unsigned long int dword;
typedef void FUN(void);
void fun_add(void);
void fun_mul(void);
void fun_div(void);
FUN *fun[4] = {NULL, fun_add, fun_mul, fun_div}; /* fun是函数指针数组 */
dword b=0, c=0;  /* b为前项值, c为当前项值 */
byte s[4] = {'\0', '+', '*', '/'};
int prev_op = 1; /* 前运算符在数组s中的下标 */

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


/* 算法描述:
   (1) 假定正在处理字符串"10*"中的'*'
   已知前项值b = 0, 当前项值c = 10, 前运算符在数组s中的下标prev_op = 1, 
   故我们要计算b = b + c = 0 + 10 = 10, 再做c = 0, 并把当前运算符'*'
   在数组s中的下标2赋值给prev_op, 即prev_op = 2;
   (2) 假定正在处理字符串"10*20/"中的'/'
   已知前项值b = 10, 当前项值c = 20, prev_op = 2, 
   故我们要计算b = b * c = 10 * 20 = 200, 再做c = 0以及prev_op = 3;
   (3) 假定正在处理字符串"10*20/100"中的'\0'
   已知前项值b = 200, 当前项值c = 100, prev_op = 3,
   故我们要计算b = b / c = 200 / 100 = 2, 再做c = 0以及prev_op = 0;
   (4) 当检测到prev_op == 0时循环结束
 */
void process(byte a)
{
   int i;
   for(i=0; i<sizeof(s); i++)
   {
      if(a == s[i])
         break;
   }
   if(i < sizeof(s)) /* a是一个运算符 */
   {
      (*fun[prev_op])(); /* 根据前运算符选择相关函数计算b+=c、b*=c、b/=c */
      prev_op = i;       /* prev_op = 当前运算符的下标 */
   }
   else              /* a是一个数字字符 */
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
