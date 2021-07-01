#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>v;
void dfs(int x,int y,int n,vector<vector<int>>&a,vector<vector<int>>&visit)
{
    if(x<0  || y<0 || x>=n ||y>=n || a[x][y]==0)
    {
        return;
    }
    if(visit[x][y])
    {
        return;
    }
    visit[x][y]=1;
    v.push_back({x,y});
    dfs(x+1,y,n,a,visit);
    dfs(x-1,y,n,a,visit);
    dfs(x,y+1,n,a,visit);
    dfs(x,y-1,n,a,visit);
}
int shortestBridge(vector<vector<int>> a) {
    int n=a.size(),val=0;
    v.clear();
    vector<vector<int>>visit(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                dfs(i,j,n,a,visit);
                val=1;
                break;
            }
        }
        if(val)
        {
            break;
        }
    }
    queue<pair<int,int>>q;
    vector<vector<int>>visit1(n,vector<int>(n)),dis(n,vector<int>(n));
    int ans=INT_MAX,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    for(auto  itr:v)
    {
        q.push({itr.first,itr.second});
        visit1[itr.first][itr.second]=1;
    }
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        if(!visit[p.first][p.second] && a[p.first][p.second]==1)
        {
            ans=min(ans,dis[p.first][p.second]);
            break;
        }
        for(int i=0;i<4;i++)
        {
            int pos=p.first+dx[i],pos1=p.second+dy[i];
            if(pos>=0 && pos1>=0 && pos<n && pos1<n && !visit1[pos][pos1])
            {
                visit1[pos][pos1]=1;
                q.push({pos,pos1});
                dis[pos][pos1]=dis[p.first][p.second]+1;
            }
        }
    }
    return ans-1;
}