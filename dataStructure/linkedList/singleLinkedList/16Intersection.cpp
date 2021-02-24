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
    int length;
    Node *head, *end;

public:
    List()
    {
        length = 0;
        head = end = NULL;
    }

    void push(int data)
    {
        Node *n = new Node(data);

        if(head == NULL)
        {
            head = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

        length++;
    }

    void printList(Node *head)
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }

    Node *findIntersection(Node *head1, Node *head2)
    {
        List result;

        while (head1 && head2)
        {
            if (head1->data == head2->data)
            {
                result.push(head1->data);
                head1 = head1->next;
                head2 = head2->next;
            }
            else if (head1->data > head2->data)
            {
                while (head1->data > head2->data)
                {
                    head2 = head2->next;
                }
            }
            else
            {
                while (head1->data < head2->data)
                {
                    head1 = head1->next;
                }
            }
        }

        return result.getHead();
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List obj1, obj2;

    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    obj1.push(6);

    obj2.push(2);
    obj2.push(4);
    obj2.push(6);
    obj2.push(8);

    obj1.printList(obj1.getHead());
    obj2.printList(obj2.getHead());

    Node *res = obj1.findIntersection(obj1.getHead(), obj2.getHead());
    obj1.printList(res);

    return 0;
}