#include<bits/stdc++.h>
using namespace std;

#define maxn 100001
vector<int>visit,sz;
int find(int x)
{
    if(visit[x]!=x)
    {
        return visit[x]=find(visit[x]);
    }
    return x;
}
void Union(int x,int y)
{
    int val=find(x),val1=find(y);
    if(val==val1)
    {
        return;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    visit[val]=val1;
    sz[val1]+=sz[val];
}
bool solve(vector<vector<int>> edges) {
    visit.resize(maxn);
    iota(visit.begin(),visit.end(),0);
    sz.assign(maxn,1);
    int n=edges.size();
    for(int i=0;i<n;i++)
    {
        int x=edges[i][0],y=edges[i][1];
        if(find(x)==find(y))
        {
            return false;
        }
        Union(x,y);
    }
    return true;
}