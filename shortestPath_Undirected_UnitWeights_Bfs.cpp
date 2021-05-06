#include <bits/stdc++.h>
using namespace std;
void bfs(int V, vector<int> adj[], int src)
{
	vector<int> dis(V, INT_MAX);
	queue<int> q;
	dis[src] = 0;
	q.push(src);


	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (auto it : adj[node])
		{
			if (dis[node] + 1 < dis[it])
			{
				dis[it] = dis[node] + 1;
				q.push(it);
			}
		}
	}
	for (int i = 0; i < V; ++i)
	{
		cout << dis[i] << " ";
	}
	cout << endl;

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
	bfs(n, adjL, 0);

	return 0;
}