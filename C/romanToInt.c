/**
13. Roman to Integer

    Total Accepted: 106977
    Total Submissions: 253812
    Difficulty: Easy

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question

*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getCharInt(char c)
{
//    int iRet;
    switch (c)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}

int romanToInt(char* s)
{
    int i, iTemp, iTemp2;
    int iRet = 0;
    if(NULL == s)
    {
        return 0;
    }

    for(i = 0; i < strlen(s); i++)
    {
        iTemp = getCharInt(s[i]);
        iTemp2 = getCharInt(s[i + 1]);
        if(iTemp < iTemp2)
        {
            iRet -= iTemp;
            iRet += iTemp2;
            i++;
        }
        else
        {
            iRet += iTemp;
        }
    }
    return iRet;
}

int main()
{
    char *str;
    int iRet;
    str = (char *)malloc(sizeof(char));
    scanf("%s", str);

    iRet = romanToInt(str);
    printf("%d", iRet);

    return 0;
}





