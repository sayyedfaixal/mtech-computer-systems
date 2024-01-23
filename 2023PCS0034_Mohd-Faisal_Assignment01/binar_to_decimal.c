#include <stdio.h>
int main()
{
    int binary_num, copy_binary_num;
    int decimal_num = 0;
    int extract_digit;
    int temp = 1;
    printf("Enter the binary number to convert it into Decimal : ");
    scanf("%d", &binary_num);
    copy_binary_num = binary_num;
    while (copy_binary_num)
    {
        extract_digit = copy_binary_num % 10;
        decimal_num = decimal_num + (extract_digit * temp);
        temp = temp * 2;
        copy_binary_num /= 10;
    }
    printf("Decimal of %d is %d", binary_num, decimal_num);
    return 0;
}