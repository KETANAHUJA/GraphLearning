#include <bits/stdc++.h>
using namespace std;
// 5 6
// 1 4 1
// 4 3 3
// 3 5 1
// 2 5 5
// 1 2 2
// 2 3 4
// 1
int main(int argc, char const *argv[])
{
	int n, m, source;
	cin >> n >> m;
	vector<pair<int, int> > adjL[n + 1];
	for (int i = 1; i <= m; ++i)
	{
		int u , v, wt;
		cin >> u >> v >> wt;
		adjL[u].push_back({v, wt});
		adjL[v].push_back({u, wt});

	}
	cin >> source;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dist(n + 1, INT_MAX);
	dist[source] = 0;
	pq.push({0, source});

	while (!pq.empty())
	{
		int dis = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		for (auto it : adjL[prev])
		{
			int next = it.first;
			int nextDis = it.second;
			if (dist[next] > dist[prev] + nextDis)
			{
				dist[next] = dist[prev] + nextDis;
				pq.push({dist[next], next});
			}
		}

	}
	for (int i = 1; i <= n ; ++i)
	{
		cout << dist[i] << " ";
	}
	cout << endl;


	return 0;
}