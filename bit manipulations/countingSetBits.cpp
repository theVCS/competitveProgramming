#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, count;
    while (true)
    {
        cin>>n;
        count = 0;

        while (n)
        {
            if (n & 1)
            {
                count++;
            }
            n = n>>1;
        }
        cout<<"the no of ones are "<<count<<endl;
    }
    

    return 0;
}