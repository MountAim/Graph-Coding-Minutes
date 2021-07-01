#include<bits/stdc++.h>
using namespace std;

int timer;
vector<vector<int>> adj;
vector<int>start,endd,bit;
 
void update(int i, int delta, int n) {
    for(; i <= n; i += i&-i){
        bit[i] += delta;
    }
}
 
int query(int i) {
    int sum = 0;
    for(; i > 0; i -= i&-i) {
        sum += bit[i];
    }
    return sum;
}
 
void dfs(int u, int p,vector<int>&value,int n) {
	start[u] = ++timer;
	update(timer, value[u-1], n);
 
	for(int v: adj[u]){
		if(v!=p) {
			dfs(v, u,value,n);
		}
	}
	endd[u] = timer;
}
 
vector<int> subtreeQuery(int n, vector<int> a, vector<vector<int>>edges, vector<vector<int>> queries)
{
    timer=0;
    start.assign(n+5,0);
    endd.assign(n+5,1e9);
    bit.assign(n+5,0);
    adj=vector<vector<int>>(n+5,vector<int>());
    int type;
    int x,y,val;
	for(int i = 0; i <edges.size(); i++) {
		x=edges[i][0],y=edges[i][1];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int>ans;
	dfs(1, 0, a, n);
	for(int i=0;i<queries.size();i++)
	{
		type=queries[i][0];	
		if(type == 1) {
		    x=queries[i][1],val=queries[i][2];
			update(start[x], -a[x-1], n);
			a[x-1] = val;
			update(start[x], +a[x-1], n);
		}
		else {
			x=queries[i][1];
			ans.push_back(query(endd[x]) - query(start[x] - 1));
		}
	}
	return ans;
}