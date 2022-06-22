#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5+3, null = 0x3f3f3f3f;
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k ++;
        if(k == N) k = 0;
    }
    return k;
}

int main()
{
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof(h));
    while (n--)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        
        int k = find(x);
        if(s[0] == 'I') h[k] = x;
        else
        {
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}