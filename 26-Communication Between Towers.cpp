#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int y,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&visit)
{
    if(visit[x][y])
    {
        return;
    }
    visit[x][y]=1;
    for(int i=0;i<n;i++)
    {
        if(matrix[i][y])
        {   
            dfs(i,y,n,m,matrix,visit);      
        }
    }
    for(int i=0;i<m;i++)
    {
        if(matrix[x][i])
        {
            dfs(x,i,n,m,matrix,visit);
        }
    }
}
int solve(vector<vector<int>> matrix) {
    int n=matrix.size();
    int m=matrix[0].size(),ans=0;
    vector<vector<int>>visit(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visit[i][j])
            {
                continue;
            }
            if(matrix[i][j]==1)
            {
                dfs(i,j,n,m,matrix,visit);
                ans++;
            }
        }
    }
    return ans;
}