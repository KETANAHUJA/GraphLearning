#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int ranks[100000];
void makeSet(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		ranks[i] = 0;
	}
}
int findPar(int node)
{
	if (node == parent[node])
		return node;
	return parent[node] = findPar(parent[node]);
}
void Union(int u, int v)
{
	u = findPar(u);
	v = findPar(v);
	if (ranks[u] < ranks[v])
		parent[u] = v;
	else if (ranks[u] > ranks[v])
		parent[v] = u;
	else
	{
		parent[v] = u;
		ranks[u]++;
	}

}
int main()
{
	int m;
	makeSet(m);

	cin >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	if (findPar(2) != findPar(3))
		cout << "Different components" << endl;
	else
		cout << "same components" << endl;

	return 0;
}