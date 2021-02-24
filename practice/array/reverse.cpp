#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr)/sizeof(int);
    int fptr = 0;
    int bptr = len - 1;

    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

    while (fptr < bptr)
    {
        swap(arr[fptr], arr[bptr]);
        fptr++;
        bptr--;
    }
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";

    return 0;
}