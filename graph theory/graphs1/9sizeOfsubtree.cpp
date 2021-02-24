#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[101];
vector<bool> vis(101, false);
vector<int> subSize(101);

int dfs(int n)
{
    int cnt = 1;
    vis[n] = true;

    for (int c : arr[n])
    {
        if (!vis[c])
        {
            cnt += dfs(c);
        }
    }

    subSize[n] = cnt;
    return cnt;
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

    cout << dfs(1) << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << subSize[i] << " ";
    }

    return 0;
}
