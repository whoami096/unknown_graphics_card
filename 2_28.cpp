#include <iostream>
using namespace std;
int main()
{
    int a[5];
    for(int i=0;i<5;i++) scanf("%1d", &a[i]);
    for(int i=0;i<4;i++) printf("%d   ", a[i]);
    printf("%d", a[4]);
    return 0;
}