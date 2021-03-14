#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<int> arr[maxN], trans[maxN], order, SS;
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node)
{
    vis[node] = true;

    for (int child : trans[node])
    {
        if (!vis[child])
        {
            dfs1(child);
        }
    }
    SS.push_back(node);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, a, b;

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < maxN; i++)
        {
            arr[i].clear();
            trans[i].clear();
            vis[i] = false;
        }
        order.clear();

        cin >> n >> m;

        while (m--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            trans[b].push_back(a);
        }

        for (int i = 1; i <= maxN; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }

        memset(vis, false, maxN);

        for (int i = n - 1; i > -1; i--)
        {

            if (!vis[order[i]])
            {
                SS.clear();

                dfs1(order[i]);

                for (int child : SS)
                {
                    cout << child << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
// 451
// 7 8
// 1 2
// 2 3
// 3 1
// 4 3
// 7 4
// 7 5
// 5 6
// 6 7