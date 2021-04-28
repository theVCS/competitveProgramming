#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, k;
int arr[maxN];
ll ft[maxN][15];

ll query(int index, int lev)
{
    ll sum = 0;

    while (index)
    {
        sum = (sum + ft[index][lev]);
        index -= (index & -index);
    }

    return sum;
}

void update(int index, int lev, ll sum)
{
    while (index <= n)
    {
        ft[index][lev] = ft[index][lev] + sum;
        index += (index & -index);
    }
}

void solve()
{
    cin >> n >> k;
    k++;

    REP(i, 1, n + 1)
    cin >> arr[i];

    REP(i, 1, n + 1)
    {
        REP(lev, 1, k + 1)
        {
            ll p = lev == 1 ? 1 : query(arr[i] - 1, lev - 1);
            update(arr[i], lev, p);
        }
    }

    cout << query(n, k);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}