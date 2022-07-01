//O(mlogn)
//n, m = 1e5， 适合稀疏图
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5+10;
int n, m, h[N], e[N], ne[N], dist[N], w[N], idx;
bool st[N];
typedef pair<int, int> PII;
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        for (int i=h[ver];i!=-1;i=ne[i])
        {
            int j = e[i];
            if(dist[j] >  distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
        st[ver] = true;
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
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
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}