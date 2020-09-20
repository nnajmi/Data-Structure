#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    string s1 = "Hello";
    printf("%c \n", s1);
    cout << s1 << endl;

    char *name = "Najmeh";
    cout << name<<endl;
    printf("%s \n", name);
    char name2[6] = "Mahdi";
    cout << name2 << endl;
    printf("%s", name2);
    return 0;
}
