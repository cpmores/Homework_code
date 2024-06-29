#include <stdio.h>
#define MAXN 100000

void heapbuild(int curheap[], int cur_size) {
  int last_parent = cur_size / 2;
  for (int i = last_parent; i >= 1; --i) {
    int child = i * 2;
    if (cur_size >= (child + 1) && curheap[child + 1] < curheap[child])
      ++child;
    if (curheap[child] < curheap[i]) {
      int tmp = curheap[child];
      curheap[child] = curheap[i];
      curheap[i] = tmp;
    }
  }
}

void shift_down(int curheap[], int cur_size) {
  int i = 1;
  while (2 * i <= cur_size) {
    int child = i * 2;
    if (cur_size >= (child + 1) && curheap[child + 1] < curheap[child])
      ++child;
    if (curheap[child] < curheap[i]) {
      int tmp = curheap[child];
      curheap[child] = curheap[i];
      curheap[i] = tmp;
      i = child;
    } else {
      break;
    }
  }
}

int main() {
  int N, M;
  int result_index = 0; // Changed to 0
  int result[MAXN] = {0};
  int cur_size = 0;
  int next_size = 0;
  int curheap[MAXN + 1] = {0};  // Increase the size of the heap by 1
  int nextheap[MAXN + 1] = {0}; // Increase the size of the heap by 1

  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    int x;
    scanf("%d", &x);
    ++cur_size;
    curheap[cur_size] = x;
  }

  heapbuild(curheap, cur_size);

  while (cur_size >
         0) { // Added condition to ensure there are elements in the heap
    int min = curheap[1];
    result[result_index++] = min;

    if (result_index < N - 1) {
      int x;
      scanf("%d", &x);
      curheap[1] = x;
      shift_down(curheap, cur_size);
    } else {
      curheap[1] = curheap[cur_size--];
      shift_down(curheap, cur_size);
    }
  }

  for (int i = 0; i < result_index; ++i) { // Fixed loop condition
    printf("%d ", result[i]);
  }
  printf("\n");

  return 0;
}
