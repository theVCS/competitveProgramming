#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int parent[maxN][16], level[maxN], n;

void dfs(int node, int par = -1, int lev = 0)
{
    vis[node] = true;
    level[node] = lev;
    parent[node][0] = par;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, node, lev + 1);
        }
    }
}

void init(int root = 1)
{
    dfs(root);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 16; j++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
    {
        swap(a, b);
    }

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
    {
        return a;
    }

    for (int i = 15; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int dist(int a, int b)
{
    int lca = LCA(a, b);
    return (level[a] + level[b] - 2 * level[lca]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    init();

    while (true)
    {
        cin >> a >> b;
        cout << dist(a, b) << endl;
    }

    return 0;
}

// 8
// 1 2
// 1 3
// 2 4
// 2 6
// 6 7
// 5 4
// 4 8