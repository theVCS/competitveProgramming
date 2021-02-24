#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int m, n;
bool vis[maxN][maxN];
int arr[maxN][maxN];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n)
    {
        return false;
    }

    if (vis[x][y])
    {
        return false;
    }

    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    cout << arr[x][y] << " ";

    REP(i, 0, 4)
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

    cin >> m >> n;

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> arr[i][j];
        }
    }

    dfs(1, 1);

    return 0;
}