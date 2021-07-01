#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int y,int n,int m,vector<vector<char>>&v,vector<vector<int>>&visit)
{
    if(x<0 || y<0 || x>=n || y>=m || v[x][y]=='0')
    {
        return;
    }
    if(visit[x][y])
    {
        return;
    }
    visit[x][y]=1;
    dfs(x+1,y,n,m,v,visit);
    dfs(x-1,y,n,m,v,visit);
    dfs(x,y+1,n,m,v,visit);
    dfs(x,y-1,n,m,v,visit);
}
int numIslands(vector<vector<char>> grid) {
    int n=grid.size ();
    if(n==0)
    {
        return 0;
    }
    int m=grid[0].size ();
    vector<vector<int>>visit(n,vector<int>(m));
    int ans=0;
    cout<<n<<' '<<m<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1' && !visit[i][j])
            {
                dfs(i,j,n,m,grid,visit);
                ans++;
            }
        }
    }
    return ans;
}