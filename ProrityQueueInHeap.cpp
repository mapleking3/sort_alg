/** 
 * @filename:   ProrityQueueInHeap.cpp
 * @brief:      用堆实现优先队列 
 *                  1.一个是他是一个数组（当然你也可以真的用链表来做。）。 
 *                  2.他可以看做一个完全二叉树。注意是完全二叉树。所以他的叶子个数刚好是nSize / 2个。 
 *                  3.我使用的下标从1开始，这样好算，如果节点的位置为i,他的父节点就是i/2,他的左孩子
 *                    结点就是i*2,右孩子结点就是i*2+1，如果下标从0开始，要复杂一点。 
 *                  4.他的父节点一定不比子节点小（我所指的是最大堆）。 
 *              由这些性质就可以看出堆得一些优点： 
 *                  1.可以一下找到最大值，就在第一个位置heap[1].  
 *                  2.维持堆只需要log(2,n)(n是数据个数)的复杂度，速度比较快。他只需要比较父与子之间的
 *                    大小关系，所以比较次数就是树的高度，而他是一个完全二叉树，所以比较次数就是log(2,n)。
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-17
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <stdio.h>
#include <stdlib.h>

//定义一个堆得结构体，
struct MyHeap 
{
    int* pnData;    //指向数据的指针
    int nSize;     //当前堆中的元素个数
};

//调整数据，维持堆得性质，这个和上次heapify的作用一样
//只是这个时从子道父节点这样的判断而已。
int IncreaseKey(MyHeap* pHeap, int nPos)
{
    //循环和他父节点判断，只要 nPos > 1他就有父节点 
    while(nPos > 1)        
    {
        int nMax = pHeap->pnData[nPos];
        int nParent = nPos / 2;

        //如果他比父节点大，交换数据，并使判断进入父节点
        //（因为只有父节点可能会影响堆得性质。他的数据改变了。）
        if (nMax > pHeap->pnData[nParent])
        {
            pHeap->pnData[nPos] = pHeap->pnData[nParent];
            pHeap->pnData[nParent] = nMax;
            nPos = nParent;
        }
        else        //否则堆没有被破坏，退出循环
        {
            break;
        }
    }

    return 1;
}

//插入数据，这里pnHeap为要插入的队，nLen为当前堆得大小。
//nData为要插入的数据，这里注意报保证堆得空间足够。
int Insert(MyHeap* pHeap, int nData)
{
    ++pHeap->nSize;            //添加数据到末尾
    pHeap->pnData[pHeap->nSize] = nData;
    IncreaseKey(pHeap, pHeap->nSize);
    return 1;
}

//弹出堆中对大元素，并使堆得个数减一
int PopMaxHeap(MyHeap* pHeap)
{
    int nMax = pHeap->pnData[1];  //得到最大元素

    //不要忘记维持堆得性质，因为最大元素已经弹出了，主要思路就是
    //同他最大孩子填充这里。

    int nPos = 1;            //起始位1，因为他弹出，所以是这里开始破坏堆得性质的
    int nChild = nPos * 2;    //他的左孩子的位置，

    //循环填充，用最大孩子填充父节点
    while(nChild <= pHeap->nSize)
    {
        int nTemp = pHeap->pnData[nChild];
        if (nChild + 1 <= pHeap->nSize &&
            nTemp < pHeap->pnData[nChild + 1])
        {
            ++nChild;
            nTemp = pHeap->pnData[nChild];
        }
        pHeap->pnData[nPos] = nTemp;
        nPos = nChild;
        nChild *= 2;
    }
    //最好一个用最末尾的填充。
    pHeap->pnData[nPos] = pHeap->pnData[pHeap->nSize];
    --pHeap->nSize;            //堆个数量减一
    return nMax;            //返回最大值。
}

//程序入口main
int main()
{
    MyHeap myHeap;            //定义一个堆
    myHeap.pnData = (int*)::malloc(sizeof(int) *11); //申请数据空间
    myHeap.nSize = 0;            //初始大小为0

    for (int i = 1; i <= 10; ++i)        //给优先队列堆里添加数据
    {
        Insert(&myHeap, i);
    }

    for (int i = 1; i <= 10; ++i)        //测试优先队列是否建立成功
    {
        printf("%d ", myHeap.pnData[i]);
    }
    printf("\n");

    while(myHeap.nSize > 0)  //逐一弹出队列的最大值。并验证
    {
        printf("%d ", PopMaxHeap(&myHeap));
    }
    printf("\n");

    ::free(myHeap.pnData);        //最后不要忘记释放申请的空间
    return 0;
}
