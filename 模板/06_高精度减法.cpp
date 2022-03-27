//正整数减正整数

#include <iostream>
#include <vector>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if(a.size()!=b.size()) return a.size() > b.size();
    else for(int i=a.size()-1;i>=0;i--)
            if(a[i]!=b[i]) return a[i] > b[i];
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
    vector<int> C;
    for(int i=0, t=0;i<a.size();i++)
    {
        t = a[i] - t;
        if(i<b.size()) t -= b[i];
        C.push_back((t+10)%10);
        if(t<0) t = 1;
        else t = 0;
    }
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    if(cmp(A, B))
    {
        auto C = sub(A, B);
        for(int i=C.size()-1;i>=0;i--) printf("%d", C[i]);
    }
    else
    {
        auto C = sub(B, A);
        cout << "-";
        for(int i=C.size()-1;i>=0;i--) printf("%d", C[i]);
    }
    return 0;
}
