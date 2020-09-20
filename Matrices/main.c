#include <stdio.h>
#include <stdlib.h>
/* //Diagonal Matrix
 * struct Matrix
 * {
 *     int A[10];
 *     int n;
 * };
 *
 * void Set(struct Matrix *m, int i, int j, int x)
 * {
 *     if(i == j)
 *         m->A[i-1] = x;
 * }
 *
 * int Get(struct Matrix m, int i, int j)
 * {
 *     if(i == j)
 *         return m.A[i-1];
 *     else
 *         return 0;
 * }
 *
 * void Display(struct Matrix m)
 * {
 *     int i,j;
 *     for(i = 0; i < m.n; i++)
 *     {
 *         for(j = 0; j < m.n; j++)
 *         {
 *             if( i == j)
 *                 printf("%d ", m.A[i]);
 *             else
 *                 printf("%d ", 0);
 *         }
 *         printf("\n");
 *     }
 * }
 *
 * int main()
 * {
 *     struct Matrix m;
 *     m.n = 4;
 *
 *     Set(&m,1,1,5);
 *     Set(&m,2,2,8);
 *     Set(&m,3,3,9);
 *     Set(&m,4,4,12);
 *     printf("%d \n", Get(m,2,2));
 *     Display(m);
 *     return 0;
 * }
 */
//Lower Triangular Matrix
struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i >= j)
        //Row major mapping
        //m->A[i*(i-1)/2+j-1] = x;
        //Column major mapping
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if(i >= j)
        //Row major mapping
        //return m.A[i*(i-1)/2+j-1];
        //Column major mapping
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i,j;
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            if( i >= j)
                //Row major mapping
                //printf("%d ", m.A[i*(i-1)/2+j-1]);
                //Column major mapping
                printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i,j,x;

    printf("Enter Dimension\n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n+1) / 2 * sizeof(int));

    printf("Enter all elements\n");
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }
    printf("\n\n");
    Display(m);
    return 0;
}
