#include <iostream>
#include <algorithm>
using namespace std;
class Fruit
{
private:
    int size, id;

public:
    string _name;
    Fruit(string name, int size, int id) : _name(name), size(size), id(id) {}
    Fruit() {}
    bool operator<(const Fruit &T) const
    {
        if (size != T.size)
            return size < T.size;
        else
            return id < T.id;
    }
} fruit[25];
int main()
{
    string str;
    int n = 0;
    while (cin >> str && str != "#")
        fruit[n] = Fruit(str, str.size(), n++);
    sort(fruit, fruit + n);
    for (int i = 0; i < n; i++)
        cout << fruit[i]._name << " ";
    cout<<n;
    return 0;
}