#include <stdio.h>
int main()
{
    int num;
    int binary_num[100];
    int index_ptr = 0;
    int x;
    printf("Please enter the Decimal number to convert it into Binary :");
    scanf("%d", &num);
    if (num == 0)
    {
        printf("%d", 0);
    }
    else
    {
        while (num)
        {
            x = num % 2;
            binary_num[index_ptr++] = x;
            num = num / 2;
        }
        for (int i = index_ptr - 1; i >= 0; i--)
        {
            printf("%d", binary_num[i]);
        }
    }
    return 0;
}