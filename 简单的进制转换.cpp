/*
输入格式：
    第一行n，第二行一个n进制数，第三行表示要转换的进制数
输出格式：
    一行，输出转换后的数
*/

#include <iostream>
#include <cstring>
using namespace std;
int main()
{

    long long n, m;
    char s[20];
    cin >> n >> s >> m;//读入数据
    long long R = 1, ans = 0;
    int i = strlen(s);//i指向要转换的数的最后一位的后面一位
    while(i--)//i指向要转换的数的最后一位
    {
        int tmp;
        if(s[i]>='A') tmp = s[i] - 'A' + 10;//如果是字母，转换成数字
        else tmp = s[i] - '0';//是数字就直接减‘0’就得到该位数

        ans += tmp * R;//该位数乘进制基数
        R *= n;//下一位数进制基数要乘“进制”
    }
    //上面循环将转换数变成了十进制
    R = 1;
    while(R*m<ans)
        R *= m;//计算出转换后数的最高位
    char str[] = "ABCDEF";
    while(ans||R)
    {
        int tmp = ans / R;//每次算出最高位
        if(tmp>9) cout << str[tmp-10];//如果大于9，换成输出字母
        else cout << tmp;//否则直接输出
        ans %= R;//ans减掉最高位表示的值，开始下一位输出作准备
        R /= m;//进制基数每次要除以“进制”
    }
    return 0;
}