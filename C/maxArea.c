/**11. Container With Most Water
*
*/
#include <stdio.h>

#define MAX 100

int maxArea(int* height, int heightSize)
{
    int i = 0;
    int j = heightSize - 1;
    int iArea, iMax = 0;

    while(i != j)
    {
        if(height[i] > height[j])
        {
            iArea = height[j] * (j - i);
            j--;
        }
        else
        {
            iArea = height[i] * (j - i);
            i++;
        }
        if(iArea > iMax)
        {
            iMax = iArea;
        }
    }

    return iMax;
}

int main()
{
    int array[100] = {0};
    int i = 0, max_area;
    char c;
    while(1)
    {
        scanf("%d%c", &array[i], &c);
        i++;
        if(c == '\n')
            break;

    }
    max_area = maxArea(array, i);
    printf("%d\n", max_area);

    return 0;
}
