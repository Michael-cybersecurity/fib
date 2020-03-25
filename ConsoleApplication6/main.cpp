﻿#include<stdio.h>
#include"queue.h"

void fib(int k, int max);
sequeuetp Q;

int main()
{
    initqueue(Q);
    int k, max;
    scanf("%d %d", &k, &max);
    fib(k, max);
}

void fib(int k, int max)
{
    int i, j;
    int f[MAXN] = { 0 };
    for (i = 0; i <= k - 2; i++)
    {
        f[i] = 0;
        Q.queue[i] = 0;
    }
    Q.queue[k - 1] = 1;
    Q.queue[k] = 1;
    Q.rear = k;
    int n = k + 1;
    f[k - 1] = 1;
    f[k] = 1;
    while (Q.queue[Q.rear] < max) {
        j = (Q.rear + 1) % (k + 1);
        f[n] = Q.queue[Q.rear] * 2 - Q.queue[j];
        Q.queue[j] = f[n];
        Q.rear = j;
        n++;
    }
    if (Q.queue[Q.rear] > max)
        n = n - 2;
    else
        n = n - 1;
    if (max == 1)
    {
        n = k;
        f[k] = 1;
    }
    if (max == 0)
        n = k - 2;


    for (i = 0; i < n ; i++)
    {
        printf("%d ", f[i]);
    }
    printf("%d\n", f[n]);
}
