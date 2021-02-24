#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int eulerTot(int n)
{
    int res = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res *= i - 1;
            res /= i;

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        res *= n - 1;
        res /= n;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<eulerTot(n)<<endl;
    }
    

    return 0;
}