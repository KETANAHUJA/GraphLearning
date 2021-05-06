#include <bits/stdc++.h>
using namespace std;
bool bipartiteDfs(int node, vector<int> &color, vector<int> adjL[])
{
	if (color[node] == -1)
		color[node] = 1;
	for (auto it : adjL[node])
	{
		if (color[it] == -1)
		{
			color[it] = 1 - color[node];
			if (!bipartiteDfs(it, color, adjL))
				return false;
		}
		else if (color[it] == color[node])
			return false;

	}
	return true;

}
bool bipartite(int V, vector<int> adj[])
{

	vector<int> color(V, -1);
	for (int i = 0; i < V; ++i)
	{
		if (color[i] == -1)
		{
			if (!bipartiteDfs(i, color, adj))
				return false;
		}

	}
	return true;
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
	bool x =  bipartite(n, adjL);
	if (x == 0)
		cout << "No Bipartite" << "\n";
	if (x == 1)
		cout << "Bipartite Graph" << "\n";
	return 0;
}