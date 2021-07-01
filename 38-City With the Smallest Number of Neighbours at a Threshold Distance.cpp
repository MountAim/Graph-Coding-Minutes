#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int findTheCity(int n, vector<vector<int>> edges, int distanceThreshold) {
    vector<vector<int>>dis(n+1,vector<int>(n+1,inf));
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][0],y=edges[i][1],val=edges[i][2];
        dis[x][y]=min(dis[x][y],val);
        dis[y][x]=min(dis[y][x],val);
    }
    for(int i=0;i<n;i++)
    {
        dis[i][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(dis[j][k] > dis[j][i]+ dis[i][k])
                {
                    dis[j][k]=dis[j][i]+dis[i][k];
                }
            }
        }
    }
    vector<int>cnt(n);
    int val=inf;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dis[i][j]<=distanceThreshold)
            {
                cnt[i]++;
            }
        }
        val=min(val,cnt[i]);
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(val==cnt[i])
        {
            ans=i;
        }
    }
    return ans;
}