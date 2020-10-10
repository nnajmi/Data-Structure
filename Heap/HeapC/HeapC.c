#include <stdio.h>

void Insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];

    while(i > 1 && temp > H[i/2])
    {
        H[i] = H[i/2];
        i = i / 2;
    }
    H[i] = temp;
}
int Delete(int H[], int n)
{
    int i, j, temp;
    int val = H[1];
    H[1] = H[n];
    H[n] = val; //Keep the deleted element at the end of Heap array
    i = 1;
    j = 2 * i; //left child of i

    while(j < n-1)
    {
        if(H[j + 1] > H[j])
            j = j + 1;
        if(H[i] < H[j])
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2 * i;
        }
        else
            break;
    } 
    return val;   
}
int main()
{
    int H[] = {0, 2, 5, 8, 9, 4, 10, 7}; //Zero is not part of the Heap
    int i;

    for(i = 2; i <= 7; i++)
    {
        Insert(H, i);
    }
    //printf("Deleted Value is %d\n", Delete(H, 7));
    //printf("Deleted Value is %d\n", Delete(H, 6));
    
    //Heap Sort
    for(i = 7; i > 1; i--)
    {
        Delete(H, i);
    }
    for(i = 0; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");
    return 0;
}