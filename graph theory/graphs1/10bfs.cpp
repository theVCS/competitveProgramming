#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

vector<int> arr[101];
bool vis[101];

void bfs(int src)
{
    queue<int> q;
    vis[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr;
        q.pop();

        for (int child : arr[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = vis;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    return 0;
}