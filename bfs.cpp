#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int V, vector<int> adj[])
{
	vector<int> bfs;
	vector<int> vis(V + 1, 0);
	for (int i = 1; i <= V; ++i)
	{
		if (!vis[i])
		{
			queue<int> q;
			q.push(i);
			vis[i] = 1;
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				for (auto it : adj[node])
				{
					if (!vis[it])
					{
						q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}
	return bfs;
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
	vector<int> x =  bfs(n, adjL);
	for (auto it : x)
		cout << it << " ";
	return 0;
}