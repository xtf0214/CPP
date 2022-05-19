#include <iostream>
using namespace std;
int main()
{
    int N[3];
    char S[3];
    for(int i = 0;i<3;i++)  cin>>N[i];
    for(int i = 0;i<3;i++)  cin>>S[i];
    if (N[0] > N[1])    swap(N[0], N[1]);
    if (N[1] > N[2])    swap(N[1], N[2]);
    if (N[0] > N[1])    swap(N[0], N[1]);
    for(int i = 0;i<3;i++)
        cout<<N[S[i]-'A']<<" ";
    return 0;
}