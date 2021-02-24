#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, f = 1, i;

    while (true)
    {
        a = 12;
        f = 1;
        cout<<"enter the bit to check"<<endl;
        cin>>i;

        if (i & 1)
        {
            cout<<"index entered is odd"<<endl;
        }
        else
        {
            cout<<"index entered is even"<<endl;
        }
        

        f = f<<i;

        a = a & f;

        if (a == f)
        {
            cout<<"set"<<endl;
        }
        else
        {
            cout<<"not set"<<endl;
        }
    }
    

    return 0;
}