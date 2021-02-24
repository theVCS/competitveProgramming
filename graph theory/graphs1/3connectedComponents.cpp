#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
bool vis[10];
vector<int> arr[10];
void dfs(int v)
{
    vis[v] = true;

    for (int P : arr[v])
    {
        if (!vis[P])
        {
            dfs(P);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, cc = 0;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            cc++;
        }
    }

    cout << "# of connected components are " << cc;

    return 0;
}