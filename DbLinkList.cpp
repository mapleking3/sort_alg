/** 
 * @filename:   DbLinkList.cpp
 * @brief:      双向链表主要思路为: 
 *                  1. 访问数据的方式不是数组的下标，而是他的节点的指针来访问 
 *                  2. 链表是用指针的指向来访问管理数据的，一个我们把数据存在一个节点里，
 *                     一个节点包括：nData，节点的数据域，nNext，他指向的下一个指针，nPre
 *                     他的上一个指针。如果他没有下一个指针或上一个指针，我们指向空nil.  
 *                  3. 一般一个链表有一个头节点。以他开始访问整个链表区域的数据。
 *                  链表主要的操作包括： 插入，删除，查找，清空，等主要操作
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-17
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <stdio.h>
#include <stdlib.h>

//定义链表的结构体。
struct MyList
{
    int nData;
    MyList* pPre;
    MyList* pNext;
};

//全局的变量，保存链表的头
MyList* g_pHead = NULL;

//判断链表是否为空
bool IsEmpty()
{
    //如果头指针指向的是空，链表为空
    return g_pHead == NULL;
}

//清空链表
int Clear()
{
    //删除所有数据，并把头指针指向为空
    MyList* pTemp = g_pHead;

    //遍历链表的数据。如果有数据，删除，然后进入下一个数据
    while(g_pHead)
    {
        g_pHead = g_pHead->pNext;
        delete pTemp;
        pTemp = g_pHead;
    }

    return 1;
}

//插入数据到链表中
int Insert(int nData)
{
    //这里是插入到头的位置，类似栈的操作。
    MyList* pTemp = new MyList();    //申请一个新的空间存放数据。
    pTemp->nData = nData;
    pTemp->pPre = NULL;            //他的上一个没有
    pTemp->pNext = g_pHead;        //他的next指向头节点，他作为头节点的上一个成为新头节点
    if (g_pHead)
    {
        g_pHead->pPre = pTemp;    //如果头节点有数据，则把头节点的上一个指向该节点。
    }
    g_pHead = pTemp;            //是头节点指针指向他，他成为新的头节点

    return 1;
}

//查找数据
bool Find(int nData)
{
    MyList* pTemp = g_pHead;        //从头节点开始寻找。
    //遍历数据
    while(pTemp)
    {
        if (pTemp->nData == nData)    //如果找到该数据，
        {
            return true;            //返回真。
        }

        pTemp = pTemp->pNext;        //没有找到，进入下一个节点
    }

    return false;            //遍历之后没有找到，则没有该数据，返回false
}

//删除数据。
bool Delete(int nData)
{
    //先找到数据，然后再删除。
    MyList* pTemp = g_pHead;    //要删除的节点指针。    

    //遍历链表找到要删除的节点
    while (pTemp)        
    {
        if (pTemp->nData == nData)    //找到了，删除它
        {
            if (pTemp->pPre)    //如果他有前一个节点，则前一个节点的next指向他的下一个节点
            {                    //这样就不会吊链了。
                pTemp->pPre->pNext = pTemp->pNext;
            }
            else        //没有上一个节点，则他就是头节点。
            {
                g_pHead = pTemp->pNext;    //头节点指针指向他，他就可以安息了。
            }

            if (pTemp->pNext)    //处理他的下一个节点情况，和上节点类似
            {
                pTemp->pNext->pPre = pTemp->pPre;
            }

            delete pTemp;    //删除它的数据空间
            return true;    //返回true,删除成功
        }
    }

    return false;    //没有找到数据，删除失败，返回false
}

int main()
{
    //测试，
    for (int i = 0; i < 10; ++i)
    {
        Insert(i);    //插入数据
    }

    if (Find(5)) //查找数据
    {
        printf("Yes!\n");
    }
    if (!Find(11))
    {
        printf("No!\n");
    }

    while(!IsEmpty())    //逐一删除数据
    {
        printf("%d ", g_pHead->nData);
        Delete(g_pHead->nData);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i)
    {
        Insert(i);
    }

    Clear();        //清空数据。
    if (IsEmpty())
    {
        printf("Empty!\n");
    }
    return 0;
}
