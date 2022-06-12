#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[10000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int count = 0;
    for (int j = 2; j < n; j++)
    {
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            if (arr[right] + arr[left] > arr[j])
                right--;
            else if (arr[right] + arr[left] < arr[j])
                left++;
            else
            {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
