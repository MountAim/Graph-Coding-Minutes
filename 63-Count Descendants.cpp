#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g,go;
vector<int>tin,tout,dep;
int timer;
 
void dfs(int node,int par)
{
    tin[node] = timer++;
    
    if(par == -1) dep[node] = 0;
    else dep[node] = dep[par] + 1;
    
    go[dep[node]].push_back(tin[node]);
    
    for(auto x : g[node])
        if(x != par) dfs(x,node);
        
    tout[node] = timer - 1;
}

int cnt(int x,int l,int r)
{
    return upper_bound(go[x].begin(),go[x].end(),r) - upper_bound(go[x].begin(),go[x].end(),l-1);
}

vector<int> countDescendants (int n, vector<vector<int>> edges, vector<vector<int>>queries)
{
    timer=0;
    g = go = vector<vector<int>>(n+1);
    tin = tout = dep =vector<int>(n+1);
    int x,y;
    for (int i =0; i<edges.size() ; i++) {
        x=edges[i][0],y=edges[i][1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        ans.push_back(cnt(y,tin[x],tout[x]));
    }
    return ans;
}