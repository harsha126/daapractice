#include <stdio.h>
#include <conio.h>

// rand () & (upper- Lower+1) +Lower;

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d,", a[i]);
    printf("\n");
}

void mem(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = 0;
}
void main()
{
    int tottat = 0, totwt = 0, upper = 6, lower = 1, proc, currTime = 0, totbt = 0, j = 0, curMin, i, n, minIndex = 0;
    int at[100], bt[100], dbt[100], ct[100], wt[100], tat[100], dat[100], res[100];
    float avg_tat, avg_wt;
    printf("enter the no of processes : ");
    scanf("%d", &n);
    mem(res, 67);
    printf("\nenter the arriving time of processes : ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);
    printf("\nenter the burst  time of processes : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        dbt[i] = bt[i];
        totbt += bt[i];
    }

    int curRunning = 0;
    for (i = 0; i <= totbt; i++)
    {
        curMin = 999;
        minIndex = 0;
        for (j = 0; j < n; j++)
        {
            if (dbt[j] > 0 && at[j] <= i && dbt[j] < curMin)
            {
                minIndex = j;
                curMin = dbt[j];
            }
        }
        if (i == 0)
            curRunning = minIndex;
        else
        {
            if (dbt[curRunning] == 0)
            {
                ct[curRunning] = i;
                curRunning = minIndex;
            }
            else if (dbt[curRunning] > dbt[minIndex])
            {
                curRunning = minIndex;
            }
        }
        dbt[curRunning]--;
        res[i] = curRunning + 1;
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        tottat += tat[i];
        wt[i] = tat[i] - bt[i];
        totwt += wt[i];
    }
    avg_tat = (float)tottat / n;
    avg_wt = (float)totwt / n;
    printArray(ct, n);
    printArray(res,totbt);
    printf("process|at|bt|wt|tat\n");
    for (int i = 0; i < n; i++)
    {
        printf("   p%d    %d| %d| %d| %d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("avg_tat : %f\n", avg_tat);
    printf("avg_wt  : %f\n", avg_wt);
}