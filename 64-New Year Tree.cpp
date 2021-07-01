#include<bits/stdc++.h>
using namespace std;

int tim;
vector<int>tin,tout,st,lazy,c,arr;
vector<vector<int>> g;
 
void dfs(int k, int par)
{
	tin[k]=++tim;
	arr[tim]=c[k];
	for(auto &it:g[k])
		if(it!=par)
			dfs(it, k);
	tout[k]=tim;
}
 
void propogate(int node, int L, int R)
{
	if(L!=R)
		lazy[node*2]=lazy[node*2+1]=lazy[node];
	st[node]=lazy[node];
	lazy[node]=0;
}
 
void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=arr[L];
		return;
	}
	int M=(L+R)>>1;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=st[node*2]|st[node*2+1];
}
 
void update(int node, int L, int R, int i, int j, int val)
{
	if(lazy[node])
		propogate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		st[node]=val;
		if(L!=R)
		{
			lazy[node*2]=val;
			lazy[node*2+1]=val;
		}
		return;
	}
	int M=(L+R)>>1;
	update(node*2, L, M, i, j, val);
	update(node*2+1, M+1, R, i, j, val);
	st[node]=st[node*2]|st[node*2+1];
}
 
int query(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propogate(node, L, R);
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)>>1;
	return query(node*2, L, M, i, j)|query(node*2+1, M+1, R, i, j);
}
 
vector<int> solve(int n, vector<int> a, vector<vector<int>> edges,vector<vector<int>> queries)
{
    tin=tout=c=arr=vector<int>(n+1);
    st= lazy=vector<int>((4*n)+1);
    g=vector<vector<int>>(n+1,vector<int>());
    tim=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i-1];
		c[i]=(1<<c[i]);
	}
	for(int i=0;i<edges.size();i++)
	{
		int u, v;
        u=edges[i][0],v=edges[i][1];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	build(1, 1, n);
	vector<int>ans;
	for(int i=0;i<queries.size();i++)
	{
		int type=queries[i][0];
		if(type==1)
		{
			long long v=queries[i][1], col=queries[i][2];
			col=(1<<col);
			update(1, 1, n, tin[v], tout[v], col);
		}
		else
		{
			long long v=queries[i][1];
			ans.push_back(__builtin_popcountll(query(1, 1, n, tin[v], tout[v])));
		}
	}
    return ans;
}