#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

vector<int>sz,label;
int cnt;
int find(int x)
{
    if(x!=label[x])
    {
        return label[x]=find(label[x]);
    }
    return x;
}
void Union(int  x,int  y)
{
    int val=find(x),val1=find(y);
    if(val==val1)
    {
        return;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    label[val]=val1;
    cnt-=(sz[val1]*(sz[val1]-1))/2;
    sz[val1]+=sz[val];
    cnt-=(sz[val]*(sz[val]-1))/2;
    cnt+=(sz[val1]*(sz[val1]-1))/2;
}
vector<int> pathQueries(int n, vector<vector<int>> edges, vector<int>queries)
{
    cnt=0;
    int x,y,val;
    label.resize(n+1);
    sz.assign(n+1,1);
    iota(label.begin(),label.end(),0);
    vector<pair<int,pair<int,int>>>v(n-1);
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1],val=edges[i][2];
        v[i]={val,{x,y}};
    }
    sort(v.begin(),v.end());
    set<pair<int,int>>s;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i];
        s.insert({x,i});
    }    
    vector<int>ans(queries.size());
    auto itr=s.begin();
    int ptr=0;
    while(itr!=s.end())
    {
        val=itr->fi;
        while(ptr<n-1 && v[ptr].fi<=val)
        {
            x=v[ptr].se.fi;
            y=v[ptr].se.se;
            Union(x,y);
            ptr++;
        }
        ans[itr->se]=cnt;
        itr++;
    }
    return ans;
}