//O(m)最坏O(nm)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5+10;
int n, m, h[N], e[N], ne[N], dist[N], w[N], idx;
int cnt[N];
bool st[N];
typedef pair<int, int> PII;
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

bool spfa()
{


    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        st[i] = true;
        q.push(i);
    }
    st[1] = true;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if(cnt[j]>=n) return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;

}
int main()
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c); 
    }
    if(spfa()) puts("Yes");
    else puts("No");
    return 0;
}