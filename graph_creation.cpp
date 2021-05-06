#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	// n vertices
	// m edges
	int n, m;
	cin >> n >> m;

	// using matrix

	int adj[n + 1][n + 1];
	memset(adj, 0, sizeof(adj[0][0]) * m * n);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	//using adj list
	vector<int> adjL[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u , v;
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}
	return 0;
}