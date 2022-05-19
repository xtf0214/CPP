#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int key;
    Node *prev, *next;
};
class Deque
{
private:
    Node *head, *tail;

public:
    Deque()
    {
        head = new Node, tail = new Node;
        *head = {0, NULL, tail};
        *tail = {0, head, NULL};
    }
    void push(int key)
    {
        Node *p = new Node;
        p->key = key;
        p->prev = tail->prev;
        tail->prev->next = p;
        tail->prev = p;
        p->next = tail;
    }
    void pop()
    {
        delete head->next;
        head->next->next->prev = head;
        head->next = head->next->next;
    }
    void print()
    {
        for (Node *p = head->next; p != tail; p = p->next)
            cout << p->key << " ";
        cout << endl;
    }
    Node *front() { return head->next; }
    Node *back() { return tail->prev; }
    bool empty() { return head->next == tail ? true : false; }
};
int main()
{
    Deque que;
    while (true)
    {
        string com;
        char key[10];
        cin >> com >> key;
        if (com == "push")
            que.push(atoi(key));
        else if (com == "pop")
            que.pop();
        else if (com == "print")
            que.print();
        else if (com == "front")
            cout << que.front()->key << endl;
        else if (com == "back")
            cout << que.back()->key << endl;
        else if (com == "empty")
            cout << (que.empty() ? "Yes" : "No");
    }
}