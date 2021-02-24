#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[101];
int timer, low[101], intime[101];
bool vis[101];

void dfs(int node, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = timer++;
    int children = 0;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);

            if (low[child] >= intime[node] && par != -1)
            {
                cout << node << " is a articulation point " << endl;
            }
            children++;
        }
    }

    if (par == -1 && children > 1)
    {
        cout << node << " is a articulation point " << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b;

    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    return 0;
}