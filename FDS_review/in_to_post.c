#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

char ans[MAXN];

typedef struct Stack {
  int top;
  char arr[MAXN];
} *stack;

void s_init(stack S) { S->top = -1; }

void s_push(stack S, char now) {
  ++(S->top);
  S->arr[S->top] = now;
}

int s_check(stack S) {
  if (S->top == -1)
    return 0;
  return 1;
}

char s_pop(stack S) {
  --(S->top);
  return S->arr[S->top + 1];
}

int priority(char x) {
  if (x == '*' || x == '/')
    return 3;
  else if (x == '+' || x == '-')
    return 2;
  else if (x == '(')
    return 1;
  return 0;
}

int change(char *in_order, int index) {
  stack S = (stack)malloc(sizeof(struct Stack));
  s_init(S);
  char x;
  int now = 0;
  int i = 0;
  while (i < index) {
    x = in_order[i];
    if (x >= '0' && x <= '9') {
      ans[now++] = x;
    } else if (x == '(') {
      s_push(S, x);
    } else if (x == ')') {
      while (s_check(S) && S->arr[S->top] != '(') {
        char out = s_pop(S);
        ans[now++] = out;
      }
      if (!s_check(S)) {
        // 没有对应的左括号，表达式不合法
        return 0;
      }
      // 弹出左括号
      s_pop(S);
    } else {
      while (s_check(S) && priority(x) <= priority(S->arr[S->top])) {
        char out = s_pop(S);
        ans[now++] = out;
      }
      s_push(S, x);
    }
    i++;
  }
  // 将栈中剩余的运算符弹出
  while (s_check(S)) {
    char out = s_pop(S);
    ans[now++] = out;
  }
  return 1;
}

int main() {
  char in_order[MAXN];
  char x;
  int index = 0;
  while ((x = getchar()) != '\n')
    in_order[index++] = x;
  in_order[index] = '\0';
  if (!change(in_order, index)) {
    printf("Invalid expression!\n");
    return 1;
  }
  ans[index] = '\0';
  printf("%s\n", ans);
  return 0;
}
