#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int maxAreaOfIsland(vector<vector<int>> grid) {
    int n=grid.size(),m=grid[0].size(),ans=0;
    if(n==0)
    {
        return ans;
    }
    vector<vector<int>>visit(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int cnt=0;
            if(grid[i][j]==1 && !visit[i][j])
            {
                cnt++;
                queue<pair<int,int>>q;
                q.push({i,j});
                visit[i][j]=1;
                while(!q.empty())
                {
                    pair<int,int>p=q.front();
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int pos=p.first+dx[k],pos1=p.second+dy[k];
                        if(pos>=0 && pos1>=0 && pos<n && pos1<m && !visit[pos][pos1] && grid[pos][pos1]==1)
                        {
                            visit[pos][pos1]=1;
                            cnt++;
                            q.push({pos,pos1});
                        }
                    }
                }
                ans=max(ans,cnt);
            }
        }
    }
    return ans;
}