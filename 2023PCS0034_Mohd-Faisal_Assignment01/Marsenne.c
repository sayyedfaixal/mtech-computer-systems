#include <stdio.h>
int checkPrime(int n)
{
    int flag = 1;
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        return 1;
    else
        return 0;
}
int checkMarsenne(int num)
{
    int power = 1;
    int copy_num = num;
    while (copy_num > 1)
    {
        if (copy_num % 2 != 0)
            return -1;
        else
        {
            copy_num = copy_num / 2;
            power++;
        }
    }
    if (checkPrime(power))
        return 1;
    else
        return 0;
}
int main()
{
    int num;
    printf("Enter a number to check for Marsenne Prime  - ");
    scanf("%d", &num);
    if (checkPrime(num))
    {
        if (checkMarsenne(num))
        {
            printf("%d is a Marsenne Prime number ", num);
        }
        else
        {
            printf("%d is not a Marsenne Prime number\n");
        }
    }
    else
    {
        printf("%d is not a Marsenne Prime number\n", num);
    }
    return 0;
}