#include <bits/stdc++.h>
using namespace std;
bool cycleDfs(int node, int parent, vector<int> &vis, vector<int> adjL[])
{

	vis[node] = 1;
	for (auto it : adjL[node])
	{
		if (!vis[it])
		{
			if (cycleDfs(it, node,  vis, adjL))
				return true;
		}
		else if (it != parent)
			return true;

	}
	return false;

}
bool dfs(int V, vector<int> adj[])
{

	vector<int> vis(V + 1, 0);
	int parent = -1;
	for (int i = 1; i <= V; ++i)
	{
		if (!vis[i])
		{
			if (cycleDfs(i, parent, vis, adj))
				return true;
		}

	}
	return false;
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
	bool x =  dfs(n, adjL);
	if (x == 0)
		cout << "No Cycle" << "\n";
	if (x == 1)
		cout << "Cycle Present" << "\n";
	return 0;
}