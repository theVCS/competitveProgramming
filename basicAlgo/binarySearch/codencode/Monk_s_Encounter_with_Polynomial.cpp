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
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll a, b, c, k;

ll f(ll x)
{
    return (a * x * x + b * x + c);
}

ll binSearch()
{
    if(c >= k)return 0;

    ll start = 1;
    ll end = ceil(sqrt(k));

    while (start <=  end)
    {
        ll mid=(start+end)/2;
        ll f1 = f(mid);
        ll f2 = f(mid - 1);

        if(f1 >= k && f2 < k)return mid;

        if(f1 < k)start = mid + 1;
        else end = mid - 1;
    }
}

void solve()
{
    cin >> a >> b >> c >> k;
    cout << binSearch() << endl;
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