#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

vector<int> g[maxn], w[maxn];
bool u[maxn];
int cnt[maxn];
long long res;
 
void dfs(int v,int n)
{
    u[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (u[to])
            continue;
        dfs(to,n);
        res += min(cnt[to], n - cnt[to]) * (long long)2 * w[v][i];
        cnt[v] += cnt[to];
    }
}
long long holi(int n,vector<vector<int>> edges)
{
    for (int i = 0; i < n; i++)
    {
        g[i].clear();
        w[i].clear();
        u[i] = false;
        cnt[i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        x=edges[i][0],y=edges[i][1],z=edges[i][2];
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    res = 0;
    dfs(0,n);
    return res;
}