﻿/** 
 * @filename:   insertSort.cpp
 * @brief:      插入排序主要思想是：把要排序的数字插入到已经排好的数据中。例如12356是已经排好
 *              的序，我们将4插入到他们中，时插入之后也是排好序的。这里显而易见是插入到3的后面,
 *              变为123456. 实现思路：插入排序就是先是一个有序的数据，然后把要插入的数据插到指
 *              定的位置，而排序首先给的就是无序的，我们怎么确定先得到一个有序的数据呢？答案就
 *              是：如果只有一个，当然是有序的咯。我们先拿一个出来，他是有序的，然后把数据一个
 *              一个插入到其中，那么插入之后是有序的，所以直到最后都是 有序的。。哈哈。结果就出
 *              来了！当然在写的时候还是有一个技巧的，不需要开额外的数组，下标从第二个元素开始
 *              遍历知道最后一个，然 后插入到前面已经有序的数据中。这样就不会浪费空间了。插入排
 *              序用处还是很多的，特别是链表中，因 为链表是指针存放的，没有数组那么好准确的用下
 *              标表示，插入是简单有效的方法。
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-16
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <stdio.h>
#include <stdlib.h>

//插入排序从下到大，nData为要排序的数据,nNum为数据的个数,该排序是稳定的排序
bool InsertionSort(int nData[], int nNum)
{
    for (int i = 1; i < nNum; ++i)        //遍历数组，进行插入排序
    {
        int nTemp = nData[i];
        for (int j = 0; j < i; ++j)        //对该数，寻找他要插入的位置
        {
            if (nData[j] > nTemp)    //找到位置，然后插入该位置，之后的数据后移
            {
                for (int k = i; k > j; --k)    //数据后移
                {
                    nData[k] = nData[k -1];
                }
                nData[j] = nTemp;        //将数据插入到指定位置
                break;
            }
        }
    }

    return true;
}

int main()
{
    int nData[10] = {4,10,9,8,7,6,5,4,3,2};    //创建10个数据，测试
    InsertionSort(nData, 10);        //调用插入排序

    for (int i = 0; i < 10; ++i)        
    {
        printf("%d ", nData[i]);
    }

    printf("\n");
    return 0;
}
