#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> topo;
	queue<int> q;

	vector<int> indegree(V, 0);
	for (int i = 0; i < V; ++i)
	{
		for (auto it : adj[i])
			indegree[it]++;
	}
	for (int i = 0; i < V; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);

	}


	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for (auto it : adj[node])
		{
			indegree[it]--;
			if (!indegree[it])
			{
				q.push(it);
			}
		}
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