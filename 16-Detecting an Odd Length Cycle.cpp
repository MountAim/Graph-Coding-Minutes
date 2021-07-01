#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> graph)
{
    int n=graph.size(),m=graph[0].size();
    vector<int>col(n+1,-1);
    for(int i=0;i<n;i++)
    {
        if(col[i]==-1)
        {
            queue<int>q;
            q.push(i);
            col[i]=0;
            while(q.size())
            {
                int x=q.front();
                q.pop();
                for(auto itr:graph[x])
                {
                    if(col[itr]==-1)
                    {
                        col[itr]=col[x]^1;
                        q.push(itr);
                    }
                    else{
                        if(col[itr]==col[x])
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}