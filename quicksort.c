#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) do { (a)=(a)+(b);(b)=(a)-(b);(a)=(a)-(b);} while (0)

void printa(int a[], int len)
{
    int i;
    for (i = 0; i < len; ++i) {
        printf("%-6d ", a[i]);
    }
    printf("\n");
}


void quicksort(int a[], int l, int r)
{
    int i, j;
    int key = a[l];
    i = l;
    j = r;
    if (l > r)
        return;
    while (i != j) {
        while (a[j] >= key && j > i)
            --j;
        if (j > i)
            a[i++] = a[j];
        while (a[i] <= key && j > i)
            ++i;
        if (j > i)
            a[j--] = a[i];
    }
    a[i] = key;
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

void quicksort_m(int a[], int l, int r)
{
    int i, j;
    int key;

    if (l >= r)  {
        return;
    }

    i = l;
    j = r+1;
    key = a[l];

    for (;;)  {
        while(++i <= r && a[i] < key) {
            ;
        }
        while(a[--j] > key) {
            ;
        }
        if (i > j) {
            break;
        }
        SWAP(a[i], a[j]);
    }
    SWAP(a[l], a[j]);

    quicksort_m(a, l, j-1);
    quicksort_m(a, j+1, r);
}

void quicksort2(int *a, int n)
{
    struct sbe {
        int l;
        int r;
    };

    struct sbe *arr = (struct sbe *)calloc(n, sizeof(struct sbe));

    int  m;
    int p;
    int l, r, i, j;

    m = 0;
    arr[0].l = 0;
    arr[0].r = n-1;

    for ( ; ; ) {
        if ( m < 0 )
            break;
        l = arr[m].l;
        r = arr[m--].r;

        if ( l >= r )
            continue;

        // partition
        p = a[l];
        i = l;
        j = r+1;
        for ( ; ; ) {
            while( ++i <= r && a[i] < p );  // ! while( a[++i] < p ); error
            while( a[--j] > p );
            if ( i > j )
                break;
            SWAP( a[i], a[j] );
        }
        SWAP( a[j], a[l] );

        arr[++m].l = l;
        arr[m].r   = j-1;
        arr[++m].l = j+1;
        arr[m].r   = r;
    }

    free(arr);
}

int main(void)
{
    int array[] = {3,1234,13521,4654,12445,14565,1575,354,35465,12475,7798,6876};

    printa(array, sizeof(array)/sizeof(array[0]));

    quicksort2(array, sizeof(array)/sizeof(array[0]));

    printa(array, sizeof(array)/sizeof(array[0]));

    return 0;
}

