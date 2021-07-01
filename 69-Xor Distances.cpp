#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fi first
#define se second 
#define pb push_back

vector<vector<pair<long long,long long>>>v;
vector<long long>pre;
void dfs(int x,int p,long long w)
{
    long long val=w;
    if(p!=0)
    {
        val=val^pre[p];
    }
    pre[x]=val;
    for(auto itr:v[x])
    {
        if(itr.fi!=p)
        {
            dfs(itr.fi,x,itr.se);
        }
    }
}
long long xorDistances(int n, vector<vector<long long>> edges)
{
    pre.assign(n+1,0);
    v=vector<vector<pair<long long,long long>>>(n+1,vector<pair<long long ,long long>>());
    
    long long x,y,val,val1,ans=0;
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1],val=edges[i][2];
        v[x].pb({y,val});
        v[y].pb({x,val});
    }
    dfs(1,0,0);
    
    vector<vector<long long>>suf(n+1,vector<long long>(61));
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=60;j++)
        {
            val1=(long long)1<<j;
            if(val1&pre[i])
            {
                suf[i][j]++;
            }
        }
        if(i<n)
        {
            for(int j=0;j<=60;j++)
            {
                suf[i][j]+=suf[i+1][j];
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=60;j++)
        {
            x=n-suf[i+1][j]-i-1;
            val1=(long long)1<<j;
            if(val1&pre[i])
            {
                x++;
                val=val1%mod;
                val=(x*val)%mod;
                ans=(ans+val)%mod;
            }   
            else{
                val=val1%mod;
                val=(suf[i+1][j]*val)%mod;
                ans=(ans+val)%mod;
            }
        }
    }
    return ans;
}