/*题目大意：输入第一行n，q，第二行n个升序整数，接下来q行，
每行一个整数k，对于每个k，输出它在数组中的起始下标和终止下标
如果数组中不存在该元素，输出“-1 -1”
数据范围
1 <= n <= 100000
1 <= q <= 10000
1 <= k <= 10000
输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1
*/
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int q[N];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &q[i]);

    while(m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if(q[mid]>=x) r = mid;
            else l = mid + 1;
        }
        if(q[l]!=x) cout << "-1 -1\n";
        else
        {
            cout << l << ' ';
            l = 0, r = n -1;
            while(l<r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid]<=x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}

/*
//区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while(l<r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
//区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while(l<r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
*/