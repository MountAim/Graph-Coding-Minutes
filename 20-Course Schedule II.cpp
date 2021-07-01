#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int>>v(numCourses+1);
    int x,y,val;
    vector<int>ind(numCourses+1);
    for(int i=0;i<prerequisites.size();i++)
    {
        x=prerequisites[i][0],y=prerequisites[i][1];
        v[y].push_back(x);
        ind[x]++;
    }
    queue<int>q;
    vector<int>topo;
    set<int>s;
    for(int i=0;i<numCourses;i++)
    {
        if(ind[i]==0)
        {
            s.insert(i);
        }
    }
    for(auto itr:s)
    {
        q.push(itr);
    }
    while(q.size())
    {
        x=q.front();
        q.pop();
        topo.push_back(x);
        s.clear();
        for(auto itr:v[x])
        {
            ind[itr]--;
            if(ind[itr]==0){
                s.insert(itr);
            }
        }
        for(auto itr:s)
        {
            q.push(itr);
        }
    }
    if(topo.size()!=numCourses)
    {
        return {};
    }
    return topo;
}