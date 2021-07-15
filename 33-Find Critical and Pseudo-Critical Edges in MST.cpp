#include<bits/stdc++.h>
using namespace std;
 
// DSU
 
vector<int> par, size;
 
void init(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        size[i] = 1;
    }
}
 
int Find(int a)
{
    if(par[a] == -1)
        return a;
    return par[a] = Find(par[a]);
}
 
void Union(int a, int b)
{
    int p1 = Find(a), p2 = Find(b);
    if(p1==p2)
        return;
    if(size[p1] < size[p2])
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        par[p2] = p1;
        size[p1] = p2;
    }
}
 
// Finding MST Cost
 
int MST(vector<vector<int>> edges, int avoid)
{
    int cost = 0;
    
    for(auto e: edges)
    {
        int id = e[3];
        if(id == avoid)
            continue;
            
        int p1 = Find(e[0]);
        int p2 = Find(e[1]);
        if(p1 == p2)
            continue;
            
        Union(p1, p2);
        cost += e[2];
    }
    
    return cost;
}
 
// Sort according to weight
 
bool cmp(vector<int> a, vector<int> b)
{
    return a[2]<b[2];    
}
 
// Driver function
 
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> edges)
{
    par.resize(n);
    size.resize(n);
    
    vector<int> critical, pseudo;
    
    for(int i=0; i<edges.size(); i++)
    {
        edges[i].push_back(i);
    }
    
    sort(edges.begin(), edges.end(), cmp);
    
    init(n);
    int minCost = MST(edges, -1);
    
    for(auto e: edges)
    {
        init(n);
        int cost = MST(edges, e[3]);
        
        // If the cost of MST by avoiding this edge is greater or the graph is disconnected at the end point vertices of this edge, then this edge is critical
        if(cost>minCost or Find(e[0])!=Find(e[1]))
        {
            critical.push_back(e[3]);
            continue;
        }
        
        // Else check if including the edge results in BST, then it is pseudo-critical else not useful edge
        init(n);
        
        // Include this edge forcefully
        Union(e[0], e[1]);
        cost = e[2];
        
        cost += MST(edges, e[3]);
        
        if(cost == minCost)
            pseudo.push_back(e[3]);
    }
    
    vector<vector<int>> ans;
    sort(critical.begin(),critical.end());
    sort(pseudo.begin(),pseudo.end());
    ans.push_back(critical);
    ans.push_back(pseudo);
    
    return ans;
}
