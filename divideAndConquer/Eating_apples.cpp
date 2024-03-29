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
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
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
map<int, int> mp;
struct cor
{
    int x, y, index;
} arr[100001];
int res[100001];

bool cmp(cor a, cor b)
{
    if (a.x == b.x)
    {
        if (mp[a.x])
        {
            return a.y > b.y;
        }
        else
        {
            return a.y < b.y;
        }
    }

    return a.x < b.x;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i].x >> arr[i].y;
        mp[arr[i].x];
        arr[i].index = i;
    }

    int flag = 0;

    for (auto &e : mp)
    {
        e.second = flag;
        flag ^= 1;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    REP(i, 1, n)
    {
        res[arr[i].index] = i - 1;
    }

    REP(i,1,n)cout<<res[i]<<endl;
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