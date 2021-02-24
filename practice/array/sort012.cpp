#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;

        int arr[n], low = 0, mid = 0, high = n - 1;
        REP(i, 0, n)
        {
            cin>>arr[i];
        }

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }

        }
        
        REP(i, 0, n)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}