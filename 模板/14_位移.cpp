/*
输入一个n，接下来n个数，输出每个数中二进制形式1的个数
int lowbit(int x){return x & -x}
n >> k & 1;
*/


#include <iostream>
using namespace std;
int lowbit(int x)
{
    return x & -x;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        int res = 0;
        while(x) x -= lowbit(x), res++;
        printf("%d ", res);
    }
    return 0;
}