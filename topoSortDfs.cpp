#include <bits/stdc++.h>
using namespace std;
void dfsHelp(int node, vector<int> &vis, vector<int> adjL[], stack<int> &st)
{
	vis[node] = 1;
	for (auto it : adjL[node])
	{
		if (!vis[it])
		{
			dfsHelp(it, vis, adjL, st);
		}
	}
	st.push(node);

}
vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> topo;
	stack<int> st;
	vector<int> vis(V, 0);
	for (int i = 0; i < V; ++i)
	{
		if (!vis[i])
		{
			dfsHelp(i, vis, adj, st);
		}


	}
	while (!st.empty())
	{
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> adjL[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u , v;
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}
	vector<int> x =  topoSort(n, adjL);
	for (auto it : x)
		cout << it << " ";
	return 0;
}