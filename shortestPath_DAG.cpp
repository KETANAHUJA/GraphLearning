// 6 7
// 0 1 2
// 1 2 3
// 2 3 6
// 0 4 1
// 4 5 4
// 5 3 1
// 4 2 2

#include <bits/stdc++.h>
using namespace std;
void findTopoSort(int node, vector<int> vis, vector<pair<int, int> > adjL[], stack<int> &st)
{
	vis[node] = 1;
	for (auto it : adjL[node])
	{
		if (!vis[it.first])
			findTopoSort(it.first, vis, adjL, st);
	}
	st.push(node);
}
void shortestPath(int src, int N, vector<pair<int, int> > adjL[])
{
	vector<int> vis(N, 0);
	stack<int> st;
	for (int i = 0; i < N; ++i)
	{
		if (!vis[i])
			findTopoSort(i, vis, adjL, st);
	}
	vector<int> dis(N, INT_MAX);

	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		dis[src] = 0;
		if (dis[node] != INT_MAX)
		{
			for (auto it : adjL[node])
			{
				if (dis[node] + it.second < dis[it.first])
					dis[it.first] = dis[node] + it.second;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (dis[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dis[i] << " ";
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > adjL[n];
	for (int i = 0; i < m; ++i)
	{
		int u , v, wt;
		cin >> u >> v >> wt;
		adjL[u].push_back({v, wt});
	}
	shortestPath(0, n, adjL);
	return 0;
}