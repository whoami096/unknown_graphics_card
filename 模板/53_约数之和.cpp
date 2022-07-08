#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int main()
{
    unordered_map<int,int> pr;

    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0)
            {
                x/=i;
                pr[i]++;
            }
        }
        if(x>1) pr[x]++;
    }

    ll res=1;
    for(auto i: pr)
    {
        int p=i.first,a=i.second;
        ll t=1;
        while(a--) t=(t*p+1)%mod;
        res=res*t%mod;
    }

    cout<<res<<endl;
    return 0;
}
