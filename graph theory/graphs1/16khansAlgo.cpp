#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[101];
bool vis[101];
int indegree[101];
vector<int> res;

void kahn(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for (int node : arr[curr])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }
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
        indegree[b]++;
    }

    kahn(n);

    for (int p : res)
    {
        cout << p << " ";
    }

    return 0;
}