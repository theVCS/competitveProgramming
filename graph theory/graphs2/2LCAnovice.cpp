//Technique:: here we find the level of the two nodes and lift the node at greater depth at the same level of other and then lift both the nodes untill we get the same parent

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int dist[maxN];
int parent[maxN];

void dfs(int node, int dis = 0, int par = -1)
{
    vis[node] = true;
    dist[node] = dis;
    parent[node] = par;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, dis + 1, node);
        }
    }
}

int LCA(int a, int b)
{
    if (dist[a] < dist[b])
    {
        swap(a, b);
    }

    int d = dist[a] - dist[b];

    while (d--)
    {
        a = parent[a];
    }

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, root = 1;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(2);

    while (true)
    {
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}