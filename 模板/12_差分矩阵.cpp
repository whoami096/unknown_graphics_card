/*
题目大意：
    第一行n，m，q
    接下来n行m列矩阵
    接下来q行x1,y1, x2,y2, c
    表示对子矩阵每个数加c，输出操作后的矩阵
输入样例：
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
输出样例：
2 3 4 1
4 3 4 1
2 2 2 2
*/
#include <iostream>
using namespace std;
const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -= c;
    b[x2+1][y2+1] += c;
}
int main()
{
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), insert(i, j, i, j, a[i][j]);
    
    while(q--)
    {
        int x1, x2, y1, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) printf("%d ", b[i][j]);
        puts("\b");
    }
    return 0;
}