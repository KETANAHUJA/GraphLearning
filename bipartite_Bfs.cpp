#include <bits/stdc++.h>
using namespace std;
bool bipartiteBfs(int i, vector<int> &color, vector<int> adj[])
{
	queue<int> q;
	q.push(i);
	color[i] = 1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (auto it : adj[node])
		{

			if (color[it] == -1)
			{
				q.push(it);
				color[it] = 1 - color[node];
			}
			else if (color[it] == color[node])
				return false;
		}
	}
	return true;

}

bool checkBipartite(int V, vector<int> adj[])
{
	vector<int> color(V + 1, -1);
	for (int i = 1; i <= V; ++i)
	{
		if (color[i] == -1)
		{
			if (!bipartiteBfs(i, color, adj))
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
	bool x =  checkBipartite(n, adjL);
	if (x == 0)
		cout << "No Bipartite Graph" << "\n";
	if (x == 1)
		cout << "Bipartite Graph" << "\n";
	return 0;
}