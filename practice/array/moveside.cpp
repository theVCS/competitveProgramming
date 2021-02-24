#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = {15, -25, 36, 59, 45, -91, 100, -56, -48};
    int ptr = 0, len = sizeof(arr)/sizeof(int);

    REP(i, 0, len)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[ptr]);
            ptr++;
        }
        
    }

    REP(i, 0, len)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}