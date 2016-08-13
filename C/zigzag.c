#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows)
{
    if((NULL == s) || (numRows < 1))
    {
        return NULL;
    }

    int i;
    int iZigsize;
    int index;
    int iSize = strlen(s);

    if (numRows < 2)
    {
        return s;
    }

    char *cRet = (char *)malloc(sizeof(char) * (iSize+1));
    cRet[iSize] = '\0';
    char *head = cRet;
    iZigsize = 2 * numRows - 2; //循环周期
    for(i = 0; i < numRows; i++)
    {
        for(index = i; index < iSize; index += iZigsize)
        {
            //第一列的数字
            *cRet++ = s[index];
            //中间行的第二个数字
            if((i > 0) && (i < numRows -1) &&
              ((index + iZigsize - 2*i) < iSize))
            {
                //同一行的两个数在s中的索引相差iZigsize - 2*i,i为行号
                *cRet++ = s[index + iZigsize - 2*i];
            }
        }
    }
    return head;

}

int main()
{
    char* s = "123456789";
    char* s1 = "PAYPALISHIRING";
    char* ret = convert(s, 3);
    char* ret1 = convert(s1, 3);
    printf("ret is:%s\n%s\n", ret, ret1);
    return 0;
}
