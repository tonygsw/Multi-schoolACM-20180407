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
#include<queue>
#define ll long long
using namespace std;
bool matri[205][105][105];
class Point{
	public:
		int x,y,time;
		friend bool operator < (Point a,Point b)    
    	{
       		return a.time> b.time;    //重载小于号使得小的先出队列    
    	}    
};
Point s,t;int n,m,k,timeout;
bool vis[105][105];
class P{
	public:
		int x,y;
};
P p[10005];
void change(int s)
{
	int len=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			matri[s][i][j]=matri[s-1][i][j];
			if(matri[s][i][j]==1)
			{
				p[len].x=i;
				p[len].y=j;
				len++;
			}
		}
	if(s%k!=0)return;
	for(int k=0;k<len;k++)
	{
		int i=p[k].x,j=p[k].y;
		if(i-1>=0&&j-1>=0)matri[s][i-1][j-1]=1;
		if(i-1>=0)matri[s][i-1][j]=1;
		if(i-1>=0&&j+1<m)matri[s][i-1][j+1]=1;
		if(j-1>=0)matri[s][i][j-1]=1;
		if(j+1<m)matri[s][i][j+1]=1;
		if(i+1<n&&j-1>=0)matri[s][i+1][j-1]=1;
		if(i+1<n)matri[s][i+1][j]=1;
		if(i+1<n&&j+1<m)matri[s][i+1][j+1]=1;
	}
}
void init()
{
	memset(vis,0,sizeof(vis));
	memset(matri,0,sizeof(matri));
}
int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool judge(int time,int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&matri[time][x][y]!=1&&vis[x][y]==0)return true;
	return false;
}
priority_queue<Point> q;
int bfs()
{
	while(!q.empty())q.pop();
	s.time=0;
	q.push(s);Point tem,nex;
	vis[s.x][s.y]=1;
	while(!q.empty())
	{
		tem=q.top();q.pop();	
		if(matri[tem.time][t.x][t.y]==1)return -1;
		if(matri[tem.time][tem.x][tem.y]==1)continue;
		if(tem.x==t.x&&tem.y==t.y&&matri[tem.time][tem.x][tem.y]==0)return tem.time;
		for(int i=0;i<4;i++)
		{
			nex.x=tem.x+to[i][0];
			nex.y=tem.y+to[i][1];
			nex.time=tem.time+1;
			if(judge(nex.time,nex.x,nex.y))
			{
				vis[nex.x][nex.y]=1;
				q.push(nex);
			}
		}
	}
	return -1;
}char te[105];
int main()
{
	//IO;
	while(scanf("%d%d%d",&n,&m,&k)&&(n!=0&&m!=0&&k!=0))
	{
		init();	
		for(int i=0;i<n;i++)
		{
			scanf("%s",te);
			for(int j=0;j<m;j++)
			{
				if(te[j]=='f')matri[0][i][j]=1;
				if(te[j]=='s')s.x=i,s.y=j; 
				if(te[j]=='t')t.x=i,t.y=j;
			}
		}
		for(int i=1;i<201;i++)
			change(i);
		int ans=bfs();
		if(ans==-1)printf("Impossible\n");
		else printf("%d\n",ans);
	}
}

