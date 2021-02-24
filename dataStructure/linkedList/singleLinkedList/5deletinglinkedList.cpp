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
private:
    Node *head;
    int length;

public:
    List()
    {
        head = NULL;
        length = 0;
    }

    void push(int data)
    {
        Node *n = new Node();

        n->data = data;
        n->next = head;

        head = n;

        length++;
    }

    void deleteList()
    {
        Node *temp = head, *prev = NULL;

        while (temp)
        {
            prev = temp;
            temp = temp->next;
            delete prev;
        }
        length = 0;
        head = NULL;
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

    int size()
    {
        return length;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List lst;

    lst.push(15);
    lst.push(105);
    lst.push(115);
    lst.push(151);
    lst.push(1235);

    lst.printList();

    cout << lst.size() << endl;

    lst.deleteList();

    lst.printList();

    cout << lst.size();

    return 0;
}