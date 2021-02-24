#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a)
{
    if (a == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (isPrime(71))
    {
        cout << "the number is a Prime Number";
    }
    else
    {
        cout << "the number is not a Prime Number";
    }

    return 0;
}