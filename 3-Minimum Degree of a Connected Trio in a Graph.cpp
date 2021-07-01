#include<bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) {
    int ans=1e9;
    int v[n+1][n+1];
    memset(v,0,sizeof(v));
    int deg[n+1];
    memset(deg,0,sizeof(deg));
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][0],y=edges[i][1];
        v[x][y]++;
        v[y][x]++;
        deg[x]++;
        deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(v[i][j] && v[j][k] && v[i][k])
                {
                    ans=min(ans,deg[i]+deg[j]+deg[k]-6);
                }
            }
        }
    }
    return ans==1e9?-1:ans;
}