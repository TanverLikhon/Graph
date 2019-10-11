// CPP program to find maximum/minimum number
/*
For minimum number of isolated vertices, we connect two vertices
 by only one edge. Each vertex should be only connected to one
 other vertex and each vertex should have degree one
Thus if the number of edges is ‘m’, and if ‘n’ vertices <=2 * 'm'
edges, there is no isolated vertex and if this condition is false,
there are n-2*m isolated vertices.
---------------------------------------------------------------------------------------
For maximum number ofisolated vertices, we create a
polygon such that each vertexis connected to other vertex
and each vertex has a diagonalwith every other vertex.
Thus, number of diagonals from onevertex to other vertex
of n sided polygon is n*(n-3)/2and number of edges
 connecting adjacent vertices is n.Thus, total number of
  edges is n*(n-1)/2.
*/
#include <bits/stdc++.h>
using namespace std;

void find(long long n, long m)
{
	if (n <= 2 * m)
		cout << "Minimum " << 0 << endl;
	else
		cout << "Minimum " << n - 2 * m << endl;
	long long i;
	for (i = 1; i <= n; i++) {
		if (i * (i - 1) / 2 >= m)
			break;
	}
	cout << "Maximum " << n - i;
}
int main()
{
	long n = 100 ;
	long m = 0;
	find(n, m);
	return 0;
}
