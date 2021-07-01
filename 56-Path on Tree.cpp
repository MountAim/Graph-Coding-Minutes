#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second 

vector<vector<pair<int,int>>>v;
vector<int>dis;
void dfs(int x ,int p,int w)
{
    dis[x]=w;
    for(auto itr:v[x])
    {
        if(itr.fi!=p)
        {
            dfs(itr.fi,x,w+itr.se);
        }
    }
}
vector<int> pathOnTree (int n, int k, vector<vector<int>> edges, vector<vector<int>> queries)
{
    dis.resize(n+1);
    v=vector<vector<pair<int,int>>>(n+1,vector<pair<int,int>>());
    int x,y,val;
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1],val=edges[i][2];
        v[x].push_back({y,val});
        v[y].push_back({x,val});
    }
    dfs(k,0,0);
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        val=dis[x]+dis[y];
        ans.push_back(val);
    }
    return  ans;
}