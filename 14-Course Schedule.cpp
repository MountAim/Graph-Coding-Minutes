#include<bits/stdc++.h>
using namespace std;

bool ans;
void dfs(int x,vector<vector<int>>&v,int col[])
{
    col[x]=1;
    for(auto itr:v[x])
    {
        if(!col[itr])
        {
            dfs(itr,v,col);
        }
        else
        {
            if(col[itr]==1)
            {
                ans=false;
            }
        }

    }
    col[x]=2;
}
bool canFinish(vector<vector<int>> c,int n) {
    ans=true;
    vector<vector<int>>v(n);
    for(int i=0;i<c.size();i++)
    {
        v[c[i][0]].push_back(c[i][1]);
    }
    int col[n];
    memset(col,0,sizeof(col));
    for(int i=0;i<n;i++)
    {
        if(!col[i])
        {
            dfs(i,v,col);
        }
    }
    return ans;
}