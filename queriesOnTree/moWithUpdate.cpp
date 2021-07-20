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

int n, m;
const int blk = 900;
ll arr[maxN], fre[maxN], last[maxN], nq, nu, res;
ll ans[maxN];
bool use[maxN];

struct Query
{
    int l, r, lblk, rblk, t, index;
} q[maxN];

struct Update
{
    int index, new_y, prev_y;
} u[maxN];

bool cmp(Query a, Query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.rblk < b.rblk) || (a.lblk == b.lblk && a.rblk == b.rblk && a.t < b.t);
}

void add(int index)
{
    int ele = arr[index];
    use[index] = true;

    if (++fre[ele] == 1)
        res++;
}

void remove(int index)
{
    int ele = arr[index];
    use[index] = false;

    if (--fre[ele] == 0)
        res--;
}

void reflect_update(int index, int ele)
{
    if (use[index] == false)
    {
        arr[index] = ele;
        return;
    }
    remove(index);
    arr[index] = ele;
    add(index);
}

void do_update(int index)
{
    reflect_update(u[index].index, u[index].new_y);
}

void undo(int index)
{
    reflect_update(u[index].index, u[index].prev_y);
}

void solve()
{
    int code, a, b;

    cin >> n >> m;

    REP(i, 1, n)
    {
        cin >> arr[i];
        last[i] = arr[i];
    }

    REP(i, 1, m)
    {
        cin >> code;

        // updation
        if (code == 1)
        {
            cin >> a >> b;
            u[nu].index = a;
            u[nu].new_y = b;
            u[nu].prev_y = last[a];
            last[a] = b;
            nu++;
        }
        // querying
        else
        {
            nq++;
            cin >> a >> b;
            q[nq].l = a;
            q[nq].r = b;
            q[nq].lblk = a / blk;
            q[nq].rblk = b / blk;
            q[nq].index = i;
            q[nq].t = nu;
        }
    }

    sort(q + 1, q + nq + 1, cmp);

    for (int i = 1, L = 2, R = 1, T = 0; i <= nq; i++)
    {
        while (T < q[i].t)
            do_update(++T);
        while (T > q[i].t)
            undo(T--);
        while (R < q[i].r)
            add(++R);
        while (L > q[i].l)
            add(--L);
        while (R > q[i].r)
            remove(R--);
        while (L < q[i].l)
            remove(L++);

        ans[q[i].index] = res;
    }

    REP(i, 1, nq)
    cout << ans[i] << " ";
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