#include<bits/stdc++.h>
using namespace std;

bool solve(int n, vector<vector<int>>edges) {
    vector<vector<int>>v(n+1);
    vector<int>ind(n+1);
    int x,y;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        ind[y]++;
    }
    vector<int>topo;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
        }
    }
    while(q.size())
    {
        x=q.front();
        q.pop();
        topo.push_back(x);
        for(auto itr:v[x])
        {
            ind[itr]--;
            if(ind[itr]==0)
            {
                q.push(itr);
            }
        }
    }
    return topo.size()!=n;
}