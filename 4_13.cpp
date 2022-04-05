#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    double total = 0, now = 0;
    while(1)
    {
        printf("Enter miles driven (-1 to quit): ");
        double a, b;
        cin >> a;
        if(a==-1) break;
        printf("Enter gallons used: ");
        cin >> b;
        printf("MPG this trip: %.6f\n", now = a/b);
        printf("Total MPG: %.6f\n", total += now);
    }
    return 0;
}