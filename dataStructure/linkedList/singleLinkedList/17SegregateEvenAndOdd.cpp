#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class List
{
private:
    Node *head;
    Node *end;
    int length;

public:
    List()
    {
        head = end = NULL;
        length = 0;
    }

    void append(int data)
    {
        Node *n = new Node(data);

        if (head == NULL)
        {
            head = end = n;
            length++;
            return;
        }

        end->next = n;
        end = n;
        length++;
    }

    Node *getHead()
    {
        return head;
    }

    int size()
    {
        return length;
    }

    void segregate()
    {
        List even, odd;
        Node *temp = head;

        while (temp)
        {
            if (temp->data % 2)
                odd.append(temp->data);
            else
                even.append(temp->data);

            temp = temp->next;
        }

        if (even.size() == 0)
        {
            head = odd.getHead();
        }
        else
        {
            even.end ->next = odd.head;
            head = even.getHead();
        }
    }

    void printList()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, dum;

    cin >> t;

    while (t--)
    {
        List obj;
        cin >> n;

        while (n--)
        {
            cin >> dum;
            obj.append(dum);
        }
        
        obj.segregate();

        obj.printList();
    }
    

    return 0;
}