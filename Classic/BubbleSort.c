// 冒泡排序，以从小到大排序为例：
// 设数组长度为N
// 1、比较相邻的前后二个数据，如果前面数据大于后面数据，则交换之
// 2、这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个
//    数据就“沉”到数组第N-1个位置上
// 3、N=N-1，如果N不为0就重复前面二步，否则排序完成

void BubbleSort1(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 1; i < n - i; ++j)
        {
            if (a[j-1] > a[j])
            {
                Swap(a[j-1], a[j]);
            }
        }
    }
}

// 对BubbleSort1进行优化，设置一个标志，如果这一次发生了交换，则为
// true，否则为false，明显如果有一次没有发生交换，说明排序完成
void BubbleSort2(int a[], int n)
{
    int i, j;
    bool flag = true;
    j = n;

    while (flag)
    {
        flag = false;
        for (i = 1; i < j; ++i)
        {
            if (a[i-1] > a[i])
            {
                Swap(a[i-1], a[i]);
                flag = true;
            }
        }
        --j;
    }
}

// 进一步优化，如果有100个数据，仅前面10个无序，后面90个都已经排好序且
// 都大于前面10个数字，那么在第一次遍历后，最后发生交换的位置必定小于10，
// 且这个位置之后的数据必定已经有序了，记录下这个位置，第二次只要从数组
// 头部便利到这个位置就可以了
void BubbleSort3(int a[], int n)
{
    int i, j, flag;

    flag = n;

    while (flag > 0)
    {
        j = flag;
        flag = 0;
        for (i = 1; i < j; ++i)
        {
            if (a[i-1] > a[i])
            {
                Swap(a[i-1], a[i]);
                flag = i;
            }
        }
    }
}
