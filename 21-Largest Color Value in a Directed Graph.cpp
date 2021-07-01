#include<bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>> edges) {
    int  n=colors.size();
    vector<vector<int>>cnt(n,vector<int>(26));
    vector<vector<int>>v(n+1);
    vector<int>in(n+1);
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        in[y]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(!in[i])
        {
            q.push(i);
            cnt[i][colors[i]-'a']=1;
        }
    }
    int ans=0;
    vector<int>topo;
    while(q.size())
    {
        int x=q.front();
        q.pop();
        topo.push_back(x);
        for(int i=0;i<26;i++)
        {
            ans=max(ans,cnt[x][i]);
        }
        for(auto itr:v[x])
        {
            for(int i=0;i<26;i++)
            {
                cnt[itr][i]=max(cnt[itr][i],cnt[x][i]+ (colors[itr]-'a'==i));
            }
            in[itr]--;
            if(in[itr]==0)
            {
                q.push(itr);
            }
        }
    }
    return topo.size()==n?ans:-1;
}