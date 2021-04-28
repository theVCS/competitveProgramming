#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 500001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n;

struct order
{
    int l, r;
} arr[maxN];

bool cmp(order a, order b)
{
    if (a.l == b.l)
        return a.r < b.r;
    return (a.l < b.l);
}

int bs(int index)
{
    int val = arr[index].r;

    int start = 1, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].l > val && arr[mid - 1].l <= val)
        {
            return mid;
        }
        else if (arr[mid].l <= val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int dp[maxN];

int fun(int index = 1)
{
    if (index == n + 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int nxt = bs(index);

    if (nxt == -1)
        return dp[index] = max(1, fun(index + 1));

    // selecting index
    return dp[index] = max(1 + fun(nxt), fun(index + 1));
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i].l >> arr[i].r;

    sort(arr + 1, arr + 1 + n, cmp);

    memset(dp, -1, sizeof(dp));

    cout << fun();
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