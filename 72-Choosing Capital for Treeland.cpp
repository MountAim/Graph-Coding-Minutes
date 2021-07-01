#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>v;
vector<int>sub,ans;
unordered_map<int,unordered_set<int>>m;
void dfs_1(int x,int p)
{
    sub[x]=0;
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs_1(itr,x);
            int cnt=0;
            if(m[itr].find(x)!=m[itr].end())
            {
                cnt=1;
            }
            sub[x]+=sub[itr]+cnt;
        }
    }
}
void dfs(int x,int p)
{
    if(p!=0)
    {
        int par=ans[p]-sub[x];
        if(m[x].find(p)!=m[x].end())
        {
            par--;
        }
        ans[x]=sub[x]+par;
        if(m[p].find(x)!=m[p].end())
        {
            ans[x]++;
        }
    }
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x);
        }
    }
}
vector<int> choosingCapital(int n, vector<vector<int>> edges)
{
    v=vector<vector<int>>(n+1,vector<int>());
    ans=vector<int>(n+1);
    sub=vector<int>(n+1);
    m.clear();
    int x,y,val;
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
        m[x].insert(y);
    }
    dfs_1(1,0);
    ans[1]=sub[1];
    dfs(1,0);
    vector<int>vec;
    val=1e9;
    for(int i=1;i<=n;i++)
    {
        val=min(val,ans[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(val==ans[i])
        {
            vec.push_back(i);
        }
    }
    return vec;
}