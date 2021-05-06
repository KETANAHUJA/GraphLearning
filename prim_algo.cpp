#include <bits/stdc++.h>
using namespace std;
// 5 6
// 0 1 2
// 1 2 3
// 2 4 7
// 4 1 5
// 0 3 6
// 3 1 8
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
		adjL[v].push_back({u, wt});

	}
	int key[n];
	bool mstSet[n];
	int parent[n];
	for (int i = 0; i < n; ++i)
	{
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = -1;
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({0, 0});

	for (int i = 0; i < n - 1; ++i)
	{
		int u = pq.top().second;
		pq.pop();
		mstSet[u] = true;
		for (auto it : adjL[u])
		{
			int v = it.first;
			int wt = it.second;
			if (mstSet[v] == false && wt < key[v])
			{
				key[v] = wt;
				parent[v] = u;
				pq.push({key[v], v});
			}
		}
	}



	for (int i = 0; i < n ; ++i)
	{
		cout << parent[i] << " - " << i << " , ";
	}
	cout << endl;


	return 0;
}