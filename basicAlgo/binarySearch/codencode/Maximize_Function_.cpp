#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];

ll S(ll Y, int n)
{
    ll s = 0;

    REP(i, 1, n + 1)
    s += max(0LL, arr[i] - Y * i);

    return s;
}

void solve()
{
    int n;
    ll k, maxV = 0;

    cin >> n >> k;

    REP(i, 1, n + 1)
        cin >> arr[i],
        maxV = max(maxV, arr[i]);

    ll start = 0, end = maxV;
    
    while (start <= end)
    {
        int mid = (start + end) / 2;

        ll f1 = S(mid, n);
        ll f2 = S(mid + 1, n);

        if (f1 >= k && f2 < k)
        {
            cout << mid << " " << f1 << endl;
            return;
        }

        if (f1 >= k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}