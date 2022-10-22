#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	int x,y;
	cin>>a>>b>>c>>d;
	if(b>d)
	{
		y=d-b+60;
		x=c-a-1;
	}
	else
	{
		y=d-b;
		x=c-a;
	}
	cout<<x<<" "<<y;
	return 0;
}