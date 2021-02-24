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
    cout << v << " ";

    for (int P : arr[v])
    {
        if (vis[P] == false)
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

    int n, m, a, b;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(2);

    return 0;
}