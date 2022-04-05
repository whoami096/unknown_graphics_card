#include <iostream>
using namespace std;
int main()
{
    cout << "Input three different integers: ";
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Sum is " << a + b + c << endl;
    cout << "Average is " << (a+b+c)/3.0 << endl;
    cout << "Smallest is " << (a < (b<c?b:c) ? a : (b<c?b:c)) << endl;
    cout << "Largest is " << (a > (b>c?b:c) ? a : (b>c?b:c)) << endl;

    return 0;
}