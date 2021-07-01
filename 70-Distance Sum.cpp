#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<int>sz,sub,ans;
void dfs_1(int x,int p)
{
    sz[x]=1;
    sub[x]=0;
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs_1(itr,x);
            sz[x]+=sz[itr];
            sub[x]+=(sub[itr]+sz[itr]);
        }
    }
}
void dfs(int x,int p,int n)
{
    int val=sub[x],par;
    if(p!=0)
    {
        par=ans[p]-sub[x]-sz[x];
        val=par+val+n-sz[x];
        ans[x]=val;
    }
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x,n);
        }
    }
}
vector<int> distanceSum(int n, vector<vector<int>> edges)
{
    int x,y,val;
    v=vector<vector<int>>(n+1,vector<int>());
    sz.assign(n+1,0);
    sub.assign(n+1,0);
    ans.assign(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs_1(1,0);
    ans[1]=sub[1];
    dfs(1,0,n);
    vector<int>distance;
    for(int i=1;i<=n;i++)
    {
        distance.push_back(ans[i]);
    }
    return distance;
}