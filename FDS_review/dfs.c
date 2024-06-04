#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
int num;
//set a tree ndde
typedef struct Node
{
  int value;
  struct Node* lkid;
  struct Node* rkid;
}*tree;
typedef struct Stack
{
  int top;
  tree arr[MAXN];
}*stack;
//this function is to used to build a tree
void addNew(int value, tree T, int check)
{
  tree N = (tree)malloc(sizeof(struct Node));
  N -> value = value;
  N -> lkid = NULL;
  N -> rkid = NULL;
  if(check && num <= 10)
  {
    ++num;
    T -> lkid = N;
    addNew(value + 1, N, 1);
    addNew(value + 2, N, 0);
  }
  else if (num <= 10 && !check )
  {
    ++num;
    T -> rkid = N;
    addNew(value + 1, N, 1);
    addNew(value + 2, N, 0);
  }
}
tree addedge(int par)
{
  tree T = (tree)malloc(sizeof(struct Node));
  T -> lkid = NULL;
  T -> rkid = NULL;
  T -> value = par;
  if (num <= 10)
  {
    ++num;
    addNew(par + 1, T, 1);
    addNew(1, T, 0);
  }
  return T;
}
void s_init(stack Q)
{
  Q -> top = 0;
}

void s_push(stack Q, tree N)
{
  Q -> arr[Q -> top++] = N;
}

tree s_pop(stack Q)
{
  Q -> top--;
  return Q -> arr[Q -> top];
}

int s_check(stack Q)
{
  if (!Q -> top)
    return 1;
  return 0;
}
int main()
{
  tree root = addedge(20);
  stack Q = (stack)malloc(sizeof(struct Stack));
  s_init(Q);
  s_push(Q, root);
  while(!s_check(Q))
  {
    tree tmp = s_pop(Q);
    if(tmp -> lkid)
      s_push(Q, tmp -> lkid);
    if(tmp -> rkid)
      s_push(Q, tmp -> rkid);
    printf("%d ", tmp -> value);
    free(tmp);
  }
  free(Q);
  return 0;
}


