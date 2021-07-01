#include<bits/stdc++.h>
using namespace std;

int dirs[5] = {0, 1, 0, -1, 0};
vector<vector<int>> highestPeak(vector<vector<int>> w) {
    vector<pair<int, int>> p;
    int h = 1, si = w.size(), sj = w[0].size();
    for (auto i = 0; i < si; ++i)
        for (auto j = 0; j < sj; ++j) {
            w[i][j] = w[i][j] == 1 ? 0 : -1;
            if (w[i][j] == 0)
                p.push_back({i, j});
        }
    while (!p.empty()) {
        vector<pair<int, int>> p1;
        for (auto [i, j] : p) {
            for (int d = 0; d < 4; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                if (x >= 0 && y >= 0 && x < si && y < sj && w[x][y] == -1) {
                    w[x][y] = h;
                    p1.push_back({x, y});
                }
            }
        }
        swap(p, p1);
        ++h;
    }
    return w;
}