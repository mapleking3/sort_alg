/** 
 * @filename:   RadixSort.cpp
 * @brief:      基数排序 
 *              今天学了基数排序，据说他的时间复杂度也是O(n)，他的思路就是： 
 *              没有计数排序那么理想，我们的数据都比较集中，都比较大，一般是4，5位。基本没有小的数据。 
 *              那我们的处理很简单，你不是没有小的数据嘛。我给一个基数，例如个位，个位都是[0-10)范围
 *              内的。先对他进行归类，把小的放上面，大的放下面，然后个位排好了，在来看10位，我们也这
 *              样把小的放上面，大的放下面，依次内推，直到最高位排好。那么不就排好了吗？我们只需要做
 *              d(基数个数)的循环就可以了。时间复杂度相当于O(d * n) 因为d为常量，例如5位数，d就是5.所
 *              以近似为O(n)的时间复杂度。这次自己写个案例： 
 *              最初的数据排好个位的数据排好十位的数据排好百位的数据 
 *                  981981725129 
 *                  387753129387 
 *                  753955753456 
 *                  129725955725 
 *                  955456456753 
 *                  725387981955 
 *                  456129387981 
 *              这里只需循环3次就出结果了。 
 *              <!--[if !supportLists]-->3.       
 *              <!--[endif]-->
 *              但是注意，我们必须要把个位排好。但是个位怎么排呢？这个是个问题。书上说的是一叠一叠的怎么
 *              合并，我是没有理解的。希望知道的有高手教我一下。 
 *              我是用的一个计数排序来排各位的，然后排十位。效率应该也低不到哪里去。呵呵。。
 * @author:     Retton
 * @version:    V1.0.0
 * @date:       2013-09-17
 * Copyright:   2012-2038 Anhui CHAOYUAN Info Technology Co.Ltd
 */
#include <stdio.h>
#include <stdlib.h>

//计数排序，npRadix为对应的关键字序列，nMax是关键字的范围。npData是具体要
//排的数据，nLen是数据的范围，这里必须注意npIndex和npData对应的下标要一致
//也就是说npIndex[1] 所对应的值为npData[1]
int RadixCountSort(int* npIndex, int nMax, int* npData, int nLen)
{
    //这里就不用说了，计数的排序。不过这里为了是排序稳定
    //在标准的方法上做了小修改。

    int* pnCount  = (int*)malloc(sizeof(int)* nMax);        //保存计数的个数
    for (int i = 0; i < nMax; ++i)
    {
        pnCount[i] = 0;
    }
    for (int i = 0; i < nLen; ++i)    //初始化计数个数
    {
        ++pnCount[npIndex[i]];
    }

    for (int i = 1; i < 10; ++i)  //确定不大于该位置的个数。
    {
        pnCount[i] += pnCount[i - 1];
    }

    int * pnSort  = (int*)malloc(sizeof(int) * nLen);    //存放零时的排序结果。

    //注意：这里i是从nLen-1到0的顺序排序的，是为了使排序稳定。
    for (int i = nLen - 1; i >= 0; --i)
    {
        --pnCount[npIndex[i]];        
        pnSort[pnCount[npIndex[i]]] = npData[i];
    }

    for (int i = 0; i < nLen; ++i)        //把排序结构输入到返回的数据中。
    {
        npData[i] = pnSort[i];
    }
    free(pnSort);                        //记得释放资源。
    free(pnCount);
    return 1;
}

//基数排序
int RadixSort(int* nPData, int nLen)
{
    //申请存放基数的空间
    int* nDataRadix    = (int*)malloc(sizeof(int) * nLen);

    int nRadixBase = 1;    //初始化倍数基数为1
    bool nIsOk = false; //设置完成排序为false

    //循环，知道排序完成
    while (!nIsOk)
    {
        nIsOk = true;
        nRadixBase *= 10;
        for (int i = 0; i < nLen; ++i)
        {
            nDataRadix[i] = nPData[i] % nRadixBase;
            nDataRadix[i] /= nRadixBase / 10;
            if (nDataRadix[i] > 0)
            {
                nIsOk = false;
            }
        }
        if (nIsOk)        //如果所有的基数都为0，认为排序完成，就是已经判断到最高位了。
        {
            break;
        }
        RadixCountSort(nDataRadix, 10, nPData, nLen);
    }

    free(nDataRadix);

    return 1;
}

int main()
{
    //测试基数排序。
    int nData[10] = {123,5264,9513,854,9639,1985,159,3654,8521,8888};
    RadixSort(nData, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", nData[i]);
    }
    printf("\n");

    return 0;
}
