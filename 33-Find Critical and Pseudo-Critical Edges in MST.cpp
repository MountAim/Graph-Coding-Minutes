#include<bits/stdc++.h>
using namespace std;

bool comp(const vector<int>&a, const vector<int>&b)
{
    return a[2]<b[2];
}
vector<int>visit,sz;    
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
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> edges) {
    unordered_set<int>cri,non_cri;
    map<pair<int,int>,int>mapping;
    for(int i=0;i<edges.size();i++)
    {
        mapping[{edges[i][0],edges[i][1]}]=i;
    }
    sort(edges.begin(),edges.end(),comp);
    visit.resize(n+1);
    sz.resize(n+1);
    iota(visit.begin(),visit.end(),0);
    sz.assign(n+1,1);
    int mst=0; 
   
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][0],y=edges[i][1],ind,val=edges[i][2];
        ind=mapping[{x,y}];
        if(find(x)!=find(y))
        {
            mst+=val;
            Union(x,y);
            cri.insert(ind);
        }
    }
    for(int i=0;i<edges.size();i++)
    {
        iota(visit.begin(),visit.end(),0);
        sz.assign(n+1,1);
        int ind=mapping[{edges[i][0],edges[i][1]}];
        unordered_set<int>nodes;
        int total=0;
        for(int j=0;j<edges.size();j++)
        {
            if(i!=j)
            {
                int x=edges[j][0],y=edges[j][1],val=edges[j][2];
                if(find(x)!=find(y))
                {
                    Union(x,y);
                    total+=val;
                    nodes.insert(x);
                    nodes.insert(y);
                }
            }
        }
        if(nodes.size()==n && total==mst)
        {
            if(cri.find(ind)==cri.end()){
                iota(visit.begin(),visit.end(),0);
                sz.assign(n+1,1);
                Union(edges[i][0],edges[i][1]);
                int value=edges[i][2];
                unordered_set<int>nodes;
                nodes.insert(edges[i][1]);
                nodes.insert(edges[i][0]);
                for(int j=0;j<edges.size();j++)
                {
                    if(i!=j)
                    {
                        int x=edges[j][0],y=edges[j][1],val=edges[j][2];
                        if(find(x)!=find(y))
                        {
                            Union(x,y);
                            value+=val;
                            nodes.insert(x);
                            nodes.insert(y);
                        }
                    }
                }
                if(nodes.size()==n && value==mst)
                {
                    non_cri.insert(ind);
                }
            }
            else{
                cri.erase(ind);
                non_cri.insert(ind);
            }
        }
    }
    vector<vector<int>>ans;
    for(int i=0;i<2;i++)
    {
        vector<int>v;
        if(i==0)
        {
            for(auto itr:cri)
            {
                v.push_back(itr);
            }
        }
        else{
            for(auto itr:non_cri)
            {
                v.push_back(itr);
            }
        }
        sort(v.begin(),v.end());
        ans.push_back(v);
    }
    return ans;
}
