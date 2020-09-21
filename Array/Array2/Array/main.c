#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Array
{
	int A[20];
	int length;
	int size;
};

//struct Array
//{
//	int *A;
//	int length;
//	int size;
//};
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Display(struct Array arr)
{
	int i;
	for(i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
	printf("\n");
}

void Append(struct Array *arr, int x)
{
	if(arr->length < arr->size)
		arr->A[arr->length] = x;
	arr->length++;
}

void Insert(struct Array *arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for(i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i-1];
		arr->A[i] = x;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index)
{
	int i;
	int x = arr->A[index];
	if(index >= 0 && index < arr->length)
	{
		int i;
		for(i = index; i < arr->length; i++)
			arr->A[i] = arr->A[i+1];
		arr->length--;
		return x;
	}
	return 0;
}

int LinearSearch(struct Array arr, int key)
{
	int i;
	for(i = 0; i < arr.length; i++)
		if(arr.A[i] == key)
			return i;
	return -1;
}

int LinearSearchWithTransposition(struct Array *arr, int key)
{
	int i;
	for(i = 0; i < arr->length; i++)
		if(arr->A[i] == key)
        {
            Swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
	return -1;
}

int LinearSearchWithMoveToHead(struct Array *arr, int key)
{
	int i;
	for(i = 0; i < arr->length; i++)
		if(arr->A[i] == key)
        {
            Swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
	return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int mid;
	int low = 0;
	int high = arr.length - 1;
	while(low <= high)
    {
        mid = (low + high) / 2;
        if(key < arr.A[mid])
            high = mid - 1;
        else if(key > arr.A[mid])
            low = mid + 1;
        else if (key == arr.A[mid])
            return mid;
    }
	return -1;
}

int BinarySearchRecursive(struct Array arr, int key, int low, int high)
{
    int mid;
	if(low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            return BinarySearchRecursive(arr, key, low, mid - 1);
        else if(key > arr.A[mid])
            return BinarySearchRecursive(arr, key, mid + 1, high);
    }
	return -1;
}

int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Min(struct Array arr)
{
    int i;
    int min = arr.A[0];
    for(i = 1; i < arr.length; i++)
        if(arr.A[i] < min)
            min = arr.A[i];
    return min;
}

int Max(struct Array arr)
{
    int i;
    int max = arr.A[0];
    for(i = 1; i < arr.length; i++)
        if(arr.A[i] > max)
            max = arr.A[i];
    return max;
}

int Sum(struct Array arr)
{
    int i;
    int sum = 0;
    for(i = 0; i < arr.length; i++)
        sum += arr.A[i];
    return sum;
}

float Average(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
    int i, j;
    for(i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void Reverse2(struct Array *arr)
{
    int i, j;
    int temp[arr->size];
    for(i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        temp[i] = arr->A[j];
    }
    for(i = 0; i < arr->length; i++)
        arr->A[i] = temp[i];
}

int isSorted(struct Array arr)
{
    int i;
    for(i = 0; i < arr.length - 1; i++)
    {
        if(arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

struct Array* Merge(struct Array arr1, struct Array arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = 10;
    int i, j, k;
    i = j = k = 0;

    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for(; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    for(; j < arr2.length; j++)
        arr3->A[k] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

struct Array* Union(struct Array arr1, struct Array arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = 10;
    int i, j, k;
    i = j = k = 0;

    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if (arr1.A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = arr2.A[j++];
            i++;
        }
    }
    for(; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    for(; j < arr2.length; j++)
        arr3->A[k] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

struct Array* Intersection(struct Array arr1, struct Array arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = 10;
    int i, j, k;
    i = j = k = 0;

    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.A[i] < arr2.A[j])
            i++;
        else if (arr1.A[i] > arr2.A[j])
            j++;
        else
        {
            arr3->A[k++] = arr2.A[j++];
            i++;
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array* SetDifference(struct Array arr1, struct Array arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->size = 10;
    int i, j, k;
    i = j = k = 0;

    while(i < arr1.length && j < arr2.length)
    {
        if(arr1.A[i] == arr2.A[j])
        {
            j++;
            i++;
        }
        else if (arr1.A[i] < arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
        }
        else
        {
            j++;
        }
    }
    for(; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    arr3->length = k;
    return arr3;
}

//The array is sorted, only one element is missing, the list starts from 1 and filled with natural numbers, the last number is known.
int FindOneMissing(struct Array arr)
{
    int i, sum = 0;
    for(i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return ((arr.length + 1) * (arr.length + 2)/2) - sum;
}

//The array is sorted, only one element is missing, the first and last numbers are known.
int FindOneMissing2(struct Array arr)
{
    int i, diff;
    diff = arr.A[0];
    for(i = 0; i < arr.length; i++)
        if(arr.A[i] - i != diff)
            return diff + i;
    return -1;
}

//The array is sorted, more than one element is missing, the first and last numbers are known.
void FindMultiMissing1(struct Array arr)
{
    int i, diff;
    diff = arr.A[0];
    for(i = 0; i < arr.length; i++)
        if(arr.A[i] - i != diff)
            while(diff < arr.A[i] - i)
            {
                printf("%d ", diff + i);
                diff++;
            }
}

//The array is not sorted, more than one element is missing, the first and last numbers are known.
//Using Hash Table
void FindMultiMissing2(struct Array arr, int low, int high)
{
    int i;
    int H[high+1];
    for(i = 0; i <= high; i++)
        H[i] = 0;
    for(i = 0; i < arr.length; i++)
        H[arr.A[i]]++;
    for(i = low; i <= high; i++)
        if(H[i] == 0)
            printf("%d ", i);
}

//Finding Duplicates in a sorted array, size of array is known
void FindSortedDuplicates(struct Array arr)
{
    int i;
    int lastDuplicate = -1;
    for(i = 0; i < arr.length; i++)
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != lastDuplicate)
        {
            printf("%d ", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
}

//Counting Duplicates in a sorted array, size of array is known
void CountSortedDuplicates(struct Array arr)
{
    int i,j;
    for(i = 0; i < arr.length; i++)
        if(arr.A[i] == arr.A[i+1])
        {
            j = i + 1;
            while(arr.A[j] == arr.A[i]) j++;
            printf("%d is appearing %d times\n", arr.A[i], j - i);
            i = j - 1;
        }
}

//Counting Duplicates in a sorted array, size of array is known
//Using Hash Table
void CountSortedDuplicates2(struct Array arr)
{
    int i;
    int hashSize = arr.A[arr.length-1]+1;
    int H[hashSize];
    for(i = 0; i < hashSize; i++)
        H[i] = 0;
    for(i = 0; i < arr.length; i++)
        H[arr.A[i]]++;
    for(i = 0; i < hashSize; i++)
        if(H[i] > 1)
            printf("%d is appearing %d times.\n", i, H[i]);
}
//Counting Duplicate elements in an unsorted array O(n^2)
void CountUnsortedDuplicates(struct Array arr)
{
    int i, j, count;
    for(i = 0; i < arr.length - 1; i++)
        if(arr.A[i] != -1)
        {
            count = 1;
            for(j = i + 1; j < arr.length; j++)
                if(arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            if(count > 1)
                printf("%d is appearing %d times.\n", arr.A[i], count);
        }
}

//Counting Duplicate elements in an unsorted array O(n^2) using hash table
void CountUnsortedDuplicates2(struct Array arr, int max)
{
    int i;
    int H[max+1];
    for(i = 0; i <= max; i++)
        H[i] = 0;
    for(i = 0; i < arr.length; i++)
        H[arr.A[i]]++;
    for(i = 0; i <= max; i++)
        if(H[i] > 1)
            printf("%d is appearing %d times.\n", i, H[i]);
}

//Find pairs of numbers with a given sum, no duplicates in the array and the array is unsorted O(n^2)
void FindAPair(struct Array arr, int sum)
{
    int i,j;
    for(i = 0; i < arr.length; i++)
        for(j = i + 1; j < arr.length; j++)
            if(arr.A[i] + arr.A[j] == sum)
                printf("%d %d \n", arr.A[i], arr.A[j]);
}

//Find pairs of numbers with a given sum, no duplicates in the array and the array is unsorted O(n)
//Using hash table
void FindAPair2(struct Array arr, int sum, int max)
{
    int i;
    int H[max+1];
    for(i = 0; i <= max; i++)
        H[i] = 0;
    for(i = 0; i < arr.length; i++)
    {
        if(H[sum - arr.A[i]] != 0 && sum - arr.A[i] > 0)
            printf("%d %d \n", arr.A[i], sum - arr.A[i]);
        H[arr.A[i]]++;
    }
}

//Find pairs of numbers with a given sum, no duplicates in the array and the array is sorted O(n)
void FindAPair3(struct Array arr, int sum)
{
    int i = 0;
    int j = arr.length - 1;
    while( i < j)
    {
        if(arr.A[i] + arr.A[j] == sum)
        {
            printf("%d %d\n", arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] > sum)
            j--;
        else i++;
    }
}

//Min and Max in an array
void MinMax(struct Array arr)
{
    int min = arr.A[0];
    int max = arr.A[0];
    int i;
    for( i = 1; i < arr.length; i++)
        if(arr.A[i] < min)
            min = arr.A[i];
        else if (arr.A[i] > max)
            max = arr.A[i];
    printf("Min = %d Max = %d", min, max);
}
int main(int argc, char *argv[])
{
	struct Array arr1 = {{3,6,8, 12,20}, 5, 20};
    struct Array arr2 = {{1,2,3,4,5,6,8,9,-10,12,3},11,20};

    MinMax(arr2);


	printf("\n");
	return 0;
}
