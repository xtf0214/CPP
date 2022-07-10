#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int s;
} a[4];
int main()
{
    for (int i = 0; i < 4; i++)
        a[i].s = i;
    Node *b[4];
    for (int i = 0; i < 4; i++)
        b[i] = &a[i];
        
    // 匿名函数，函数指针
    bool (*cmp)(Node * x, Node * y) = [](Node *x, Node *y) -> bool
    { return x->s > y->s; };

    // 匿名函数，auto
    auto comp = [](Node *x, Node *y) -> bool
    { return x->s > y->s; };

    sort(b, b + 4, cmp);
    // 匿名函数
    sort(b, b + 4, [](Node *x, Node *y) -> bool
         { return x->s > y->s; });
    for (int i = 0; i < 4; i++)
        cout << b[i]->s << " ";
    return 0;
}