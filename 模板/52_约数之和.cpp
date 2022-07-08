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
        res=res*(i.second+1)%mod;
    }

    cout<<res<<endl;
    return 0;
}