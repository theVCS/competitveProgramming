#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct indices
{
    int ara, arb;
} index[maxN];

int leftShift[maxN], rightShift[maxN];

void solve()
{
    int n, dum;

    cin >> n;

    REP(i, 0, n)
    cin >> dum,
        index[dum].ara = i;
    REP(i, 0, n)
    cin >> dum,
        index[dum].arb = i;

    int res = 0;

    REP(i, 1, n + 1)
    {
        res = max(res, ++rightShift[(index[i].ara - index[i].arb + n) % n]);
        res = max(res, ++leftShift[(index[i].arb - index[i].ara + n) % n]);
    }

    cout << res;
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