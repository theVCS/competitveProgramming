#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
// #define endl "\n"
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

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        power >>= 1;
    }
    return res;
}

const int sz = 26;

struct Node
{
    int cnt;
    Node *arr[sz];
    bool flag;

    Node()
    {
        cnt = 0, flag = false;

        for (int i = 0; i < sz; i++)
        {
            arr[i] = NULL;
        }
    }
};

class Trie
{
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string &word)
    {
        Node *temp = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (temp->arr[index] == NULL)
                temp->arr[index] = new Node();
            temp->cnt++;
            temp = temp->arr[index];
        }

        temp->cnt++;
        temp->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string &word)
    {
        Node *temp = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (temp->arr[index] == NULL || temp->cnt == 0)
                return false;
            temp = temp->arr[index];
        }

        return temp->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix)
    {
        Node *temp = root;

        for (char c : prefix)
        {
            int index = c - 'a';
            if (temp->arr[index] == NULL || temp->cnt == 0)
                return false;
            temp = temp->arr[index];
        }

        return (temp->cnt > 0);
    }

    /** delete a word from trie */
    void del(string &s)
    {
        if (search(s) == false)
            return;

        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';
            temp->cnt--;
            temp = temp->arr[index];
        }

        temp->cnt--;
        temp->flag = false;
    }

    // bool isLast()

    void printSuggestions(Node *node, string s)
    {
        if(node->flag)
        {
            cout<<s<<endl;
        }

        for (int i = 0; i < sz; i++)
        {
            if(node->arr[i])
            {
                s.push_back('a'+i);
                printSuggestions(node->arr[i], s);
                s.pop_back();
            }
        }
        
    }

    void autoComplete(string &s)
    {
        Node *temp = root;

        for(char c: s)
        {
            int index = c - 'a';
            if(temp->arr[index]==NULL||temp->cnt==0)return;
            temp = temp->arr[index];
        }

        printSuggestions(temp,s);
    }
};

void solve()
{
    Trie obj;

    while (true)
    {
        int code;
        string s;
    
        cin >> code >> s;

        if(code == 1)
            obj.insert(s);
        else obj.autoComplete(s);
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