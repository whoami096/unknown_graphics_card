#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if(a==b) cout << "These numbers are equal.\n";
    else cout << (a > b ? a : b) << " is large.\n";
    return 0;
}