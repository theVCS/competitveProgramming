#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int,int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define INF 0x3f3f3f3f
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

struct ele
{
    int ele, index;
}arr[maxN];
    
int cost[maxN];

void solve()
{
    int n;

    cin >> n;

    REP(i,0,n)
    {
        cin >> arr[i].ele;
        arr[i].index = i;
    }

    sort(arr,arr+n);

    ll k;
    cin >> k;
    k %= n;

    // all the elements are permutation of (1 - n)
    // calculating cost as : (real position after sorting - position before sorting + n) % n
    REP(i,0,n)
    {
        cost[(i - arr[i].index + n) % n]++;
    }

    cout << cost[k] << endl;
}
    
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // ifstream fi("input.txt");
    // ofstream fo("output.txt");
    
    // fi >> input;
    // fo << output;
    
    int t = 1;
    
    //cin >> t;
    
    while (t--)
    {
        solve();
    }
    
    //fi.close();
    //fo.close();
    
    return 0;
}