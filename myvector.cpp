#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class myvector
{
private:
    bool check(int tmp)
    {
        if(tmp < 32) return false;
        while(!(tmp&1)) tmp >>= 1;
        tmp >>= 1;
        if(tmp) return false;
        else return true; 
    }
public:
    T * a = new T[32];
    T & operator[](int k)
    {return *(a+k);}
    int cnt = 0;
    int size() {return cnt;}
    void push_back(T k)
    {
        if(this->check(cnt))
        {
            T *tmp = new T[(cnt)*2];
            memcpy(tmp, a, sizeof(T)*cnt);
            delete []a;
            a = tmp;
        }
        *(a + cnt ++) = k;
    }
    void pop_back() { cnt--; }

    int back() { return *(a+cnt-1); }

    void clear() { cnt = 0;}
    T *begin(){return a;}
    T *end(){return a+cnt;}
    void erase(T *tmp1, T *tmp2) { cnt = tmp1 - a; }
    
    void operator=(myvector<T> tmp)
    {
        this->size() = tmp.size();
        for (int i = 0; i < tmp.size(); i++)
        {
            *(a+i) = tmp[i];
        }
        
    }
};

int main()
{
    int n;

    cin >> n;
    myvector<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(n - i);
    }

    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    
    return 0;
}
