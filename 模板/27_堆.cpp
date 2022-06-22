#include <iostream>
using namespace std;
const int N = 1e5+10;

int heap[N], ed;
void down(int u)
{
    int t = u;
    if(u*2<=ed&&heap[u*2]<heap[t]) t = u * 2;
    if(u*2+1<=ed&&heap[u*2+1]<heap[t]) t = u * 2 + 1;
    if(t!=u)
    {
        swap(heap[t], heap[u]);
        down(t);
    }
}

void up(int u)
{
    while (u/2&&heap[u/2]>heap[u])
    {
        swap(heap[u/2], heap[u]);
        u /= 2;
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> heap[i];
    ed = n;
    for(int i=n/2;i;i--) down(i);
    while(m--)
    {
        cout << heap[1] << ' ';
        heap[1] = heap[ed--];
        down(1);
    }
    return 0;
}