#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Comparison-based sorting algorithms
//O(n^2)
//Bubble sort is stable and with the help of flag can become adaptive.
void BubbleSort(int A[], int n)
{
    int i,j;
    int flag; //With help of flag, the bubble sort gets adaptive
    for(i = 0; i < n-1; i++)
    {
        flag = 0;
        for(j = 0; j < n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}
//Insertion sort is stable and adaptive.
void InsertionSort(int A[], int n)
{
    int i, j, x;
    for(i = 1; i < n; i++)
    {
        x = A[i];
        j = i - 1;
        while(j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
//Selection sort is not stable nor adaptive.
void SelectionSort(int A[], int n)
{
    int i, j, k;
    for(i = 0; i < n-1; i++)
    {
        for(j = k = i; j < n; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        Swap(&A[i], &A[k]);
    }
}
//Quick Sort  o(nlog n)
int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do{i++;} while(A[i] <= pivot);
        do{j--;} while(A[j] > pivot);

        if(i < j)
            Swap(&A[i], &A[j]);
    } while (i < j);
    Swap(&A[l], &A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if(l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l ,j);
        QuickSort(A, j + 1, h);
    }
}
//Merge sort is stable but not adaptive o(nlog n)
//Merge sort is the only sort that needs extra space that is n for extra array and log n for stack
void Merge(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100] = {0};

    while(i <= mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i <= mid; i++)
        B[k++] = A[i];
    for(; j <= h; j++)
        B[k++] = A[j];

    for(i = l; i <= h; i++)
        A[i] = B[i];
}
void MergeSortIterative(int A[], int n)
{
    int i, p, l, h, mid;
    for(p = 2; p <= n; p = p *2)
    {
        for(i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h)/2; //because they are integer, we get the floor value
            Merge(A, l, mid, h);
        }
    }
    if(p/2 < n)
        Merge(A, 0, p/2 - 1, n-1);
}
void MergeSortRecursive(int A[], int l, int h)
{
    int mid;
    if(l < h)
    {
        mid = (l + h)/2;
        MergeSortRecursive(A, l, mid);
        MergeSortRecursive(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    //BubbleSort(A, 10);
    //InsertionSort(A, 10);
    //SelectionSort(A, 10);
    //MergeSortIterative(A, 10);
    MergeSortRecursive(A, 0, 9);
    
    // int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, __INT32_MAX__};
    // int n = 11;

    // QuickSort(A, 0, 10);

    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}