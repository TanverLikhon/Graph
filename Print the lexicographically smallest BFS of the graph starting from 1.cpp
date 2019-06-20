// C++ program to print the lexcicographically
// smallest path starting from 1
#include <bits/stdc++.h>
using namespace std;
// Function to print the smallest lexicographically
// BFS path starting from 1
int r;
void printLexoSmall(vector<int> adj[], int n)
{
	// Visited array
	bool vis[n + 1];
	memset(vis, 0, sizeof vis);
	// Minimum Heap
	priority_queue<int, vector<int>, greater<int> > Q;
	// First one visited
	vis[1] = true;
	Q.push(1);
	// Iterate till all nodes are visited
	while (!Q.empty()) {
		// Get the top element
		int now = Q.top();
		// Pop the element
		Q.pop();
		// Print the current node
		cout << now << " ";
		if(now==r)return;
		// Find adjacent nodes
		for (auto p : adj[now]) {
			// If not visited
			if (!vis[p]) {
				// Push
				Q.push(p);
				// Mark as visited
				vis[p] = true;
			}
		}
	}
}
// Function to insert edges in the graph
void insertEdges(int u, int v, vector<int> adj[])
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
// Driver Code
int main()
{
	int n = 4, m = 5;
	cin>>r;
	vector<int> adj[n + 1];
	// Insert edges
	insertEdges(1, 2, adj);
	insertEdges(2,1, adj);
	insertEdges(2,3, adj);
	insertEdges(3,2, adj);
	insertEdges(3, 4, adj);
	insertEdges(4, 3, adj);
	insertEdges(1, 4, adj);
	insertEdges(4,1 ,adj);
	insertEdges(1,3 ,adj);
	insertEdges(3,1, adj);
	// Function call
	printLexoSmall(adj, n);

	return 0;
}
