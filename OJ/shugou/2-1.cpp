#include <iostream>
using namespace std;
class myVector
{

public:
    myVector() : size(0), length(0) {}
    int &operator[](int pos) { return arr[pos]; }
    int search(int e)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == e)
                return i;
        return size;
    }
    void insert(int pos, int e)
    {
        if (size == length)
            realloc_insert();
        for (int i = size; i >= pos; i--)
            arr[i + 1] = arr[i];
        arr[pos] = e;
        size++;
    }
    void push_back(int e)
    {
        if (size == length)
            realloc_insert();
        arr[size++] = e;
    }
    int erase(int pos)
    {
        int t = arr[pos];
        for (int i = pos; i < size; i++)
            arr[i] = arr[i + 1];
        size--;
    }
    int sizes() { return size; }

private:
    int *arr;
    int size, length;
    void realloc_insert()
    {
        int *t = arr + length;
        t = new int{0};
        length++;
    }
};
int main()
{
    // int *a = new int[10]{12, 10, 13, 14, 15, 20, 25, 26, 30, 56};
    // for (int i = 0; i < 10; i++)
    //     cout << a[i] << " ";
    int a[10]{12, 10, 13, 14, 15, 20, 25, 26, 30, 56};
    myVector arr;
    for (int i = 0; i < 10; i++)
        arr.push_back(a[i]);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}