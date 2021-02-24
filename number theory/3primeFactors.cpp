#include <bits/stdc++.h>
using namespace std;
#define ll long long int

template <class T>
void primefactors(T num)
{
    for (T i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            int cnt = 0;

            while (num % i == 0)
            {
                cnt++;
                num /= i;
            }
            cout << i << "^" << cnt << endl;
        }
    }
    if (num > 1)
    {
        cout << num << "^" << 1;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 7*7*7*13*23*23;
    primefactors(n);

    return 0;
}