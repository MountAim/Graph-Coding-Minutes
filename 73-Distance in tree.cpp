#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<vector<long long>>sub,ans;
void dfs_1(int x,int p,int k)
{
    sub[x][0]=1;
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs_1(itr,x,k);
            for(int i=0;i<=k;i++)
            {
                sub[x][i+1]+=sub[itr][i];
            }
        }
    }
}
void dfs(int x,int p,int k)
{
    if(p!=0)
    {
        vector<long long>vec(k+5);
        ans[x]=sub[x];
        vec=ans[p];
        for(int i=1;i<=k;i++)
        {
            vec[i]-=sub[x][i-1];
        }
        for(int i=0;i<=k;i++)
        {
            ans[x][i+1]+=vec[i];
        }
    }
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x,k);
        }
    }
}
long long distance(int n, int k, vector<vector<int>> edges)
{
    v=vector<vector<int>>(n+1,vector<int>());
    sub=vector<vector<long long>>(n+1,vector<long long>(k+5));
    ans=vector<vector<long long>>(n+1,vector<long long>(k+5));
    long long x,y,val;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs_1(1,0,k);
    ans[1]=sub[1];
    dfs(1,0,k);
    val=0;
    for(int i=1;i<=n;i++)
    {
        val+=ans[i][k];
    }
    val/=2;
    return val;
}