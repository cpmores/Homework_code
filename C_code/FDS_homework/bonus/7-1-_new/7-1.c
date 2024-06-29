#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
typedef struct Node {
  int value;
  struct Node *next;
} *node;
typedef struct Queue {
  int size;
  int count;
  node front;
  node rear;
} *queue;
void Node_init(node N, int value) {
  N = (node)malloc(sizeof(struct Node));
  N->value = value;
  N->next = NULL;
}
void q_init(queue Q, int size) {
  Q = (queue)malloc(sizeof(struct Queue));
  Q->size = size;
  Q->count = 0;
  Node_init(Q->front, 0);
  Node_init(Q->rear, -1);
  Q->front = Q->rear;
}
int check_full(queue Q) {
  if (Q->size > Q->count)
    return 1; // 1 represents not full
  return 0;   // 0 represents full
}
void q_push(queue Q, int index) {
  node new;
  Node_init(new, index);
  Q->rear->next = new;
  Q->rear = new;
}
void q_delete(queue Q, node *adr[MAXN], node *adr_pre[MAXN], int index) {
  (*adr_pre[index])->next = (*adr[MAXN])->next;
  adr[index] = NULL;
  adr_pre[index] = NULL;
  Q->count--;
}
int main() {
  int k, m, n;
  int cac_times[MAXN] = {0};
  int hist_times[MAXN] = {0};
  node *adr_cac[MAXN] = {0};
  node *adr_cac_pre[MAXN] = {0};
  node *adr_hist[MAXN] = {0};
  node *adr_hist_pre[MAXN] = {0};
  scanf("%d%d%d", &k, &m, &n);
  queue cac;
  queue hist;
  q_init(cac, m);
  q_init(hist, m);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    if (cac_times[x] != 0) {
      q_delete(cac, adr_cac, adr_cac_pre, x);
    }
  }
}
