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

class Node
{
public:
    int data;
    Node *next;
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void push(int data)
    {
        Node *n = new Node();

        n->data = data;
        n->next = head;

        head = n;
    }

    void printList()
    {
        Node *n = head;

        while (n)
        {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    void del(int key)
    {
        Node *temp = head;
        Node *prev = NULL;

        if (temp && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List obj;

    obj.push(15);
    obj.push(105);
    obj.push(1515);
    obj.push(1505);
    obj.push(215);
    obj.push(1);
    obj.printList();

    obj.del(105);
    obj.printList();

    return 0;
}