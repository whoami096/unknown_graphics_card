/*
题目大意：给定长为n的整数序列，找出最长的不包含重复数字的连续子序列
    输出它的长度
数据范围：
    1 <= n <= 100000
输入样例：
    5
    1 2 2 3 5
输出样例：
    3
*/
/*模板
for(int i=0, j=0;i<n;i++)
{
    while(j<i && check(i, j)) j++;

    //code
}
*/
#include <iostream>
#include <cstring>
const int N = 100010;
using namespace std;
int a[N], s[N];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i=0, j=0;i<n;i++)
    {
        s[a[i]] ++;
        while(s[a[i]]>1)
        {
            s[a[j]] --;
            j ++;
        }
        ans = max(ans, i-j+1);
    }
    cout << ans;
    return 0;
}