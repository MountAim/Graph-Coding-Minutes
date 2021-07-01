#include<bits/stdc++.h>
using namespace std;

int treeDiameter(vector<vector<int>> edges) {
    int n=edges.size()+1;
	vector<vector<int>>v(n+1);
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		x=edges[i][0],y=edges[i][1];
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int>q;
	vector<int>visit(n+1),dis(n+1,0);
	visit[1]=1;
	q.push(1);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto itr:v[x])
		{
			if(!visit[itr])
			{
				q.push(itr);
				visit[itr]=1;
				dis[itr]=max(dis[itr],dis[x]+1);
			}
		}
	}
	int val=0,val1;
	for(int i=1;i<=n;i++)
	{
		if(val<dis[i])
		{
			val=dis[i];
			x=i;
		}
	}
	dis.assign(n+1,0);
	visit.assign(n+1,0);
	q.push(x);
	visit[x]=1;
	while(!q.empty())
	{
		y=q.front();
		q.pop();
		for(auto itr:v[y])
		{
			if(!visit[itr])
			{
				q.push(itr);
				visit[itr]=1;
				dis[itr]=max(dis[itr],dis[y]+1);
			}
		}
	}
	val1=0;
	for(int i=1;i<=n;i++)
	{
		val1=max(val1,dis[i]);
	}
	return val1;
}