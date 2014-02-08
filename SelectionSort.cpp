/** 
 * @filename:   SelectionSort.cpp
 * @brief:      选择排序 
 *              今天学习了选择排序，选择排序和冒泡排序思路上有一点相似，都是先确定最小元素，
 *              再确定第二笑元素，最后确定最大元素。他的主要流程如下： 
 *              1.加入一个数组A = {5,3,6,2,4,7}，我们对他进行排序 
 *              2.确定最小的元素放在A[0]位置，我们怎么确定呢，首先默认最小元素为5,他的索引
 *                为0,然后用它跟3比较，比他打，则认为最小元素为3,他的索引为1，然后用3跟6比，
 *                发现比他小，最小元素还是3，然后跟2比，最小元素变成了2，索引为3，然后跟4比，
 *                跟7比。当比较结束之后，最小元素也尘埃落定了。就是2，索引为3，然后我们把他
 *                放在A[0]处。为了使A[0]原有数据部丢失，我们使A[0](要放的位置)与A[3]（最小数
 *                据的位置）交换。这样就不可以了吗？ 
 *              3.然后我们在来找第二小元素，放在A[1]，第三小元素，放在A[2]。。当寻找完毕，我
 *                们排序也就结束了。 
 *              4.不过，在找的时候要注意其实位置，不能在找A[2]的时候，还用A[2]的数据跟已经排
 *                好的A[0],A[1]比，一定要跟还没有确定位置的元素比。还有一个技巧就是我们不能
 *                每次都存元素值和索引，我们只存索引就可以了，通过索引就能找到元素了。呵呵。 
 *              5.他和冒泡的相似和区别，冒泡和他最大的区别是他发现比他小就交换，把小的放上面，
 *                而选择是选择到最小的在直接放在确定的位置。选择也是稳定的排序。
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-17
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <stdio.h>
#include <stdlib.h>

//选择排序, pnData要排序的数据， nLen数据的个数
int SelectSort(int* pnData, int nLen)
{
    for (int i = 0; i < nLen - 1; ++i)
    {
        int nIndex = i;

        //遍历剩余数据，选择出当前最小的数据
        for (int j = i + 1; j < nLen; ++j)
        {
            if (pnData[j] < pnData[nIndex])    
            {
                nIndex = j;
            }
        }

        //如果当前最小数据索引不是i，也就是说排在i位置的数据在nIndex处
        if (nIndex != i)        
        {
            //交换数据，确定i位置的数据。
            int nTemp = pnData[i];
            pnData[i] = pnData[nIndex];
            pnData[nIndex] = nTemp;
        }
    }

    return 1;
}

int main()
{
    int nData[10] = {4,10,9,8,7,6,5,4,3,2};    //创建10个数据，测试
    SelectSort(nData, 10);        //调用选择排序

    for (int i = 0; i < 10; ++i)        
    {
        printf("%d ", nData[i]);
    }

    printf("\n");
    return 0;
}

#if 0
int SelectSort(int* pnData, int nLen) 
{ 
    //i从[0,nLen-1)开始选择，确定第i个元素 
    for (int i = 0; i < nLen - 1; ++i) 
    { 
        //遍历剩余数据，选择出当前最小的数据 
        for (int j = i + 1; j < nLen; ++j) 
        { 
            if (pnData[j] < pnData[i]) 
            { 
                int nTemp = pnData[i]; 
                pnData[i] = pnData[j]; 
                pnData[j] = nTemp; 
            } 
        } 
    } 
    return 1; 
} 
#endif
