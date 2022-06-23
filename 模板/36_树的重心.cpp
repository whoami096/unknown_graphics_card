#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10, M = N * 2;
int ans = N;
int h[N], e[N], ne[M], idx;
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
//以u为根的子树中点的数量
int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[j];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);//取最大子树
            sum += s;//加上所有子树
        }
    }
    res = max(res, n-sum);//节点上面的树
    ans = min(ans, res);
    return sum;
    


}

int main()
{
    int n;
    cin >> n;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < n; i++)
    {
        int a, b; 
        cin >> a >> b;
        add(a, b), add(b, a);//双向都可以搜
    }
    dfs(1);
    cout << ans << endl;
    
    return 0;
}
