#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define maxN 1000001
#define REP(i, a, b) for (int i = a; i < b; i++)

int phi[1000001];

void sieve()
{
    for (int i = 1; i < maxN; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i < maxN; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<phi[n]<<endl;
    }
    
    return 0;
}