#include <stdio.h>
#include <stdlib.h>
#include <cmath>

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
int FindMax(int A[], int n)
{
    int max = 0 - __INT32_MAX__;
    int i;
    for(i = 0; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}
void CountSort(int A[], int n)
{
    int i, j, max, *C;
    max = FindMax(A,n);
    C = (int *)malloc(sizeof(int)* (max+1));
    for(i = 0; i < max+1; i++)
        C[i] = 0;
    for(i = 0; i < n; i++)
        C[A[i]]++;  
    i = 0;
    j = 0;
    while(j < max+1)
    {
        if(C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }  
}
void ShellSort(int A[], int n)
{
    int gap, i, j, temp;
    for(gap = n/2; gap >=1; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while(j >= 0 && A[j] > temp)
            {
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }
}
struct Node
{
    int value;
    Node *next;
};
void Insert(Node ** ptrBins, int idx)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->value = idx;
    temp->next = nullptr;

    if(ptrBins[idx] == nullptr)
        ptrBins[idx] = temp;
    else
    {
        Node *p = ptrBins[idx];
        while(p->next != nullptr)
            p = p->next;
        p->next = temp;
    }   
}
int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    free(p);
    return x;
}
void BinSort(int A[], int n)
{
    int i;
    int max = FindMax(A, n);
    Node** bins = (Node **)malloc(sizeof(Node *)*(max+1));    
    for(i = 0; i < max+1; i++)
        bins[i] = nullptr;
    for(i = 0; i < n; i++)
        Insert(bins, A[i]);
    i = 0;
    int j = 0;
    while(i < max+1)
    {
        while(bins[i] != nullptr)
            A[j++] = Delete(bins, i);
        i++;
    }
    free(bins);
}
int CountDigits(int x)
{
    int count = 0;
    while(x != 0)
    {
        x = x/10;
        count ++;
    }
    return count;
}
int GetBinIndex(int x, int pass)
{
    return (int)(x / pow(10, pass)) % 10;
}
void Insert1(Node ** ptrBins, int value, int idx)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = nullptr;

    if(ptrBins[idx] == nullptr)
        ptrBins[idx] = temp;
    else
    {
        Node *p = ptrBins[idx];
        while(p->next != nullptr)
            p = p->next;
        p->next = temp;
    }   
}
void RadixSort(int A[], int n)
{
    int i;
    int max = FindMax(A, n);
    int nPass = CountDigits(max);
    //printf("pass: %d\n", nPass);
    Node **bins = (Node **)malloc(sizeof(Node *)*10);
    for(i = 0; i < 10; i++)
        bins[i] = nullptr;
    for(int pass = 0; pass < nPass; pass++)
    {
        for(i = 0; i < n; i++)
        {
            int binIdx = GetBinIndex(A[i], pass);
            Insert1(bins, A[i], binIdx);
        }
        i = 0;
        int j = 0;
        while(i < 10)
        {
            while(bins[i] != nullptr)
                A[j++] = Delete(bins, i);
            i++;
        }
        for(i = 0; i < 10; i++)
            bins[i] = nullptr;
    }
    free(bins);
}
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    // Uncomment to test each sorting technique
    //BubbleSort(A, n);
    //InsertionSort(A, n);
    //SelectionSort(A, n);
    //MergeSortIterative(A, n);
    //MergeSortRecursive(A, 0, n-1);
    //CountSort(A, n);
    //ShellSort(A, n);
    //BinSort(A, n);
    RadixSort(A, n);
    
    // int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, __INT32_MAX__};
    // int n = sizeof(A)/sizeof(A[0])-1;
    // QuickSort(A, 0, n);

    printf("Size of array: %d\n", n);
    printf("Sorted List: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}