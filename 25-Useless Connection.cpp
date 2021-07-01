#include<bits/stdc++.h>
using namespace std;

int visit[1001];
int find(int x)
{
    if(x!=visit[x])
    {
        return visit[x]=find(visit[x]);
    }
    return x;
}
void Union(int x,int y)
{
    int val=find(x),val1=find(y);
    visit[val]=val1;
}
vector<int> findUselessConnection(vector<vector<int>> edges) {
    int n=edges.size();
    for(int i=0;i<1001;i++)
    {
        visit[i]=i;
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        int x=edges[i][0],y=edges[i][1];
        if(find(x)==find(y))
        {
            ans.push_back(x);
            ans.push_back(y);
        }
        else
        {
            Union(x,y);
        }
    }
    return ans;
}