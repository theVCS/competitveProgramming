#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

struct point
{
    ll x, y;
    int index;
};
int n;
vector<point> points;
vector<point> convHull;

ll cross(point pivot, point a, point b)
{
    // x1*y2 - y1*x2
    a.x -= pivot.x;
    a.y -= pivot.y;

    b.x -= pivot.x;
    b.y -= pivot.y;

    ll z = (a.x * b.y - a.y * b.x);

    return z;
}

ll dot(point a, point b)
{
    a.x -= b.x;
    a.y -= b.y;

    return (a.x * a.x + a.y * a.y);
}

bool compare(point a, point b)
{
    return (a.x == b.x && a.y == b.y);
}

void convexHull()
{
    int pt = 0;

    REP(i, 0, n - 1)
    {
        if (points[pt].x > points[i].x || (points[pt].x == points[i].x && points[pt].y > points[i].y))
            pt = i;
    }

    convHull.push_back(points[pt]);

    while (true)
    {
        pt = 0;

        REP(i, 0, n - 1)
        {
            ll z = cross(convHull.back(), points[pt], points[i]);

            if (z < 0 || (z == 0 && dot(points[i], convHull.back()) > dot(points[pt], convHull.back())))
            {
                pt = i;
            }
        }

        if (compare(points[pt], convHull.front()))
            break;
        else
            convHull.push_back(points[pt]);
    }
}

bool cmp(point a, point b)
{
    return a.index < b.index;
}

void solve()
{
    while (true)
    {
        cin >> n;

        if(n == 0)return;

        ll x, y;

        points.clear();

        REP(i, 1, n)
        {
            cin >> x >> y;
            points.push_back({x, y, i});
        }

        convHull.clear();
        convexHull();
        // sort(all(convHull), cmp);
    

        cout<<convHull.size()<<endl;
    
        for (point p : convHull)
        {
            cout << p.x << " " << p.y << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}