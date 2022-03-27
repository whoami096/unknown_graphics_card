#include <iostream>
#define N 100009
using namespace std;
int a[N];
void select_sort(int a[], int k)
{
    for(int i=0;i<k-1;i++)
        for(int j=i+1;j<k;j++)
            if(a[i]>a[j]) swap(a[i], a[j]);//每次循环从后面找一个最小值排好
}
void bubble_sort(int a[], int k)
{
    while(k--)
    for(int i=0;i<k;i++)
        if(a[i]>a[i+1]) swap(a[i], a[i+1]);//每次循环排好一个最大值
    
}
void insert_sort(int a[], int k)
{
    for(int i=1;i<k;i++)
        for(int j=0;j<i;j++)
            if(a[j]>a[i]){//如果找到值比要插入的值大，则插到这个值前面，否则不用管
                int tmp = a[i];
                for(int p=i;p>j;p--) a[p] = a[p-1];
                a[j] = tmp;
                break;
            }
        
    
}
// O(n*n)
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    select_sort(a, n);

    for(int i=0;i<n;i++) printf("%d ", a[i]);
    return 0;
}