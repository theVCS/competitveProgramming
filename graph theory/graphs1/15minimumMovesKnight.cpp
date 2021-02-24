#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool vis[9][9];
int dist[9][9];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8 || vis[x][y])
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
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                q.push({x + dx[i], y + dy[i]});
                dist[x + dx[i]][y + dy[i]] = 1 + dist[x][y];
                vis[x + dx[i]][y + dy[i]] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, sx, sy, ex, ey;
    char c;

    cin >> t;

    while (t--)
    {
        cin >> c;
        sx = c - 'a' + 1;
        cin >> sy;

        cin >> c;
        ex = c - 'a' + 1;
        cin >> ey;

        bfs(sx, sy);

        cout << dist[ex][ey] << endl;

        REP(i, 0, 9)
        REP(j, 0, 9)
        vis[i][j] = false;
    }

    return 0;
}