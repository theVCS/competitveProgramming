#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[101];
vector<bool> vis(101, false);
vector<int> intime(101);
vector<int> outime(101);
int timer = 1;

void dfs(int n)
{
    vis[n] = true;
    intime[n] = timer++;

    for (int c : arr[n])
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }
    outime[n] = timer++;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, t;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    cin >> t;

    while (t--)
    {
        cin >> a >> b;

        if ((intime[a] < intime[b]) && (outime[a] > outime[b]))
        {
            cout << b << " lies on " << a;
        }
        else
        {
            cout << b << " doen't lie lies on " << a;
        }
    }

    return 0;
}