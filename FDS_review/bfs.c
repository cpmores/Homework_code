//in this section, we will complement breadth first search using queue, which means first in and first out.
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
typedef struct Queue
{
  int head;
  int rear;
  tree arr[MAXN];
}*queue;
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
void q_init(queue Q)
{
  Q -> head = 0;
  Q -> rear = 0;
}

void q_push(queue Q, tree N)
{
  Q -> arr[Q -> rear++] = N;
}

tree q_pop(queue Q)
{
  return Q -> arr[Q -> head++];
}

int q_check(queue Q)
{
  if (Q -> rear == Q -> head && Q -> head)
    return 1;
  return 0;
}
int main()
{
  tree root = addedge(20);
  queue Q = (queue)malloc(sizeof(struct Queue));
  q_init(Q);
  q_push(Q, root);
  while(!q_check(Q))
  {
    if(Q -> arr[Q -> head] -> lkid)
      q_push(Q, Q -> arr[Q -> head] -> lkid);
    if(Q -> arr[Q -> head] -> rkid)
      q_push(Q, Q -> arr[Q -> head] -> rkid);
    tree tmp = q_pop(Q);
    printf("%d ", tmp -> value);
  }
  free(Q);
  return 0;
}
