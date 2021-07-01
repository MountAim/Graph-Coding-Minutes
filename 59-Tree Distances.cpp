#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>ans;
 
int bfs(int src,int n) {
	int top;
	queue<int> q;
	vector<int> d(n+1, -1);
	d[src] = 0;
	ans[src] = max(ans[src], d[src]);
	q.push(src);
 
	while(!q.empty()) {
		top = q.front();
		q.pop();
 
		for(int v: adj[top]) {
			if(d[v] == -1) {
				q.push(v);
				d[v] = d[top] + 1;
				ans[v] = max(ans[v], d[v]);
			}
		}
	}
	return top;
}
 

vector<int> treeDistances(int n, vector<vector<int>>edges)
{
    ans.assign(n+1,-1);
    adj=vector<vector<int>>(n+1,vector<int>());
    int x,y;
    vector<int>value;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int diam_end_1 = bfs(1,n);
	int diam_end_2 = bfs(diam_end_1,n);
	bfs(diam_end_2,n);
    for(int i=1;i<=n;i++)
    {
        value.push_back(ans[i]);
    }
    return value;
}