//acwing 3188
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e7+10;
char str[N], tmp[N/2];
int ne[N];
int main()
{
    scanf("%s", tmp);
    str[0] = '$', str[1] = '#';
    int length1 = 2;
    for(int i=0;tmp[i];i++)
    {
        str[length1++] = tmp[i];
        str[length1++] = '#';
    }
    str[length1++] = '^';
    int mr = 0, ml = 0;
    for(int i=1;str[i]!='^';i++)
    {
        if(i < mr) ne[i] = min(ne[2*ml-i], mr - i);
        else ne[i] = 1;
        while(str[i+ne[i]]==str[i-ne[i]]) ne[i] ++;
        if(ne[i]+i > mr)
        {
            mr = ne[i] + i;
            ml = i;
        }
    }
    int res = 0;
    for(int i=1;i<=length1;i++)
    {
        res = max(res, ne[i]);
    }
    printf("%d", res-1);
    
    return 0;
}