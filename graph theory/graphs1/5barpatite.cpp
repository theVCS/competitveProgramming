#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[100];
vector<bool> vis(100);
vector<int> col(100);

bool dfs(int n, int c)
{
    vis[n] = true;
    col[n] = c;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            if (dfs(P, c ^ 1) == false)
            {
                return false;
            }
        }
        else
        {
            if (col[n] == col[P])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    if (dfs(1, 0))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    

    return 0;
}