#include<bits/stdc++.h>
using namespace std;

int par[1005],sz[1005];

int findpar(int u){
    if(u==par[u]){return u;}
    return par[u] = findpar(par[u]);
}
bool fmerge(int u, int v){
    int pu=findpar(u),pv=findpar(v);
    if(pu==pv){return 0;}
    if(sz[pu]<sz[pv]){
        swap(pu,pv);
    }
    sz[pu]+=sz[pv];
    par[pv]=pu;
    return 1;
}
int minCostConnectPoints(vector<vector<int>> points) {
    for(int i=0;i<=1000;i++){
        par[i]=i;sz[i]=1;
    }
    vector<pair<int,pair<int,int> > > edges;
    int n=points.size();
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            int dx=abs(points[i][0]-points[j][0]),dy=abs(points[i][1]-points[j][1]);
            edges.push_back({dx+dy,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    int ans=0;
    int cnt=0,i=0;
    while(i<edges.size()){
        int u = edges[i].second.first, v= edges[i].second.second, w = edges[i].first;
        if(fmerge(u,v)){
            cnt++;
            ans+=w;
        }
        i++;
    }
    return ans;
}
