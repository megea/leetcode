/*
8. String to Integer (atoi)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi(char* str)
{
    if (NULL == str)
    {
        return 0;
    }

    long long val = 0;
    int sign = 1;
    while (*str == ' ')
        str++;
    if(*str == '-')
    {
        sign = -1;
        str++;
    }
    else if(*str == '+')
    {
         sign = 1;
         str++;
    }
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            break;
        else if(*str >= '0' && *str <= '9')
        {
            val = val * 10 + *str -48;
            if(val > 2147483648)
                break;
        }
        str++;
     }
     if((sign == -1) && (val > 2147483648)) //�����2147483648������-1*INT_MIN����
        return INT_MIN;
     if((sign == 1) && (val > 2147483647))  //�����2147483647��Ȼ������INT_MAX���������
        return INT_MAX;

     val = (int)sign * val;
     return val;

}

int main()
{
    char str[] = "-";
    int val = atoi(str);
//    int x = (-INT_MIN);
    int val1 = myAtoi(str);
    printf("val:%d\n", val);
    printf("val:%d\n", val1);
//    printf("%d\n",x);
    return 0;
}
