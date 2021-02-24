#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, capacity[maxN][maxN], source, sink;
vector<int> arr[maxN];

int bfs(vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

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
    vector<int> parent(n + 1);
    int currF;
    int maxF = 0;

    while (currF = bfs(parent)) // bfs finds the parents in an augmentation path and sends the minimum of the flows in that path untill the capacity of one of the pipes reaches its limit
    {
        maxF += currF;

        int curr = sink;

        while (curr != source)
        {
            int prev = parent[curr];
            capacity[prev][curr] -= currF;  // decreases residual capacity in forward edge
            capacity[curr][prev] += currF;  // increases residual capacity in backward edge
            curr = prev;
        }
    }
    return maxF;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, a, b, cap;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> cap;
        arr[a].push_back(b);
        capacity[a][b] = cap;
    }

    cin >> source >> sink;

    cout << maxFlow();

    return 0;
}

// 6 9
// 1 2 7
// 1 6 4
// 2 3 5
// 2 5 3
// 3 4 8
// 5 2 3
// 5 4 5
// 1 5 3
// 6 2 3
// 1 4