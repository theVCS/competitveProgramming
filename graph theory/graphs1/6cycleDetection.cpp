#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[101];
vector<bool> vis(101, false);

bool dfs(int n, int parent)
{
    vis[n] = true;

    for (int c : arr[n])
    {
        if (!vis[n])
        {
            if (dfs(c, n) == true)
            {
                return true;
            }
        }
        else
        {
            if (c != parent)
            {
                return true;
            }
        }
    }

    return false;
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

    if (dfs(1, 0))
    {
        cout << "contains cycle";
    }
    else
    {
        cout << "contains no cycle";
    }

    return 0;
}