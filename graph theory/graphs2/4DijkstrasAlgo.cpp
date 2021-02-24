#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pair<int, int>> arr[maxN];
vector<int> dist(maxN, INT_MAX);

void dijsktra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[node] = 0;
    q.push({0, node}); // first is distance and second is node

    while (!q.empty())
    {
        int dis = q.top().first;
        int curr = q.top().second;
        q.pop();

        for (pair<int, int> e : arr[curr])
        {
            if (dis + e.second < dist[e.first])
            {
                dist[e.first] = dist[curr] + e.second;
                q.push({dist[e.first], e.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, w;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> w;
        arr[a].push_back({b, w});
        arr[b].push_back({a, w});
    }

    dijsktra(1);

    REP(i, 1, n + 1)
        cout << dist[i] << " ";

    return 0;
}
// 6 9
// 1 2 4
// 1 6 2
// 2 6 1
// 2 3 5
// 6 3 8
// 3 5 3
// 6 5 10
// 3 4 6
// 5 4 5

// result
//0 3 8 14 11 2