#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if((nums1 == NULL)||(nums2 == NULL))
    {
        return 0;
    }
    int sum = nums1Size + nums2Size;
    int num[nums1Size + nums2Size + 1];
    int i = 0;
    int j = 0;
    int k = 0;
    double ret = 0;

    while((i < nums1Size) && (j < nums2Size))
    {
        if(nums1[i] < nums2[j])
            num[k++] = nums1[i++];
        else
            num[k++] = nums2[j++];
    }
    while((i == nums1Size) && (j < nums2Size))
    {
        num[k++] = nums2[j++];
    }
    while((i < nums1Size) && (j == nums2Size))
    {
        num[k++] = nums1[i++];
    }
    if((sum % 2) == 0)
    {
        ret = ((double)(num[sum/2] + num[sum/2 - 1]))/2;
    }
    else
    {
        ret = num[(sum - 1)/2];
    }

    return ret;
}
/*
void main()
{
 //   int a[] = {1, 4, 6, 10, 30};
 //   int b[] = {2, 5, 9, 13};
//    int a[] = {1, 3};
//    int b[] = {2};
    int c[] = {2};
    int d[] = {};
    double ret;

    ret = findMedianSortedArrays(c, 1, d, 0);
    printf("ret:%lf\n", ret);
}
*/

