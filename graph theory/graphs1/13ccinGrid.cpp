#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int m, n;
int arr[101][101];
bool vis[101][101];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n)
    {
        return false;
    }

    if (vis[x][y] || arr[x][y] == 0)
    {
        return false;
    }
    return true;
}

void dfs(int x = 1, int y = 1)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cc = 0;

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j] && arr[i][j] != 0)
            {
                dfs(i, j);
                cc++;
            }
        }
    }

    cout << cc;

    return 0;
}