#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int m, n;
int arr[101][101], dist[101][101];
bool vis[101][101];

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

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    dist[x][y] = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                vis[newX][newY] = true;
                dist[newX][newY] = 1 + dist[x][y];
                q.push({newX, newY});
            }
        }
    }

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> m >> n;
    cin >> x >> y;
    bfs(x, y);

    return 0;
}