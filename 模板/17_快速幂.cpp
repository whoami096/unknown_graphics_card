#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, p, ans = 1;
    cin >> a >> b >> p;
    while(b)
    {
        
        if(b&1)
            ans *= a;
        b >>= 1;
        a *= a;
        a %= p;
        ans %= p;
    }
    cout << ans % p;
    return 0;
}