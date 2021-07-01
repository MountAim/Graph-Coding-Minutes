#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>>&v,int n,vector<int>&vec,vector<vector<int>>&ans)
{
    vec.push_back(x);
    if(x==n-1)
    {
        ans.push_back(vec);
    }
    for(auto itr:v[x])
    {
        dfs(itr,v,n,vec,ans);
    }
    vec.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    int n=graph.size();
    vector<vector<int>>ans;
    vector<int>v;
    dfs(0,graph,n,v,ans);
    return ans;     
}