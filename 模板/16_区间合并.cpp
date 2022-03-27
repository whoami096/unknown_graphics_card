/*
输入格式：
    第一行一个n，接下来n行
    每行两个整数[l, r]
输出格式：
    一行，计算合并后的区间个数
输入样例：
5
1 2
2 4
5 6
7 8
7 9
输出样例：
3
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for(auto seg:segs)
        if(ed < seg.first)
        {
            if(st!=-2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    
    if(st!=-2e9) res.push_back({st, ed});
    
    segs = res;

}

int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;
    return 0;
}