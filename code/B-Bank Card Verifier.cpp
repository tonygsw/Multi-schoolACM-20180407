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
int num[20];
string en="0000";
int main()
{
    string a1,a2,a3,a4;
    while(cin>>a1>>a2>>a3>>a4&&(a1!=en&&a2!=en&&a3!=en&&a4!=en))
    {
        num[1]=a1[0]-'0';num[2]=a1[1]-'0';num[3]=a1[2]-'0';num[4]=a1[3]-'0';
        num[5]=a2[0]-'0';num[6]=a2[1]-'0';num[7]=a2[2]-'0';num[8]=a2[3]-'0';
        num[9]=a3[0]-'0';num[10]=a3[1]-'0';num[11]=a3[2]-'0';num[12]=a3[3]-'0';
        num[13]=a4[0]-'0';num[14]=a4[1]-'0';num[15]=a4[2]-'0';num[16]=a4[3]-'0';
        for(int i=1;i<=16;i++)
        {
            if(i%2==0)continue;
            num[i]=num[i]*2;
            if(num[i]>9)num[i]=num[i]-9;
        }
        int sum=0;
        for(int i=1;i<=16;i++)sum+=num[i];
        if(sum%10==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
