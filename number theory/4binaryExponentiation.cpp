#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll powerCal(ll _base, ll _power)
{
    ll res = 1;

    while (_power)
    {
        if (_power)
        {
            res *= _base;
            _power--;
        }
        _base *= _base;
        _power /= 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<powerCal(125, 10);

    return 0;
}