/*
9. Palindrome Number
*/

#include <stdbool.h>
#include <stdio.h>

//这个可以用栈匹配最方便
bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    if(x == 0)
        return true;

    int iStack[10] = {-1};
    int i = 0;
    int j = 0;

    while(x > 0)
    {
        iStack[i++] = x % 10;
        x =x/10;
    }

    i--;
    for(j = 0; j <= i; i--, j++)
    {
        if(iStack[j] != iStack[i])
            return false;
    }
    return true;

}

int main()
{
    int x = 123;
//    scanf("%d\n", x);
    bool b = isPalindrome(x);
    printf("%d\n", b);
    return 0;
}
