/*
输入格式：
    第一行三个整数n，m，q
    接下来n行，每行m个整数，表示整数矩阵
    接下来q行，每行包含四个整数x1，y1，x2，y2
    表示子矩阵左上角和右下角坐标
输出格式：
    共q行，输出每个子矩阵的和
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    int a[n+1][m+1], s[n+1][m+1];
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    while(q--)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);

    }

    return 0;
}