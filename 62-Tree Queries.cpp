#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<int>tin,tout;
int timer;
void dfs(int x,int p)
{
    tin[x]=++timer;
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x);
        }
    } 
    tout[x]=timer;
}
bool comp(const array<int,3>&arr1, const array<int,3>&arr2)
{
    return arr1[1]<arr2[1];
}
vector<int> treeQuery(int n, vector<int> a, vector<vector<int>> edges, vector<vector<int>> queries)
{
    timer=0;
    tin.resize(n+1);
    tout.resize(n+1,1e9);
    v=vector<vector<int>>(n+1,vector<int>());
    int x,y;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int>ans(n);
    vector<array<int,3>>temp(n+2);
    dfs(1,0);
    temp[n+1]={0,n+5,n+1};
    for(int i=1;i<=n;i++)
    {   
        temp[i]={0,tin[i],i};
    }
    sort(temp.begin(),temp.end(),comp);
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        int start=tin[x],end=tout[x];
        temp[start][0]+=y;
        temp[end+1][0]-=y;
    }
    for(int i=1;i<=n;i++)
    {
        temp[i][0]+=temp[i-1][0];
    }
    for(int i=1;i<=n;i++)
    {
        ans[temp[i][2]-1]=temp[i][0];
    }
    for(int i=0;i<n;i++)
    {
        ans[i]+=a[i];
    }
    return ans;
}