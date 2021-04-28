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
#define maxN 100001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a);
        a = (a * a);
        power >>= 1;
    }
    return res;
}

ll w[maxN];
int cnt[32];

void solve()
{
    int n;
    ll W;
    cin >> n >> W;

    REP(i, 1, n)
    {
        cin >> w[i];
        int pow = log2(w[i]);
        cnt[pow]++;
    }

    int hgt = 0;
    ll wth;

    while (true)
    {
        bool flag = true;
        wth = W;

        RREP(i, 31, 0)
        {
            if (cnt[i] == 0)
                continue;
            else
                flag = false;

            ll ele = binExp(2, i);

            if (wth - ele >= 0)
            {
                cnt[i]--;
                wth -= ele;
                i++;
            }
        }

        if (flag)
            break;

        hgt++;
    }

    cout << hgt << endl;
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