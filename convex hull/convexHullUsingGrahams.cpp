#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

struct point
{
    ll x, y, z;
    int index;

    point(long long tmp_x = 0, long long tmp_y = 0, long long tmp_z = 0)
    {
        x = tmp_x;
        y = tmp_y;
        z = tmp_z;
    }

    point operator+(point b)
    {
        return point(this->x + b.x, this->y + b.y, this->z + b.z);
    }

    point operator-(point b)
    {
        return point(this->x - b.x, this->y - b.y, this->z - b.z);
    }

    point operator*(long long val)
    {
        return point(this->x * val, this->y * val, this->z * val);
    }

    point operator/(long long val)
    {
        return point(this->x / val, this->y / val, this->z / val);
    }

    point &operator=(point b)
    {
        this->x = b.x;
        this->y = b.y;
        this->z = b.z;
        return *this;
    }

    point &operator+=(point b)
    {
        *this = *this + b;
        return *this;
    }

    point &operator-=(point b)
    {
        *this = *this - b;
        return *this;
    }

    point &operator*=(long long val)
    {
        (*this) = (*this) * val;
        return *this;
    }

    point &operator/=(long long val)
    {
        (*this) = (*this) / val;
        return *this;
    }

    bool operator==(point b)
    {
        if (this->x == b.x && this->y == b.y && this->z == b.z)
            return true;
        else
            return false;
    }
};
vector<point> points;

ll dot(point a, point b)
{
    ll ans = a.x * b.x + a.y * b.y + a.z * b.z;
    return ans;
}

point cross(point a, point b)
{
    point e;
    e.x = a.y * b.z - b.y * a.z;
    e.y = a.z * b.x - b.z * a.x;
    e.z = a.x * b.y - b.x * a.y;
    return e;
}

double magnitude(point a)
{
    return sqrt(dot(a, a));
}

double ang(point a, point b)
{
    return acos(dot(a, b) / (magnitude(a) * magnitude(b)));
}

double rad_to_deg(double val)
{
    return val * 180 / pi;
}

double deg_to_rad(double val)
{
    return val * pi / 180;
}

int direction(point pivot, point a, point b)
{
    long long t = cross((a - pivot), (b - pivot)).z;

    // t > 0, a x b is anti clockwise
    // t < 0, a x b is clockwise
    // t == 0, a and b are collinear

    return t;
}

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
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

int n;
vector<point> convHull;
point p;

bool cmp(point a, point b)
{
    ll z = direction(p, a, b);

    if (z == 0)
        return magnitude(a - p) < magnitude(b - p);
    else
        return z > 0;
}

point secondTop(stack<point> &st)
{
    point t = st.top();
    st.pop();
    point p = st.top();
    st.push(t);
    return p;
}

void conHull()
{
    convHull.clear();
    int n = points.size();
    int ptr = 0;

    REP(i, 0, n - 1)
    {
        if (points[i].y < points[ptr].y || (points[i].y == points[ptr].y && points[i].x < points[ptr].x))
            ptr = i;
    }

    p = points[ptr];
    swap(points[ptr], points[0]);
    sort(all(points), cmp);


    stack<point> st;
    st.push(points[0]);
    st.push(points[1]);

    REP(i, 2, n - 1)
    {
        while (st.size() > 1 && direction(secondTop(st), st.top(), points[i]) <= 0)
        {
            st.pop();
        }

        st.push(points[i]);
    }

    vector<pii> res;
    cout << st.size() << endl;
    while (!st.empty())
    {
        res.push_back({st.top().x, st.top().y});
        st.pop();
    }

    RREP(i, res.size() - 1, 0)
    {
        cout << res[i].first << " " << res[i].second << endl;
    }
}

void solve()
{
    while (true)
    {
        cin >> n;

        if (n == 0)
            return;

        int x, y;

        map<int, set<int>> mp;

        REP(i, 1, n)
        {
            cin >> x >> y;
            mp[x].insert(y);
        }

        points.clear();

        for (auto e : mp)
        {
            for (int y : e.second)
                points.push_back(point(e.first, y));
        }

        if (points.size() > 2)
        {
            conHull();
        }
        else
        {
            cout << points.size() << endl;

            for (point p : points)
            {
                cout << p.x << " " << p.y << endl;
            }
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