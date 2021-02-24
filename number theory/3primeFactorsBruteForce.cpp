#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n = 1000000007;

    for (ll i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }

    return 0;
}

// here the time complexity is of order of n (O(n)) when n is a prime number