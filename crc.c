#include <stdio.h>
#include<conio.h>
void main()
{
    int i, j, k, arr[30], gen[10], t[40], n, g;
    printf("enter the no. of data bits to be transmitted:");
    scanf("%d", &n);
    printf("enter the no. of bits in generator:");
    scanf("%d", &g);
    printf("enter the data bits to be transmitted:");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter the generator bits:");
    for (i = 0; i < g; i++)
        scanf("%d", &gen[i]);
    for (i = 0; i < n; i++)
        t[i] = arr[i];
    for (i = n; i < (n + g - 1); i++)
        arr[i] = 0;
    printf("At sender's side");
    printf("\nafter appending zeros  at end of data bits:");
    for (i = 0; i < (n + g - 1); i++)
        printf("%d", arr[i]);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            k = 0;
            for (j = i; j < (i + g); j++)
            {
                arr[j] = arr[j] ^ gen[k];
                k++;
            }
        }
        else
            for (j = i; j < (i + g); j++)
                arr[j] = arr[j] ^ 0;
    }
    printf("\ncrc is:");
    for (i = n; i < (n + g - 1); i++)
        printf("%d", arr[i]);
    for (i = n; i < (n + g - 1); i++)
        t[i] = arr[i];
    printf("\ndata bits to be transmitted is:");
    for (i = 0; i < (n + g - 1); i++)
        printf("%d", t[i]);
    printf("\n At Receiver side");
    for (i = 0; i < (n + g - 1); i++)
        arr[i] = t[i];
    printf("\n Received data is:");
    for (i = 0; i < n + g - 1; i++)
        printf("%d", arr[i]);
    for (i = 0; i < (n + g - 1); i++)
    {
        if (arr[i] == 1)
        {
            k = 0;
            for (j = i; j < (i + g); j++)
            {
                arr[j] = arr[j] ^ gen[k];
                k++;
            }
        }
        else
            for (j = i; j < (i + g); j++)
                arr[j] = arr[j] ^ 0;
    }
    printf("\n crc is");
    for (i = n; i < (n + g - 1); i++)
        printf("%d", arr[i]);
}
