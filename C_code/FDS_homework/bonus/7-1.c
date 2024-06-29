#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
typedef struct node {
  int value;
  struct node *next;
  int reptimes;
} *Node;
typedef struct hisarr {
  int times;
  int size;
  int now_size;
  Node head;
} *Hisarr;
Node gettail(Hisarr arr) {
  Node p = arr->head;
  while (p->next) {
    p = p->next;
  }
  return p;
}
void Cac_pop(Hisarr arr, Node check[], Hisarr now, Node now_check[]) {
  check[(arr->head->next)->value]->value = 0;
  now_check[(arr->head->next)->value]->value = 0;
  check[(arr->head->next)->value]->next->reptimes = 0;
  Node p = arr->head->next;
  arr->head->next = arr->head->next->next;
  check[p->value]->next->next = NULL;
  --(arr->now_size);
}
void Cac_push(Hisarr arr, Node check[], int value, Hisarr now,
              Node now_check[]) {
  if (!check[value]) {
    if (arr->now_size == arr->size) {
      Cac_pop(arr, check, now, now_check);
    }
    check[value] = (Node)malloc(sizeof(struct node));
    check[value]->value = 1;
    check[value]->next = NULL;
    check[value]->reptimes = 0;
    Node T = (Node)malloc(sizeof(struct node));
    T->value = value;
    T->next = NULL;
    T->reptimes = 0;
    check[value]->next = T;
    gettail(arr)->next = T;
    T->next = NULL;
    ++(arr->now_size);
  } else if (check[value]->value == 1) {
    Node p = arr->head->next;
    Node pre = arr->head;
    while (p->value != value) {
      pre = p;
      p = p->next;
    }
    pre->next = p->next;
    p->next = NULL;
    gettail(arr)->next = p;
  } else if (check[value]->value == 0) {
    if (arr->now_size == arr->size) {
      Cac_pop(arr, check, now, now_check);
    }
    check[value]->value = 1;
    Node p = check[value]->next;
    gettail(arr)->next = p;
    p->next = NULL;
    ++(arr->now_size);
  }
}
void His_pop(Hisarr arr, Node check[]) {
  check[(arr->head->next)->value]->value = 0;
  check[(arr->head->next)->value]->reptimes = 0;
  check[(arr->head->next)->value]->next->reptimes = 0;
  Node p = arr->head->next;
  arr->head->next = arr->head->next->next;
  check[(p)->value]->next->next = NULL;
  --(arr->now_size);
}
void His_push(Hisarr arr, Node check[], int value, Hisarr cac,
              Node check_cac[]) {
  if (!check[value]) {
    if (arr->now_size == arr->size) {
      His_pop(arr, check);
    }
    check[value] = (Node)malloc(sizeof(struct node));
    check[value]->value = 1;
    check[value]->next = NULL;
    check[value]->reptimes = 0;
    Node T = (Node)malloc(sizeof(struct node));
    T->value = value;
    T->next = NULL;
    T->reptimes = 1;
    check[value]->next = T;
    gettail(arr)->next = T;
    T->next = NULL;
    ++(arr->now_size);
  } else if (check[value]->value == 1) {
    Node p = arr->head->next;
    Node pre = arr->head;
    while (p->value != value) {
      pre = p;
      p = p->next;
    }
    pre->next = p->next;
    p->next = NULL;
    ++(check[value]->next->reptimes);
    if (check[value]->next->reptimes == arr->times) {
      check[value]->value = -1;
      --(arr->now_size);
      Cac_push(cac, check_cac, value, arr, check);
    } else {
      gettail(arr)->next = p;
    }
  } else if (check[value]->value == 0) {
    ++(check[value]->next->reptimes);
    if (check[value]->next->reptimes == arr->times) {
      check[value]->value = -1;
      Cac_push(cac, check_cac, value, arr, check);
    } else {
      if (arr->now_size == arr->size) {
        His_pop(arr, check);
      }
      check[value]->value = 1;
      Node p = check[value]->next;
      gettail(arr)->next = p;
      p->next = NULL;
      ++(arr->now_size);
    }
  } else if (check[value]->value == -1) {
    Cac_push(cac, check_cac, value, arr, check);
  }
}
void initalize(Hisarr arr, int K, int N) {
  arr->times = K;
  arr->size = N;
  arr->now_size = 0;
  arr->head = (Node)malloc(sizeof(struct node));
}
int main() {
  int K, N, M;
  Node check_His[MAXN] = {0};
  Node check_Cac[MAXN] = {0};
  Hisarr arr = (Hisarr)malloc(sizeof(struct hisarr));
  Hisarr cac = (Hisarr)malloc(sizeof(struct hisarr));
  scanf("%d%d%d", &K, &N, &M);
  initalize(arr, K, N);
  initalize(cac, K, N);
  for (int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    His_push(arr, check_His, x, cac, check_Cac);
    if (i == 0)
      arr->head->next = gettail(arr);
  }
  int flag1 = 0;
  int flag2 = 0;
  Node p = arr->head->next;
  while (p) {
    if (p->next)
      printf("%d ", p->value);
    else
      printf("%d", p->value);
    p = p->next;
    flag1++;
  }
  if (!flag1)
    printf("-");
  putchar(10);
  Node ptr = cac->head->next;
  while (ptr) {
    if (ptr->next)
      printf("%d ", ptr->value);
    else
      printf("%d", ptr->value);
    ptr = ptr->next;
    ++flag2;
  }
  if (!flag2)
    printf("-");
  for (int i = 0; i < M; ++i) {
    if (check_His[i])
      free(check_His[i]);
    if (check_Cac[i])
      free(check_Cac[i]);
  }
  free(arr);
  free(cac);
  return 0;
}
