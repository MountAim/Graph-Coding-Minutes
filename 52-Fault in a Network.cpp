#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>bridges;
vector<int>tin,low;
int timer;
void dfs(int x,int p,vector<int>&visit,vector<vector<int>>&v)
{
    visit[x]=1;
    tin[x]=low[x]=++timer;
    for(auto itr:v[x])
    {
        if(itr==p)
        {
            continue;
        }
        if(visit[itr])
        {
            low[x]=min(low[x],tin[itr]);
        }
        else{
            dfs(itr,x,visit,v);
            low[x]=min(low[x],low[itr]);
            if(low[itr]>tin[x])
            {
                bridges.push_back({x,itr});
            }
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
    vector<vector<int>>v(n+1);
    for(int i=0;i<connections.size();i++)
    {
        int x=connections[i][0],y=connections[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    timer=0;
    bridges.clear();
    low.assign(n+1,0);
    tin.assign(n+1,0);
    vector<int>visit(n+1);
    dfs(0,0,visit,v);
    return bridges;
}