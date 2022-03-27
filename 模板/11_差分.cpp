/*
题目大意：
    第一行n，m
    第二行n个整数
    接下来m行，每行三个正整数l，r，c
    表示对区间[l, r]每个数加c
    输出操作后的数列
输入样例：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出样例：
3 4 5 3 4 2
*/
#include <iostream>
using namespace std;
const int N = 100010;
int s[N], a[N];

void insert(int l, int r, int c)
{
    a[l] += c;
    a[r+1] -= c;

}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%d", &s[i]), insert(i, i, s[i]);

    while(m--)
    {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(l, r, c);
    }

    for(int i=1;i<=n;i++) a[i] += a[i-1];

    for(int i=1;i<=n;i++) printf("%d ", a[i]);
    return 0;
}