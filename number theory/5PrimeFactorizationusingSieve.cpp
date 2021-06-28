#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxN 1000001
int sieve[maxN];

void sieveFactors()
{
    for (int i = 2; i < maxN; i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j < maxN; j += i)
            {
                if (!sieve[j])
                {
                    sieve[j] = i;
                }
            }
        }
    }
}

void factor(int _number)
{
    while (sieve[_number])
    {
        cout << sieve[_number] << "*";
        _number = _number / sieve[_number];
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieveFactors();
    factor(10);

    return 0;
}