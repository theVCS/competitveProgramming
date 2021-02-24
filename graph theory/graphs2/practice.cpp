#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, capacity[maxN][maxN], src, sink;
vector<int> arr[maxN];

int bfs(vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[src] = -2;
    queue<pii> q;
    q.push({src, INT_MAX});

    while (!q.empty())
    {
        int curr = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int child : arr[curr])
        {
            if (capacity[curr][child] && parent[child] == -1)
            {
                parent[child] = curr;
                int newF = min(flow, capacity[curr][child]);

                if (child == sink)
                {
                    return newF;
                }
                q.push({child, newF});
            }
        }
    }
    return 0;
}

int maxFlow()
{
    int flow = 0, newFlow;
    vector<int> parent(n + 1);

    while (newFlow = bfs(parent))
    {
        flow += newFlow;

        int cur = sink;

        while (cur != src)
        {
            int pre = parent[cur];
            capacity[pre][cur] -= newFlow;
            capacity[cur][pre] += newFlow;
            cur = pre;
        }
    }
    return flow;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, a, b, c;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> c;
        arr[a].push_back(b), arr[b].push_back(a), capacity[a][b] = c;
    }

    cin >> src >> sink;

    cout << maxFlow();

    return 0;
}