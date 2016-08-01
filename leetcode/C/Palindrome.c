#include <string.h>



int findOdd(cha*s, int k)
{
    int i = k-1, j = k+1;
    while((i >= 0)&&(s[j] != '\0'))
    {
        if(s[i] != s[j])
            return 2*(j-k) - 1;
        i--;
        j++;
    }
    return 2*(j-k) - 1;
}

int findEven(cha*, int k)
{
    int i = k, j = k+1;
    while((i >= 0)&&(s[j] != '\0'))
    {
        if(s[i] != s[j])
            return 2 * (j - k);
        i--;
        j++;
    }
    return 2 * (j - k);
}

char* longestPalindrome(char* s)
{
    int Max = 0, tempLen = 0;
    int i;
    int len = strlen(s);
    char* str;
    char* temp = s;

    for(i = 0; i < len; i++)
    {
        tempLen = findOdd(s, i);
        Max = (Max > tempLen) ? Max : tempLen;
        tempLen = findEven(s, i);
        Max = (Max > tempLen) ? Max : tempLen;

        s[Max]


    }

    return str;
}

void main()
{
    char *s = "helloworld!";
    char *ret;
    ret = longestPalindrome(s);
    printf("%s\n", &s[2]);
}
