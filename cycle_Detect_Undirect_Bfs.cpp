#include <bits/stdc++.h>
using namespace std;
bool cycleBfs(int i, int V, vector<int> &vis, vector<int> adj[])
{
	queue<pair<int, int> > q;
	q.push(make_pair(i, -1));
	// q.push({i, -1});

	vis[i] = 1;
	while (!q.empty())
	{
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for (auto it : adj[node])
		{

			if (!vis[it])
			{
				q.push(make_pair(it, node));
				vis[it] = 1;
			}
			else if ( it != parent)
				return true;
		}
	}
	return false;

}

bool bfs(int V, vector<int> adj[])
{
	vector<int> vis(V + 1, 0);
	for (int i = 1; i <= V; ++i)
	{
		if (!vis[i])
		{
			if (cycleBfs(i, V, vis, adj))
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
	bool x =  bfs(n, adjL);
	if (x == 0)
		cout << "No Cycle" << "\n";
	if (x == 1)
		cout << "Cycle Present" << "\n";
	return 0;
}