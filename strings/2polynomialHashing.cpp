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

ll getHash(string s)
{
    ll value = 0;

    ll p = 103;
    ll power = 1;

    // some points about p
    // p > size of the character set and p is prime
    // for example if we use only small case letter then we just need to take p > 26
    // if we use both upper case and lower case letter then p > 52

    for (int i = 0; i < s.size(); i++)
    {
        value = (value + (s[i] - 'a' + 1) * power) % mod;
        power = (power * p) % mod;
    }
    return value;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    while (true)
    {
        getline(cin, s);
        cout << getHash(s) << endl;
    }

    return 0;
}