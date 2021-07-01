#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
int shortest_cycle(int n)
{
    // To store length of the shortest cycle
    int ans = INT_MAX;
 
    // For all vertices
    for (int i = 1; i <= n; i++) {
 
        vector<int> dist(n+1, (int)(1e9));
        vector<int> par(n+1, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
 
        while (!q.empty()) {
 
            int x = q.front();
            q.pop();
 
            for (int child : gr[x]) {
 
                if (dist[child] == (int)(1e9)) {
 
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                }
 
                else if (par[x] != child and par[child] != x){
                    ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
    }
 
    if (ans == INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
}
int solve(int n,vector<vector<int>> edges){
    gr=vector<vector<int>>(n+1,vector<int>());
    for(int i=0;i<edges.size();i++){
        int x=edges[i][0],y=edges[i][1];
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    return shortest_cycle(n);
}