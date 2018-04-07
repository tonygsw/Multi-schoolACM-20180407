/*
    data:2018.04.01
    author:gsw
    link:http://acm.csu.edu.cn/csuoj/contest/problem?cid=2152&pid=D
    account:gswycf
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<set>
#define ll long long
using namespace std;
int main()
{
    int c,d;
    while(cin>>c>>d&&(c!=0&&d!=0))
    {
        int ans1=c*30+d*40;
        int ans2=c*35+d*30;
        int ans3=c*40+d*20;
        int ans=min(ans1,ans2);
        ans=min(ans,ans3);
        cout<<ans<<endl;
    }
}
