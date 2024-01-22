#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<int> degree(numCourses),vis(numCourses);
    vector<set<int>> gp(numCourses);
    for(auto &it:prerequisites){
        gp[it[1]].insert(it[0]);
        degree[it[0]]+=1;
    }
    
    vector<int> ans;
    priority_queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(degree[i]==0){
            q.push(-1*i);
        }
    }
    
    while(!q.empty()){
        int node=-1*q.top();
        ans.push_back(node);
        q.pop();
        vis[node]=1;
        for(auto &it:gp[node]){
            if(vis[it]) return {};
            
            degree[it]-=1;
            if(degree[it]==0){
                q.push(-1*it);
            }
        }
    }
    return ans;
}
