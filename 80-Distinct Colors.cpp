#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

vector<vector<int>>v;
vector<int>sz,ans,col;
void dfs(int x,int p)
{
	sz[x]+=1;
	for(auto itr:v[x])
	{
		if(itr!=p)
		{
			dfs(itr,x);
			sz[x]+=sz[itr];
		}
	}
}
map<int,int>m;
void solve(int x,int p,bool keep, vector<int>* vec[])
{
	int mx=-1,bigchild=-1;
	for(auto itr:v[x])
	{
		if(itr!=p && mx<sz[itr])
		{
			mx=sz[itr];
			bigchild=itr;
		}
	}
	for(auto itr:v[x])
	{
		if(itr!=p && itr!=bigchild)
		{
			solve(itr,x,0,vec);
		}
	}
	if(bigchild!=-1)
	{
		solve(bigchild,x,1,vec);
		vec[x]=vec[bigchild];
	}
	else
	{
		vec[x]=new vector<int>();
	}
	vec[x]->push_back(x);
	m[col[x]]++;
	for(auto itr:v[x])
	{
		if(itr!=p && itr!=bigchild)
		{
			for(auto it:*vec[itr])
			{
				m[col[it]]++;
				vec[x]->push_back(it);						
			}			
		}
	}
	ans[x-1]=m.size();
	if(!keep)
	{
		for(auto itr:*vec[x])
		{
			m[col[itr]]--;
			if(m[col[itr]]==0)
			{
				m.erase(col[itr]);
			}
		}
	}
}
vector<int> solve(int n, vector<int> a, vector<vector<int>> edges)
{
    m.clear();
    vector<int> *vec[n+1];
    v=vector<vector<int>>(n+1,vector<int>());
    sz=col=vector<int>(n+1);
	ans=vector<int>(n);
	for(int i=0;i<n;i++)
	{
	    col[i+1]=a[i];
	}
	int x,y;
	for(int i=0;i<edges.size();i++)
	{
	    x=edges[i][0],y=edges[i][1];
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	solve(1,0,1,vec);
	return ans;
}