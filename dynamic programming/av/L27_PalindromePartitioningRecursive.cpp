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

bool isPalindrome(string s, int sx, int ex)
{
    while (sx < ex)
    {
        if (s[sx] != s[ex])
        {
            return false;
        }
        sx++, ex--;
    }
    return true;
}

int palinPar(string s, int i, int j)
{
    if (i >= j || isPalindrome(s, i, j))
    {
        return 0;
    }
    else
    {
        int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int temp = palinPar(s, i, k) + palinPar(s, k + 1, j) + 1;
            ans = min(ans, temp);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;

    cout << palinPar(s, 0, s.size() - 1);

    return 0;
}