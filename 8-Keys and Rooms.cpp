#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>>&v, vector<int>& visit)
{
    visit[x]=1;
    for(auto itr:v[x])
    {
        if(visit[itr]==0)
        {
            dfs(itr,v,visit);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>> rooms) {
   int n=rooms.size();
    vector<int>visit(n);
    dfs(0,rooms,visit);
    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            return false;
        }
    }
    return true;
}