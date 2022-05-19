#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int ER=0;
char H,R;
bool compare(char H,char R) {
	if((H=='a' && R=='E') || (H=='a' && R=='B') || (H=='b' && R=='E') || (H=='b' && R=='a') || (H=='b' && R=='A'))
	{
		cout<<"���Ա������ʺ"; 
		return false;
	}
	
	else if((H=='E' && R=='a') || (H=='E' && R=='b') || (H=='a' && R=='b') || (H=='A' && R=='b') || (H=='B' && R=='a'))
	{
		cout<<"��������";
		return false;
	}
		
	else	return true;		
}
bool play() {
	srand(time(0));
	char cmd1[6]={'E','A','B','a','b'};
	char cmd2[4]={'E','a','B'};
	char cmd3[5]={'E','A','a','b'};
	cin>>H;
	switch(ER)
	{
		case 0 : {	if(ER==0)	R='E';	if(ER==1)	R=cmd1[rand()%2];	if(ER>=2)	R=cmd1[rand()%3];	break;	}
		case 1 : {	if(ER==0)	R=cmd2[rand()%2];	if(ER==1)	R=cmd3[rand()%3];	if(ER>=2)	R=cmd1[rand()%4];	break;	}
		default : {	if(ER==0)	R=cmd2[rand()%3];	if(ER==1)	R=cmd3[rand()%4];	if(ER>=2)	R=cmd1[rand()%5];	break;	}			
	}
	if(R=='E')	ER++;
	if(R=='a')	ER--;
	if(R=='b')	ER-=2;
	cout<<"����ʹ��"<<H<<" "<<"����ʹ�� "<<R<<" ER="<<ER<<endl;
	if(compare(H,R))	return	true;
	else	return false;
}
int main() {
	while(play())	play();	
	return 0;
}

