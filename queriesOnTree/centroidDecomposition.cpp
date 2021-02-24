#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

set<int> arr[maxN];
int parent[maxN];
int subSize[maxN];
int res[maxN];
int dp[maxN][17];
int level[maxN];

// decomposition part

int dfs(int node, int par)
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

int centCal(int node, int par, int n)
{
    for (int child : arr[node])
    {
        if (child == par)
            continue;

        if (subSize[child] > n / 2)
            return centCal(child, node, n);
    }

    return node;
}

void decompose(int node, int par)
{
    int size = dfs(node, par);
    int centroid = centCal(node, par, size);

    parent[centroid] = par;

    for (int adj : arr[centroid])
    {
        arr[adj].erase(centroid), decompose(adj, centroid);
    }
}

// preprocessing part
void dfs0(int node, int par = -1, int l = 0)
{
    dp[node][0] = par;
    level[node] = l;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node, l + 1);
    }
}

void init(int n)
{
    dfs0(1);

    for (int j = 1; j < 17; j++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (dp[i][j - 1] == -1)
            {
                dp[i][j] = -1;
            }
            else
            {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = dp[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 16; i >= 0; i--)
    {
        if (dp[a][i] != -1 && dp[a][i] != dp[b][i])
            a = dp[a][i], b = dp[b][i];
    }

    return dp[a][0];
}

int dist(int a, int b)
{
    return (level[a] + level[b] - 2 * level[LCA(a, b)]);
}

void update(int node)
{
    int curr = node;

    while (curr != -1)
    {
        res[curr] = min(res[curr], dist(curr, node));
        curr = parent[curr];
    }
}

int query(int node)
{
    int curr = node;
    int ans = 1e9;

    while (curr != -1)
    {
        ans = min(ans, res[curr] + dist(curr, node));
        curr = parent[curr];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, m;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].insert(b), arr[b].insert(a);
    }

    memset(res, INT_MAX, maxN);

    init(n);

    decompose(1, -1);

    REP(i, 1, n + 1)
    cout << "Parent[" << i << "] = " << parent[i] << endl;

    return 0;
}

// Properties ------
//1. centroid tree have all the vertices as the given tree. 
//2.the height of the centroid tree is atmost log(N)
//3.let us consider two arbitrary vertices a, b and the path between them can be broken down into A-->C and C-->B where C is lca of A, B in centroid tree
//4. lca of two nodes a, b in centroid tree is that node which was first removed and made a centroid and which made a, b disconnected like:
                        //     c        <----- lca and was removed before and made centroid which made
                        //    / \               a, b disconnected
                        //   /   \
                        //  a     b
//5. 