#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

set<int> arr[maxN];
int subSize[maxN], parent[maxN];

int dfs(int node = 1, int par = -1)
{
    subSize[node] = 1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        subSize[node] += dfs(child, node);
    }

    return subSize[node];
}

int cenCal(int node, int par, int n)
{
    for (int child : arr[node])
    {
        if (child == par)
            continue;

        if (subSize[child] > n / 2)
            return cenCal(child, node, n);
    }
    return node;
}

void decompose(int node = 1, int par = -1)
{
    int size = dfs(node, par);
    int centroid = cenCal(node, par, size);

    parent[centroid] = par;

    for (int child : arr[centroid])
    {
        arr[child].erase(centroid), decompose(child, centroid);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    scanf("%d", &n);

    REP(i, 1, n)
    {
        scanf("%d %d", &a, &b);
        arr[a].insert(b), arr[b].insert(a);
    }

    decompose();

    return 0;
}