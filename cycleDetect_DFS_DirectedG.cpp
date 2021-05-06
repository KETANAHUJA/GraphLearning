#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int node, vector<int> &dfsvis, vector<int> &vis, vector<int> adjL[])
{

	vis[node] = 1;
	dfsvis[node] = 1;
	for (auto it : adjL[node])
	{
		if (!vis[it])
		{
			if (checkCycle(it, dfsvis,  vis, adjL))
				return true;
		}
		else if (dfsvis[it])
			return true;

	}
	return false;

}
bool isCyclic(int V, vector<int> adj[])
{

	vector<int> vis(V + 1, 0);
	vector<int> dfsvis(V + 1, 0);
	for (int i = 1; i <= V; ++i)
	{
		if (!vis[i])
		{
			if (checkCycle(i, dfsvis, vis, adj))
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

	bool x =  isCyclic(n, adjL);
	if (x == 0)
		cout << "No Cycle" << "\n";
	if (x == 1)
		cout << "Cycle Present" << "\n";
	return 0;
}