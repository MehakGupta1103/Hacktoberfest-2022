
#include <iostream>
#include <queue>
#define V 4

using namespace std;

// This function returns true if graph
// G[V][V] is Bipartite, else false
bool isBipartite(int G[][V], int src)
{
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// Assign first color to source
	colorArr[src] = 1;
	queue <int> q;
	q.push(src);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (G[u][u] == 1)
		return false;

		for (int v = 0; v < V; ++v)
		{
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1)
			{
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}
	return true;
}

int main()
{
	int G[][V] = {{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0}
	};

	isBipartite(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}
