#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *next;
};
class List
{
private:
    Node *head;
    int n;

public:
    List() { head = new Node, *head = {0, NULL}, n = 0; }
    void push_front(int key)
    {
        Node *t = new Node{key, head->next};
        head->next = t;
        n++;
    }
    void push_back(int key)
    {
        for (Node *p = head;; p = p->next)
            if (p->next == NULL)
            {
                Node *t = new Node{key, p->next};
                p->next = t;
                n++;
                break;
            }
    }
    void insert(int pos, int key)
    {
        for (Node *p = head->next; p; p = p->next)
            if (p->key == pos)
            {
                Node *t = new Node{key, p->next};
                p->next = t;
                n++;
                break;
            }
    }
    Node *search(int key)
    {
        for (Node *p = head->next; p; p = p->next)
            if (p->key == key)
                return p->next;
        return NULL;
    }
    // 删除第一个值为key的结点
    void erase(int key)
    {
        for (Node *p = head, *t; p->next; p = p->next)
            if (p->next->key == key)
            {
                t = p->next;
                p->next = p->next->next;
                n--;
                delete t;
                break;
            }
    }
    void print()
    {
        for (Node *p = head->next; p; p = p->next)
            printf("%d ", p->key);
    }
    int size() { return n; }
};
List A;
int main()
{
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.erase(3);
    A.insert(2, 4);
    A.print();
    cout << "\nA.length = " << A.size() << endl;
    return 0;
}