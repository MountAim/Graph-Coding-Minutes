#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int orangesRotting(vector<vector<int>> grid) {
    int n=grid.size(),m=grid[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>>visit(n,vector<int>(m)),dist(n,vector<int>(m,INT_MAX));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j});
                visit[i][j]=1;
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.first+dx[i],y=p.second+dy[i];
            if(x>=0 && x<n && y>=0 && y<m)
            {
                if(visit[x][y]==0 && grid[x][y]==1)
                {
                    visit[x][y]=1;
                    q.push({x,y});
                }
                dist[x][y]=min(dist[x][y],dist[p.first][p.second]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                ans=max(ans,dist[i][j]);
            }
        }
    }
    return ans==INT_MAX?-1:ans;
}