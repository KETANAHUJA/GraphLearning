#include <bits/stdc++.h>
using namespace std;
void dfsHelp(int node, vector<int> &vis, vector<int> adjL[], vector<int> &dfs)
{
	dfs.push_back(node);
	vis[node] = 1;
	for (auto it : adjL[node])
	{
		if (!vis[it])
		{
			dfsHelp(it, vis, adjL, dfs);
		}
	}

}
vector<int> dfs(int V, vector<int> adj[])
{
	vector<int> dfs;
	vector<int> vis(V + 1, 0);
	for (int i = 1; i <= V; ++i)
	{
		if (!vis[i])
		{
			dfsHelp(i, vis, adj, dfs);
		}

	}
	return dfs;
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
	vector<int> x =  dfs(n, adjL);
	for (auto it : x)
		cout << it << " ";
	return 0;
}