#include <iostream>

using namespace std;

/* //Diagonal Matrix
 * class Diagonal
 * {
 * private:
 *     int n;
 *     int *A;
 * public:
 *     Diagonal()
 *     {
 *         n = 2;
 *         A = new int[2];
 *     }
 *     Diagonal(int n)
 *     {
 *         this->n = n;
 *         A = new int[n];
 *     }
 *     ~Diagonal()
 *     {
 *         delete []A;
 *     }
 *     void Set(int i, int j, int x);
 *     int Get(int i, int j);
 *     void Display();
 * };
 *
 * void Diagonal::Set(int i, int j, int x)
 * {
 *     if(i == j)
 *         A[i-1] = x;
 * }
 *
 * int Diagonal::Get(int i, int j)
 * {
 *     if(i == j)
 *         return A[i-1];
 *     else
 *         return 0;
 * }
 *
 * void Diagonal::Display()
 * {
 *     int i,j;
 *     for(i = 0; i < n; i++)
 *     {
 *        for(j = 0; j < n; j++)
 *             if(i == j)
 *                 cout<< A[i] << " ";
 *             else
 *                 cout << 0 << " ";
 *         cout << endl;
 *     }
 * }
 *
 * int main()
 * {
 *     Diagonal d(4);
 *     d.Set(1,1,5);
 *     d.Set(2,2,8);
 *     d.Set(3,3,9);
 *     d.Set(4,4,12);
 *
 *     d.Display();
 *     return 0;
 * }
 */

/* class LowerTri
 * {
 * private:
 *     int n;
 *     int *A;
 * public:
 *     LowerTri()
 *     {
 *         n = 2;
 *         A = new int[2*(2+1)/2];
 *     }
 *     LowerTri(int n)
 *     {
 *         this->n = n;
 *         A = new int[n*(n+1)/2];
 *     }
 *     ~LowerTri()
 *     {
 *         delete []A;
 *     }
 *     void Set(int i, int j, int x);
 *     int Get(int i, int j);
 *     void Display();
 *     int GetDimension() { return n;}
 * };
 *
 * void LowerTri::Set(int i, int j, int x)
 * {
 *     if(i >= j)
 *         //Row-major mapping
 *         //A[i*(i-1)/2+j-1] = x;
 *         //Column-major mapping
 *         A[n*(j-1)-(j-2)*(j-1)/2+i-j] = x;
 * }
 *
 * int LowerTri::Get(int i, int j)
 * {
 *     if(i >= j)
 *         //Row-major mapping
 *         //return A[i*(i-1)/2+j-1];
 *         //Column-major mapping
 *         return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
 *     else
 *         return 0;
 * }
 *
 * void LowerTri::Display()
 * {
 *     int i,j;
 *     for(i = 1; i <= n; i++)
 *     {
 *        for(j = 1; j <= n; j++)
 *             if(i >= j)
 *                 //Row-major mapping
 *                 //cout<< A[i*(i-1)/2+j-1] << " ";
 *                 //Column-major mapping
 *                 cout<< A[n*(j-1)-(j-2)*(j-1)/2+i-j] << " ";
 *             else
 *                 cout << 0 << " ";
 *         cout << endl;
 *     }
 * }
 *
 * int main()
 * {
 *     int d;
 *     cout << "Enter Dimensions\n";
 *     cin >> d;
 *
 *     LowerTri lm(d);
 *
 *     int x;
 *     cout << "Enter all elements\n";
 *     for(int i = 1; i <= d; i++)
 *     {
 *         for(int j = 1; j <= d; j++)
 *         {
 *             cin >> x;
 *             lm.Set(i,j,x);
 *         }
 *     }
 *     lm.Display();
 *     return 0;
 * }
 */

class UpperTri
{
private:
    int n;
    int *A;
public:
    UpperTri()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    UpperTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~UpperTri()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n;}
};

void UpperTri::Set(int i, int j, int x)
{
    if(j >= i)
        //Column-major mapping
        A[j*(j-1)/2+i-1] = x;
        //Row-major mapping
        //A[n*(i-1)-(i-2)*(i-1)/2+j-i] = x;
}

int UpperTri::Get(int i, int j)
{
    if(j >= i)
        //Column-major mapping
        return A[j*(j-1)/2+i-1];
        //Row-major mapping
        //return A[n*(i-1)-(i-2)*(i-1)/2+j-i];
    else
        return 0;
}

void UpperTri::Display()
{
    int i,j;
    for(i = 1; i <= n; i++)
    {
       for(j = 1; j <= n; j++)
            if(j >= i)
                //Column-major mapping
                cout<< A[j*(j-1)/2+i-1] << " ";
                //Row-major mapping
                //cout<< A[n*(i-1)-(i-2)*(i-1)/2+j-i] << " ";
            else
                cout << 0 << " ";
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions\n";
    cin >> d;

    UpperTri lm(d);

    int x;
    cout << "Enter all elements\n";
    for(int i = 1; i <= d; i++)
    {
        for(int j = 1; j <= d; j++)
        {
            cin >> x;
            lm.Set(i,j,x);
        }
    }
    lm.Display();
    return 0;
}
