/*
    data:2018.04.01
    author:gsw
    link:http://acm.csu.edu.cn/csuoj/contest/problem?cid=2153&pid=H
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
int num1[1005],num2[1005],num3[1005];
int dp[1005];int n;
void init()
{
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    memset(num3,0,sizeof(num3));
}
int he(int i)
{
	if((num1[i]+num2[i])==num3[i])return 1;//不接收 不产生 
	if((num1[i]+num2[i])%10==num3[i])return 2;//不接受 产生 
	if((num1[i]+num2[i]+1)==num3[i])return 3;//接收 不产生 
	if((num1[i]+num2[i]+1)%10==num3[i]) return 4;//接收 产生 
	return -1;
}
void strtonum(string a,int num)
{
    for(int i=0;i<a.length();i++)
    {
        if(num==1)num1[i]=a[i]-'0';
        if(num==2)num2[i]=a[i]-'0';
        if(num==3)num3[i]=a[i]-'0';
    }
}
int DP()
{
	int maxx=0;
	memset(dp,0,sizeof(dp)); 
	for(int i=0;i<n;i++)
	{
		int a=he(i);
		if(a==-1)continue;
		if(dp[i]==0&&(a==3||a==4))continue;
		dp[i]++; 
		if(a==1||a==3)maxx=max(maxx,dp[i]);
		for(int j=i+1;j<n;j++)
		{
			if((he(i)==1||he(i)==3)&&(he(j)==1||he(j)==2))dp[j]=max(dp[j],dp[i]);
			if((he(i)==2||he(i)==4)&&(he(j)==3||he(j)==4))dp[j]=max(dp[j],dp[i]);
		}
	}
	return n-maxx;
}
int main()
{
    string s1,s2,s3;
    while(cin>>n&&n!=0)
    {
        init();
        cin>>s1>>s2>>s3;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        reverse(s3.begin(),s3.end());
        strtonum(s1,1);strtonum(s2,2);strtonum(s3,3);
        cout<<DP()<<endl;
    }
}





/*


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<string>

using namespace std;
#define ll long long
const ll MAXN=1233;

char str1[MAXN],str2[MAXN],str3[MAXN];
ll n;
ll dp[MAXN];

int cal(int now)
{
	int a=str1[now]-'0';
	int b=str2[now]-'0';
	int c=str3[now]-'0';
	
	if(a+b==c)return 0;//不接受 不产生 
	if(a+b==c-1)return 1;//接收 不产生 
	if(a+b>=10&&(a+b)%10==c)return 2;//不接受 产生 
	if(a+b+1>=10&&(a+b+1)%10==c)return 3;//接收 产生 
	
	return 23333;
}


void init()
{
	memset(dp,0,sizeof(dp));
	cin>>str1>>str2>>str3;
	
	for(int i=0;i<n/2;++i)
	{
		swap(str1[i],str1[n-1-i]);
		swap(str2[i],str2[n-1-i]);
		swap(str3[i],str3[n-1-i]);
	}//cout<<str1<<endl<<str2<<endl<<str3<<endl;
	ll maxx=0;
	for(int i=0;i<n;++i)
	{
		int res=cal(i);
		if(res==23333)continue;
		if(dp[i]==0&&(res==1||res==3))continue;
		dp[i]++;
//		cout<<i<<ends<<res<<ends<<dp[i]<<endl;
		
		
		if(res==0||res==1)maxx=max(maxx,dp[i]);
		for(int j=i+1;j<n;++j)
		{
			int cc=cal(j);
			if(res==0||res==1)if(cc==0||cc==2)dp[j]=max(dp[i],dp[j]);
			if(res==2||res==3)if(cc==1||cc==3)dp[j]=max(dp[i],dp[j]);
		}
	}
	cout<<n-maxx<<"\n";
}

int main()
{
	while(cin>>n&&n)init();
	
	
	
	return 0;
}*/

