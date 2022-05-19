#include <iostream>
#include <vector>
using namespace std;
vector<int> A(1);
void search(int i)
{
    bool flag = false;
    for (; i < A.size(); i++)
        if (A[i] % (i + 1) == 0)
        {
            A.erase(A.begin() + i);
            flag = true;
            break;
        }
    if (!flag)
    {
        for (int i = 1; i < A.size(); i++)
            cout << A[i] << " ";
        return;
    }
    search(i);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout<<A.size();
    search(1);
}