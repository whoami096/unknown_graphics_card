/*
输入格式：
    第一行n，m
    第二行n个数，表示整数数列
    接下来m行，每行两个整数l，r
输出格式：
    对于每对l，r输出数列[l, r]的和
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n+1], s[n+1] = { 0 };
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", s[b]-s[a-1]);
    }
    return 0;
}