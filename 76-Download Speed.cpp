#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct FlowEdge { 
    int v, u; ll cap, flow = 0; 
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {} 
};
struct Dinic
{
		const ll FLOW_INF = 1e18;
		int n, m = 0, s, t;
		vector<FlowEdge> edges;	vector<vector<int>> adj;
		vector<int> level, ptr;	queue<int> q;
		Dinic(int n, int s, int t) : n(n), s(s), t(t) { adj.resize(n); level.resize(n); ptr.resize(n); }
		void addEdge(int u, int v, ll cap)
		{
				edges.emplace_back(u, v, cap); edges.emplace_back(v, u, 0);
				adj[u].push_back(m); adj[v].push_back(m+1);
				m += 2;
		}
		bool bfs()
		{
				while (!q.empty())
				{
						int v = q.front(); q.pop();
						for (int id : adj[v])
						{
								if (edges[id].cap - edges[id].flow < 1) continue;
								if (level[edges[id].u] != -1) continue;
								level[edges[id].u] = level[v] + 1;
								q.push(edges[id].u);
						}
				}
				return level[t] != -1;
		}
		ll dfs(int v, ll pushed)
		{
				if (pushed == 0) return 0;
				if (v == t)	return pushed;
				for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++)
				{
						int id = adj[v][cid], u = edges[id].u;
						if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)	continue;
						ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
						if (tr == 0) continue;
						edges[id].flow += tr; edges[id ^ 1].flow -= tr;
						return tr;
				}
				return 0;
		}
		ll flow()
		{
				ll f = 0;
				while (true)
				{
						fill(level.begin(), level.end(), -1);
						level[s] = 0;
						q.push(s);
						if (!bfs())	break;
						fill(ptr.begin(), ptr.end(), 0);
						while (ll pushed = dfs(s, FLOW_INF)) f += pushed;
				}
				return f;
		}
};
// O(N^2 * E)
long long solve(int n, vector<vector<int>> edges)
{
    Dinic dinic(n+1, 1, n);
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0],v=edges[i][1],w=edges[i][2];
        dinic.addEdge(u, v, w);
    }
    return dinic.flow();
}