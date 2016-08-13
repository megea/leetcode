#include <stdio.h>
#include <limits.h>
//#define BASE 10

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
        iTemp = x % 10;
        if(iRet > (INT_MAX - iTemp)/10)
        {
            return 0;   //Ô½½ç
        }
        else
        {
            iRet = iRet * 10 + iTemp;
        }
        x = x/10;
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


