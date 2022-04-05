#include <iostream>
using namespace std;
int main()
{
    printf("integer\tsquare\tcube\n");
    for(int i=0;i<11;i++)
    printf("%d\t%d\t%d\n", i, i*i, i*i*i);
    return 0;
}