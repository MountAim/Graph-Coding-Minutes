#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<int>visit,tin,low,ans;
int timer;
void dfs(int x,int p)
{
    tin[x]=low[x]=++timer;
    int child=0;
	visit[x]=1;
    for(auto itr:v[x])
    {
		if(itr==p)
		{
			continue;
		}
        if(visit[itr]==1)
        {
            low[x]=min(low[x],tin[itr]);
        }
        else{
            child++;
            dfs(itr,x);
            low[x]=min(low[x],low[itr]);
            if(p!=-1 && tin[x]<=low[itr])
            {
                ans[x]=1;
            }
        }
    }
    if(p==-1 && child>1)
    {   
        ans[x]=1;
    }
}
vector<bool> destructiveBob(int n, vector<vector<int>> edges, vector<int>queries)
{
    timer=0;
    v=vector<vector<int>>(n+1,vector<int>());
    tin=vector<int>(n+1);
    low=vector<int>(n+1);
    ans=vector<int>(n+1);
    visit=vector<int>(n+1);
    int x,y,val;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==0)
		{
		    dfs(i,-1);
		}
	}
	vector<bool>vec;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i];
        if(ans[x])
        {
            vec.push_back(true);
        }
        else{
            vec.push_back(false);
        }
    }
    return vec;
}