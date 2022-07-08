#include <iostream>
#include <cmath>
using namespace std;
const int N=1e9+10;

int cnt,primes[N/10];
bool st[N];

void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            for(int j=i+i;j<=n;j+=i)
                st[j]=true;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    get_prime(n);

    cout<<cnt<<endl;
    return 0;
}