#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
/*
所有容器都有:
a.size(), 返回元素个数，O(1);
a.empty(), 判断是否为空，O(1)，是就true否则返回false;

pair<int, string> p;//pair<int, pair<int, int>> p;
p.first, p.second
赋值
p = make_pair(10, "yxc");
p = {20, "abc"};
支持比较运算，first第一个关键字
second第二个关键字，按字典序比较


vector:
    clear(),清空
    front(),返回第一个数
    back(),返回最后一个数
    push_back(),向队尾插入一个数
    pop_back(),删除最后一个数
    begin(), end()迭代器
    支持比较运算，按字典序比较
    三种遍历方式
    for(int i=0;i<a.size();i++) cout << a[i];
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) cout << *i;
    for(auto i:a) cout << i;

string:
    clear(), 清空
    size()/length()
    a.substr(1, 2),返回从下标为1的长为2的字符串，如果2很大，返回到结尾，等价于a.substr(1);
    a.c_str();字符串起始地址

queue:
    push() 向队尾插入一个元素
    front() 返回队头元素
    back() 返回队尾元素
    pop() 弹出队头元素

priority_queue //默认是大根堆
    push() 插入一个元素
    top() 返回堆顶元素
    pop() 弹出堆顶元素
    priority_queue<int, vector<int>, less<int>> a;//大根堆
    priority_queue<int, vector<int>, greater<int>> a;//小根堆
    或者每次push(-x)//也是小根堆

stack:
    push() 向栈顶插入一个元素
    top() 返回栈顶元素
    pop() 弹出栈顶元素

deque:
    clear()
    front()
    back()
    push_back()/pop_back()
    push_front()/pop_front()
    []
    begin()/end()

set/multiset:
    不能有重复元素/可以有重复元素
    insert() 插入一个数
    find() 返回迭代器，找不到就是end()
    count() 返回某个数的个数
    erase() O(logn+k) k = x个数
        (1) 输入是x，删除所有x
        (2) 输入一个迭代器，删除这个迭代器
    lower_bound()/upper_bound()
    lower_bound(x) 返回大于等于x的最小的数的迭代器
    upper_bound(x) 返回大于x的最小的数的迭代器

map/multimap:
    insert() 插入一个pair
    erase() 输入pair或迭代器
    find()
    lower_bound()/upper_bound()
    []
    //插入
    map<string, int> a;
    a["yxc"] = 1; //O(logn)

unordered_set, unordered_map, unordered_multiset, unordered_multimap;
    和无unordered，不支持lower_bound(),upper_bound(),++,--;
    但是操作基本上O(1)

bitset:
    bitset<100000> s;
    ~, &, |, ^, >>, <<, ==, !=;
    []
    count()// 返回多少个1
    any() 判断是否至少有一个1
    none() 判读是否全为0

    set(), 全设成1
    set(k, v), 将第k位变成v
    reset(), 全设成0；
    flip() 等价于~
    flip(k) 第k位取反

*/

using namespace std;
int main()
{
    int n = 12;
    vector<int> a1;
    vector<int> a2(n);
    vector<int> a3(n, 3);
    vector<int> a4[n];
    return 0;
}