/**
10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.
*/
#include <stdio.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {

    if ((p == NULL) || (s == NULL))
    {
        return false;
    }
    if (!*p) return !*s;
    if (*(p + 1) == '*')
    {
        while((*s == *p) || (*s && *p == '.'))
        {
            if (isMatch(s, p + 2))      //利用递归来查询是否匹配
                return true;
            s++;
        }
        return isMatch(s, p+2);
    }
    else if((*p == *s) || (*s && *p == '.'))
    {
        return isMatch(s + 1, p + 1);
    }

    return false;
}

int main(void)
{
    char str1[200];
    char str2[20];
    bool bIstrue;

    printf("Input the two string:\n");
    scanf("%s", str1);
    scanf("%s", str2);

    bIstrue = isMatch(str1, str2);
    if(bIstrue)
        printf("true!");
    else
        printf("false");

    return 0;
}
