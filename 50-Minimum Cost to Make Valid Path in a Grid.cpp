#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int minCost(vector<vector<int>> grid) {
    int n=grid.size(),m=grid[0].size();
    deque<array<int,3>>qu;
    qu.push_front({0,0,0});
    vector<vector<int>>dis(n+1,vector<int>(m+1,1e9));
    dis[0][0]=0;
    int ans;
    while(qu.size())
    {
        array<int,3>arr=qu.front();
        int x=arr[1],y=arr[2],val=arr[0];
        qu.pop_front();
        if(x==n-1 && y==m-1)
        {
            ans=val;
            break;
        }
        for(int i=0;i<4;i++)
        {
            int p=x+dx[i],q=y+dy[i];
            int dir=i+1;
            if(p>=0 && q>=0 && p<n && q<m)
            {
                int flag=0;
                if(grid[x][y]!=dir)
                {
                    flag=1;
                }
                if(dis[p][q]>val+flag)
                {
                    if(flag)
                    {
                        qu.push_back({val+flag,p,q});
                    }
                    else{
                        qu.push_front({val,p,q});
                    }
                }
                dis[p][q]=min(dis[p][q],val+flag);
            }
        }
    }
    return ans;
}