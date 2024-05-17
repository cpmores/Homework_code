#include <stdio.h>

#define MAXN 10000

int check(int check_seq[], int ans_next[], int N)
{
    for(int i = 1; i <= N ; ++i)
    {
        if(check_seq[i] != ans_next[i])
            return 0;
    }
    return 1;
}
int Insert_sort(int raw[], int check_seq[], int ans_next[], int N)
{   
    for(int i = 1; i <= N; ++i)
        ans_next[i] = raw[i];
    int flag = 0;
    for(int i = 2; i <=N ; ++i)
    {
        int now = i;
        while(now >= 2 && ans_next[now] < ans_next[now - 1])
        {   
            int temp = ans_next[now];
            ans_next[now] = ans_next[now - 1];
            ans_next[now - 1] = temp;
            --now;
        }
        if(flag)
            return 1;
        if(check(check_seq, ans_next, N))
            flag = 1;
    }
    return 0;
}

void downseq(int ans_next[], int now, int N)
{
    while(2*now <= N)
    {
        int child = now*2;
        if(child + 1 <= N&&ans_next[child + 1] > ans_next[child])
            ++child;
        if(ans_next[now] < ans_next[child])
        {
            int temp = ans_next[now];
            ans_next[now] = ans_next[child];
            ans_next[child] = temp;
            now = child;
        }
        else
            break;
    }
}

int Heap_sort(int raw[], int check_seq[], int ans_next[], int N)
{
    int flag = 0;
    for(int i = 1; i <= N; ++i)
        ans_next[i] = raw[i];
    for(int i = N/2; i >= 1; --i)
        downseq(ans_next, i, N);//build a heap
    if(check(check_seq, ans_next, N))
        return 1;
    int temp = ans_next[1];
    ans_next[1] = ans_next[N];
    ans_next[N] = temp;
    for(int i = N - 1; i >= 1; --i)
    {   
        downseq(ans_next, 1, i);
 
        if (flag)
            return 1;
        if(check(check_seq, ans_next, N))
            flag = 1;
        int temp = ans_next[1];
        ans_next[1] = ans_next[i];
        ans_next[i] = temp;
 
    }
    return 0;
    
}

int main()
{
    int N;
    int raw[MAXN] = {0};// store the raw sequence
    int check_seq[MAXN] = {0};//store the sequence we need to check
    int sort[MAXN] = {0};//store the sort sequence for each check
    int ans_next[MAXN] = {0};//store the next sequence answer
    scanf("%d", &N);
    for(int i = 1; i <= N ; ++i)
    {
        scanf("%d", &raw[i]);
    }
    for(int i = 1; i <= N ; ++i)
    {
        scanf("%d", &check_seq[i]);
    }
    if (Insert_sort(raw, check_seq, ans_next, N))
    {
        printf("Insertion Sort\n");
        for(int i = 1; i < N ; ++i)
            printf("%d ", ans_next[i]);
        printf("%d", ans_next[N]);
    }
    else 
    {
        Heap_sort(raw, check_seq, ans_next, N);
        printf("Heap Sort\n");
        for(int i = 1; i < N ; ++i)
            printf("%d ", ans_next[i]);
        printf("%d", ans_next[N]);
    }

    return 0;
}
