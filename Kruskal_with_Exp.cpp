#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    cout<<"Entering root as "<<x<<endl;
    cout<<"idx[x]="<<id[x]<<endl;
    while(id[x] != x)
    {   cout<<"id[id[x]]"<<id[id[x]]<<endl;
        id[x] = id[id[x]];
        x = id[x];
    }
    cout<<"Leaving root "<<x<<endl;
    return x;
}

void union1(int x, int y)
{
  cout<<"Entering union  "<<x<<"  -- "<<y<<endl;

    int p = root(x);
    int q = root(y);
    cout<<"p  "<<p<<"   q   "<<q<<endl;
    id[q] = id[p];

    cout<<"id "<<id[p]<<"   --  "<<id[q]<<endl;
}

long long kruskal()
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        cout<<"               Working for      "<<x<<"---"<<y<<" cost  "<<cost<<endl;cout<<endl;
        cout<<"roots are "<<root(x)<<" and "<<root(y)<<endl;

        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal();
    cout << minimumCost << endl;
    return 0;
}
/*

*/
