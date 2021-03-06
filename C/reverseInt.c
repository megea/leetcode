/*
7. Reverse Integer
*/

#include <stdio.h>
#include <limits.h>
#define BASE 10

int reverse(int x)
{
    int iSign;
    int iTemp = 0;
    int iRet = 0;

    if(0 == x)
    {
        return x;
    }
    else if(x < 0)
    {
        iSign = -1;
        x = -x;
    }
    else
    {
        iSign = 1;
    }
    while (0 != x)
    {
        iTemp = x % BASE;
        if(iRet > (INT_MAX - iTemp)/BASE)
        {
            return 0;   //Խ��
        }
        else
        {
            iRet = iRet * BASE + iTemp;
        }
        x = x/BASE;
    }
    return iRet * iSign;
}
int main()
{

    int x = 12345;
    int y = -2147483648;
//    int y = -12345;
    x = reverse(x);
    y = reverse(y);
    printf("x:%d\ny:%d\n%d\n%d\n", x, y, INT_MAX, INT_MIN);
    return 0;
}


