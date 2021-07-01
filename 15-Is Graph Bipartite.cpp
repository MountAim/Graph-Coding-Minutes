#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> colors(n, 0);
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (colors[i]) continue;
        
        colors[i] = 1;
        q.push(i);
        
        while (!q.empty()) {
            int temp = q.front();
            
            for (auto neighbor : graph[temp]) {
                
				// Color neighbor with opposite color
                if (!colors[neighbor]){
                    colors[neighbor] = -colors[temp];
                    q.push(neighbor);
                }
                
				// If the neighbor has the same color - can't bipartite.
                else if (colors[neighbor] == colors[temp]){
                    return false;
                }
            }
            q.pop();
        }
    }
    return true;
}