#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int isPrime[100001];
    int nMax = 100000;

    for (int i = 2; i <= nMax; i++)
    {
        isPrime[i] = 1;
    }

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int i = 2; i * i <= nMax; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= nMax; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    for (int i = 0; i <= nMax; i++)
    {
        if (isPrime[i])
        {
            cout << i << endl;
        }
    }

    return 0;
}