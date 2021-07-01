#include<bits/stdc++.h>
using namespace std;

int n,m,dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int dfs(int x,int y,vector<vector<int>>&dp,vector<vector<int>>&matrix)
{
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int val=1;
    for(int i=0;i<4;i++)
    {
        int p=x+dx[i];
        int q=y+dy[i];
        if(p>=0 && q>=0 && p<n && q<m && matrix[x][y]<matrix[p][q])
        {
            val=max(val,1+dfs(p,q,dp,matrix));
        }
    }
    return dp[x][y]=val;
}
int longestIncreasingPath(vector<vector<int>> matrix) {
    n=matrix.size(),m=matrix[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=max(ans,dfs(i,j,dp,matrix));
        }
    }
    return ans;
}