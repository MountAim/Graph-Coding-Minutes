#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    priority_queue<int, vector<int>, greater<int>> q; // Use priority queue

    for (auto& u : prerequisites) {
        auto ai = u[0];
        auto bi = u[1];
        adj[bi].push_back(ai);
        indegree[ai]++;
    }

    for (int i = 0; i < numCourses; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    vector<int> ans;
    int n = 0;
    while (!q.empty()) {
        auto item = q.top(); // Use top() instead of front() for priority queue
        q.pop();
        ans.push_back(item);
        n++;
        for (auto k : adj[item]) {
            indegree[k]--;
            if (indegree[k] == 0) {
                q.push(k);
            }
        }
    }

    // Check if all courses can be taken
    if (n == numCourses) {
        return ans;
    } else {
        return vector<int>();
    }
}
