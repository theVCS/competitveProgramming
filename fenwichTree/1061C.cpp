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

int sieve[1000001];
int arr[maxN];
int n;
vector<int> fac[1000001];

void init()
{
    for (int i = 2; i < 1000001; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j < 1000001; j += i)
            {
                if (sieve[j] == 0)
                    sieve[j] = i;
            }
        }
    }
}

void init2(int index)
{
    int ele = arr[index];
    map<int, int> mp;

    while (sieve[ele])
    {
        mp[sieve[ele]]++;
        ele /= sieve[ele];
    }

    for (auto e : mp)
    {
        fac[e.first].push_back(index);
    }
}

ll fun(int pos = -1)
{
    
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        init2(i);
        fac[1].push_back(i);
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

    //cin >> t;
    init();

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}