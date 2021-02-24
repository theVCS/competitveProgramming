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

class Stack
{
private:
    Node *head;
    int length;

public:
    Stack()
    {
        head = NULL;
        length = 0;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        n->next = head;

        head = n;
        length++;
    }

    void pop()
    {
        Node *temp = head;

        if (temp)
        {
            head = temp->next;
            delete temp;
            length--;
        }
    }

    int top()
    {
        return head->data;
    }

    bool empty()
    {
        return (length == 0);
    }

    int size()
    {
        return length;
    }

    void swap(Stack st)
    {
        Node *temp = head, *prev = NULL;
        
        //freeding memory
        while (temp)
        {
            prev = temp;
            temp = temp->next;
            delete prev;
        }
        
        head = st.head;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    return 0;
}