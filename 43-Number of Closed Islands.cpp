#include<bits/stdc++.h>
using namespace std;

int fill(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j]){
        return 0;
    }
    return (g[i][j] = 1) + fill(g, i + 1, j) + fill(g, i, j + 1) + fill(g, i - 1, j) + fill(g, i, j - 1);
}
int closedIsland(vector<vector<int>> g) {
    for (int i = 0; i < g.size(); ++i){
        for (int j = 0; j < g[i].size(); ++j){
            if (i * j == 0 || i == g.size() - 1 || j == g[i].size() - 1){
                fill(g, i, j);
            }
        }
    }
    int res=0;
    for (int i = 0; i < g.size(); ++i){
        for (int j = 0; j < g[i].size(); ++j){
            res += fill(g, i, j) > 0;
        }
    }
    return res;
}