/*
输入格式
第一行两个整数n， m
接下来n行，每行包含两个整数x和c
接下来m行，每行两个整数l，r
输出格式
m行，每行输出一个询问中所求区间内的数字和
输入样例
3 3
1 2
3 6
7 5
1 3
4 6
7 8
输出样例
8
0
5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 300010;
int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l<r)
    {
        int mid = l + r >> 1;
        if(alls[mid]>=x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        
        alls.push_back(l);
        alls.push_back(r);
    }
    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //处理插入
    for(auto item:add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    //预处理前缀和
    for(int i=1;i<=alls.size();i++) s[i] = s[i-1] + a[i];
    //处理询问
    for(auto item:query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l-1] << endl;
    }
    return 0;

}