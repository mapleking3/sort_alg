/** 
 * @filename:   HeapSort.cpp
 * @brief:      堆排序 
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-17
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <stdio.h>
#include <stdlib.h>

//交换两个整数。注意一定要if判断是否两个相等，如果
//不相等才交换，如果相等也交换会出错的。a^a = 0
inline void Swap(int& a, int& b)
{
    if (a != b)
    {
        a^= b;
        b^= a;
        a^= b;
    }
}

//维持一个最大堆
int Heapify(int* npData, int nPos, int nLen)
{
    int nMax = -1;                        //暂存最大值
    int nChild = nPos * 2;                //他的左孩子位置

    while(nChild <= nLen)                //判断他是否有孩子
    {
        nMax = npData[nPos];            //是当前最大值为他

        if (nMax < npData[nChild])        //与左孩子比较
        {
            nMax = npData[nChild];        //如果比左孩子小，就时最大值为左孩子
        }

        //同理与右孩子比较，这里要注意，必须要保证有右孩子。
        if (nChild + 1 <= nLen && nMax < npData[nChild + 1])    
        {
            ++nChild;                    //赋值最大值的时候把孩子变为右孩子，方便最后的数据交换
            nMax = npData[nChild];

        }

        if (nMax != npData[nPos])        //判断是否该节点比孩子都打，如果不大
        {
            Swap(npData[nPos], npData[nChild]);    //与最大孩子交换数据
            nPos = nChild;                        //该节点位置变为交换孩子的位置
            nChild *= 2;                        //因为只有交换后才使不满足堆得性质。
        }
        else                            //都最大了，满足堆得性质了。退出循环
        {
            break;
        }
    }

    return 1;                        //维持结束。
}

//建立一个堆
int BuildHeap(int* npData, int nLen)
{
    //从nLen / 2最后一个有叶子的数据开始，逐一的插入堆，并维持堆得平衡。
    //因为堆是一个完全二叉树，所以nlen/2+1- nLen之间肯定都是叶子。
    //叶子还判断什么呢。只有一个数据，肯定满足堆得性质咯。
    for (int i = nLen / 2; i >= 1; --i)
    {
        Heapify(npData, i, nLen);
    }

    return 1;
}

//堆排序
int HeapSort(int* npData, int nLen)
{
    BuildHeap(npData, nLen);        //建立一个堆。

    while(nLen >= 1)                //逐一交和第一个元素交换数据到最后
    {                                //完成排序
        Swap(npData[nLen], npData[1]);
        --nLen;
        Heapify(npData, 1, nLen);//交换之后一定要维持一下堆得性质。
    }                            //不然小的成第一个元素,就不是堆了。

    return 1;
}

//main函数，
int main()
{
    int nData[11] = {0,9,8,7,6,5,4,3,2,1,0};    //测试数据，下标从1开始哦。
    HeapSort(nData, 10);                        //堆排序

    for (int i = 1; i <= 10; ++i)                //输出排序结果。
    {
        printf("%d ", nData[i]);
    }
    printf("\n");
    return 0;
}
