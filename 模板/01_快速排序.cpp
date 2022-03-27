#include <iostream>
using namespace std;
void quick_sort(int *a, int l, int r);
int main()
{
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i=0;i<m;i++) scanf("%d", &a[i]);
    quick_sort(a, 0, m-1);
    for(int i=0;i<m;i++) printf("%d ", a[i]);

    return 0;
}
//O(nlog(n))
void quick_sort(int *a, int l, int r)
{
    if(l>=r) return;
    int i = l - 1, j = r + 1, x = a[(l+r)>>1];
    while(i<j){
        do i++; while(a[i]<x);
        do j--; while(a[j]>x);
        if(i<j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j+1, r);
}