//直接插入排序的基本思想是：每次将一个待排序的记录，按其关键字大小插入
//到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止
//设数组a[0…n-1]
//1、初始时，a[0]自成1个有序区，无序区为a[1…n-1]. 令i=1
//2、将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间
//3、i++并重复第二步直到i==n-1，排序完成
void Swap(int &a, int &b)
{
    if (a != b)
    {
        a^=b;
        b^=a;
        a^=b;
    }
}

void InsertSort1(int a[], int n)
{
    int i, j, k;

    for (i = 1; i < n; ++i)
    {
        for (j = i - 1; j >= 0; --j)
        {
            if (a[j] < a[i]) 
            {
                break;
            }
        }

        if (j != i - 1)
        {
            int tmp = a[i];
            for (k = i - 1; k > j; --k)
            {
                a[k+1] = a[k];
            }
            a[k+1] = tmp;
        }
    }
}

void InsertSort2(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
        if (a[i] < a[i-1])
        {
            int tmp = a[i];
            for (j = i - 1; j >= 0 && a[j] > tmp; --j)
            {
                a[j+1] = a[j];
            }
            a[j+1] = tmp;
        }
    }
}

void InsertSort3(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
        for (j = i - 1; j >= 0 && a[j] > a[j+1]; --j)
        {
            Swap(a[j], a[j+1]);
        }
    }
}
