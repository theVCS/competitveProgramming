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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int t[1000001];

bool recur(ll a, ll b)
{
    if (a == b)
    {
        return t[a] = true;
    }
    else if (a > b)
    {
        return false;
    }
    if (t[a] != -1)
    {
        return t[a];
    }
    else
    {
        return t[a] = recur(2 * a, b) || recur(10 * a + 1, b);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(t, -1, sizeof(t));

    ll a, b, temp;

    cin >> a >> b;

    temp = a;

    if (recur(a, b))
    {
        cout << "YES" << endl;

        while (true)
        {
            cout << temp << " ";

            if (temp == b)
            {
                break;
            }

            if (t[temp * 2])
            {
                temp *= 2;
            }
            else
            {
                temp = 10 * temp + 1;
            }
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}