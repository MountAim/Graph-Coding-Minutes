#include<bits/stdc++.h>
using namespace std;

#define maxn 100001

int findCenter(vector<vector<int>> edges) {
    vector<int>deg(maxn);
    int n=edges.size(),x,y;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        x=edges[i][0],y=edges[i][1];
        s.insert(x);
        s.insert(y);
        deg[x]++;
        deg[y]++;
    }
    for(int i=1;i<maxn;i++)
    {
        if(deg[i]==(int)s.size()-1)
        {
            return i;
        }
    }
    return -1;
}