/*
5. Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.
*/

#include <string.h>
#include <stdio.h>

int findOdd(char* s, int k)
{
    int i = k-1, j = k+1;
    while((i >= 0)&&(s[j] != '\0'))
    {
        if(s[i] != s[j])
            return j - 1;
        i--;
        j++;
    }
    return j - 1;
}

int findEven(char* s, int k)
{
    int i = k, j = k+1;
    while((i >= 0)&&(s[j] != '\0'))
    {
        if(s[i] != s[j])
            return j - 1;
        i--;
        j++;
    }
    return j - 1;
}

char* longestPalindrome(char* s)
{
    int i;
    int index, Max = 1, Start = 0, End = 0;
//    char* str = s;

    if (s == NULL)
    {
        return NULL;
    }
/*��Ȼ����Ϊ������ż�������ǿ���ͨ��ȷ��������ַ�������λ��ĩλ�Ӷ����Խ������ַ�����ȡ����*/
    for(i = 0; s[i]; i++)
    {
        index = findOdd(s, i);
        if(Max < (2 * (index - i) + 1))
        {
            Max = 2 * (index - i) + 1;
            Start = 2 * i - index;
            End = index;
        }
        index = findEven(s, i);
        if(Max < (2 * (index - i)))
        {
            Max = 2 * (index - i);
            Start = 2 * i - index + 1;
            End = index;
        }

    }
    s[End + 1] = 0;
    return s + Start;
}

int main()
{
    char s[] = "helloworld!";   //char *s�Ƕ���sΪ������,���Բ���ָ�������char s[]��s������ջ��
    char *ret;
    ret = longestPalindrome(s);
    printf("%s\n", ret);
    return 0;
}
