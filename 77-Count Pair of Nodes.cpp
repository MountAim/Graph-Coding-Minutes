#include<bits/stdc++.h>
using namespace std;

vector<int> countPairs(int n, vector<vector<int>> edges, vector<int> queries) {
    vector<int> cnt(n + 1), sorted_cnt(n + 1), res;
    vector<unordered_map<int, int>> shared(n + 1);
    for (auto &e : edges) {
        sorted_cnt[e[0]] = cnt[e[0]] = cnt[e[0]] + 1;
        sorted_cnt[e[1]] = cnt[e[1]] = cnt[e[1]] + 1;
        ++shared[min(e[0], e[1])][max(e[0], e[1])];
    }
    sort(begin(sorted_cnt), end(sorted_cnt));
    for (auto &q : queries) {
        res.push_back(0);
        for (int i = 1, j = n; i < j; ){
            if (q < sorted_cnt[i] + sorted_cnt[j]){
                res.back() += (j--) - i;
            }
            else{
                ++i;
            }
        }
        for (auto i = 1; i <= n; ++i){
            for (auto [j, sh_cnt]: shared[i]){
                if (q < cnt[i] + cnt[j] && q + sh_cnt >= cnt[i] + cnt[j]){
                    --res.back();
                }
            }
        }
    }
    return res;
}