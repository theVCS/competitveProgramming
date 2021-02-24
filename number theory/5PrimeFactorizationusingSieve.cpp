#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000001
int sieve[max];

void sieveFactors()
{
    for (int i = 2; i < max; i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j < max; j += i)
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