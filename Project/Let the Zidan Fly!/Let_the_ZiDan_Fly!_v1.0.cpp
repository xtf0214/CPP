#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct act {
	int E,B;
	char cmd;
};
act H={0,4};
act R={0,4};

char cmd1[4]={'E','a','b'};	
char cmd2[5]={'E','A','a','b'};
char cmd3[6]={'E','A','B','a','b'};

void compare() {
	if(H.cmd=='a')
		if(R.cmd=='E' || R.cmd=='B')	R.B--;
	if(H.cmd=='b')
		if(R.cmd=='E' || R.cmd=='a' || R.cmd=='B')	R.B-=2;
	if(R.cmd=='a')
		if(R.cmd=='E' || R.cmd=='B')	H.B--;
	if(R.cmd=='b')
		if(R.cmd=='E' || R.cmd=='a' || R.cmd=='B')	H.B-=2;
}

void Energy_Change() {
	if(H.cmd=='a')	H.E--;
	if(H.cmd=='b')	H.E-=2;
	if(H.cmd=='E')	H.E++;
	if(R.cmd=='a')	R.E--;
	if(R.cmd=='b')	R.E-=2;	
	if(R.cmd=='E')	R.E++;
}

void print() {
	cout<<"玩家"; 
	switch(H.cmd)
	{
		case 'E' : cout<<"充能！";break;
		case 'a' : cout<<"发射小炮！";break;
		case 'b' : cout<<"发射大炮！";break;
		case 'A' : cout<<"使用小炮の格挡！";break;
		case 'B' : cout<<"使用大炮の格挡！";break;
	}
	
	cout<<"\n电脑";
	switch(R.cmd)
	{
		case 'E' : cout<<"充能！";break;
		case 'a' : cout<<"发射小炮！";break;
		case 'b' : cout<<"发射大炮！";break;
		case 'A' : cout<<"使用小炮の格挡！";break;
		case 'B' : cout<<"使用大炮の格挡！";break;
	}
	cout<<"\n";
}
void print1() {
	cout<<"电脑の能量";
	for(int i=0;i<R.E;i++)	cout<<"$";
	cout<<"\n电脑の血量";
	for(int i=0;i<R.B;i++)	cout<<"▉";
}
void print2() {
	cout<<"\n玩家の能量";
	for(int i=0;i<H.E;i++)	cout<<"$";
	cout<<"\n玩家の血量";
	for(int i=0;i<H.B;i++)	cout<<"▉";
	cout<<"\n";
}
bool Birth() {
	srand(time(0));
	cin>>H.cmd;
	int temp=(R.E>=2)?2:R.E ;
	switch(H.E)
	{
		case 0 : R.cmd=cmd1[rand()%(temp+1)];break;
		case 1 : R.cmd=cmd2[rand()%(temp+2)];break;
		default : R.cmd=cmd3[rand()%(temp+3)];break;		
	}
	print();
	Energy_Change();
	compare();
	print1();
	print2(); 
	if(R.B==0 || H.B==0)	return false;
	else	return true;
}
int main() {
	while(Birth())	Birth();
	if(H.B==0)	cout<<"电脑获胜！";
	if(R.B==0)	cout<<"玩家获胜！";
	return 0; 
} 
