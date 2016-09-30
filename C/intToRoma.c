/**
* 12. Integer to Roman
* Given an integer, convert it to a roman numeral.
* Input is guaranteed to be within the range from 1 to 3999.
*
* ˼·��
*   ����������ʮ���١�ǧ�ϵ��������ַ�����ʾ��Ȼ�����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*************************************************************************
* intToRoman:
*   In:  val: value to convert.
*   Out: pointer to the Roman number string.
*   Cav: n/a
**************************************************************************/


char* intToRoman(int num)
{
    int iTemp;
    char *str, *strTemp;
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    if((num < 0) || (num > 3999))
    {
        return NULL;
    }
    str = malloc(sizeof(char) * 20);
    strTemp = str;
    while(num >= 1000)
    {
        *str++ = 'M';
        num -= 1000;
    }
    iTemp = num/100;
    strcpy(str, huns[iTemp]);
    str += strlen(huns[iTemp]);
    num %= 100;

    iTemp = num/10;
    strcpy(str, tens[iTemp]);
    str += strlen(tens[iTemp]);
    num %= 10;

    strcpy(str, ones[num]);
    str += strlen(ones[num]);

    *str = '\0';
    return strTemp;
}

int main()
{
    int i_input;
    char *out;

    scanf("%d", &i_input);
    out = intToRoman(i_input);
    printf("%s", out);

    return 0;
}

