#include <stdio.h>
#define MAXN 100000

void shift_down(int curheap[], int cur_size, int now);
int heapbuild(int curheap[], int cur_size) {
  if (!cur_size || cur_size == 1)
    return 0;
  int last_parent = (cur_size + 1) / 2;
  for (int i = last_parent; i >= 1; --i) {
    int child = i * 2;
    if (cur_size >= (child + 1) && curheap[child + 1] < curheap[child])
      ++child;
    if (curheap[child] < curheap[i]) {
      shift_down(curheap, cur_size, i);
    }
  }
  return 1;
}
void shift_down(int curheap[], int cur_size, int now) {
  int i = now;
  while (2 * i <= cur_size) {
    int child = i * 2;
    if (cur_size >= (child + 1) && curheap[child + 1] < curheap[child])
      ++child;
    if (curheap[child] < curheap[i]) {
      int tmp = curheap[child];
      curheap[child] = curheap[i];
      curheap[i] = tmp;
      i = child;
    } else
      break;
  }
}
int main() {
  int N, M;
  int result_index = -1;
  int result[MAXN] = {0};
  int cur_size = 0;
  int next_size = 0;
  int curheap[MAXN] = {0};
  int nextheap[MAXN] = {0};
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    int x;
    scanf("%d", &x); // scan the next data
    ++cur_size;
    curheap[cur_size] = x;
  }
  heapbuild(curheap, cur_size);
  int count = M - 1;
  while (cur_size) {
    while (cur_size > 0) {
      int min = curheap[1];
      curheap[1] = curheap[cur_size];
      if (result_index == -1 || min > result[result_index]) {
        result[++result_index] = min;
        int x;
        ++count;
        if (count < N)
          scanf("%d", &x);
        if (count < N) {
          curheap[cur_size] = x;
          ++cur_size;
        }
        --cur_size;
      } else {
        nextheap[++next_size] = min;
        --cur_size;
      }
      shift_down(curheap, cur_size, 1);
    }
    for (int i = 0; i <= result_index; ++i) {
      printf("%d ", result[i]);
      result[i] = 0;
    }
    putchar(10);
    result_index = -1;
    cur_size = next_size;
    for (int i = 1; i <= next_size; ++i) {
      curheap[i] = nextheap[i];
    }
    heapbuild(curheap, cur_size);
    next_size = 0;
  }
}
