#include<bits/stdc++.h>
using namespace std;

int cnt,n,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
vector<pair<int,int>>vec;
void dfs(int x,int y,vector<vector<int>>&grid, vector<vector<int>>&visit)
{
    if(x<0 || y<0 || x>=n || y>=n || grid[x][y]==0 || visit[x][y]==1)
    {
        return;
    }
    cnt++;
    visit[x][y]=1;
    vec.push_back({x,y});
    dfs(x+1,y,grid,visit);
    dfs(x-1,y,grid,visit);
    dfs(x,y+1,grid,visit);
    dfs(x,y-1,grid,visit);
}
int largestIsland(vector<vector<int>> grid) {
    n=grid.size();
    vector<vector<int>>visit(n+1,vector<int>(n+1));
    vector<vector<int>>temp(n+1,vector<int>(n+1)),ind(n+1,vector<int>(n+1));
    int num=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1 && visit[i][j]==0)
            {
                vec.clear();
                cnt=0;
                dfs(i,j,grid,visit);
                for(auto itr:vec)
                {
                    ind[itr.first][itr.second]=num;
                    temp[itr.first][itr.second]=cnt;
                }
                num++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(temp[i][j]==0)
            {
                int val=1;
                unordered_set<int>s;
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0 && y>=0 && x<n && y<n)
                    {
                        if(s.find(ind[x][y])==s.end())
                        {
                            val+=temp[x][y];
                            s.insert(ind[x][y]);
                        }
                    }
                }
                ans=max(ans,val);
            }
            else{
                ans=max(ans,temp[i][j]);
            }
        }
    }
    return ans;
}