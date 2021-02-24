#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int power(int a, int m, int p)
{
    int res = 1;

    while (m)
    {
        if (m % 2)
        {
            res = ((res % p) * (a % p)) % p;
            m--;
        }

        a = ((a % p) * (a % p)) % p;
        m /= 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, m;
    cin >> t;

    while (t--)
    {
        cin >> a >> m;
        cout << power(a, m - 2, m) << endl;
    }

    return 0;
}