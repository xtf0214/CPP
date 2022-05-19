#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring> 
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
bool fangui;
bool waigua;
string name; 

void Blood_Change() {
	if(H.E<=0)
		switch(H.cmd)
		{
			case 'a' :	switch(R.cmd)
						{
							case 'a' : H.B-=2;break;
							case 'b' : H.B-=3;break;
							default : H.B--;
						}
						fangui=true;
						break;
						
			case 'b' :	switch(R.cmd)
						{
							case 'a' : H.B-=3;break;
							case 'b' : H.B-=4;break;
							default : H.B-=2;
						}
						fangui=true;
						break;
						
			case 'E' :	switch(R.cmd)
						{
							case 'a' :H.B--;break;
							case 'b' :H.B-=2;break;
						}
						break;
						
			case 'A' :	if(R.cmd=='b')	H.B-=2;break;
			
			case 'B' :	if(R.cmd=='a')	H.B--;break;	
	}			
	else if(H.E<=1)	
		switch(H.cmd)
		{
			case 'a' :	switch(R.cmd)
						{
							case 'E' : case 'B' : R.B--;break;
							case 'b' : H.B-=2;break;
						}
						break;
						
			case 'b' :	switch(R.cmd)
						{
							case 'a' : H.B-=3;break;
							case 'b' : H.B-=4;break;
							default : H.B-=2;
						}
						fangui=true;
						break;
						
			case 'E' :	switch(R.cmd)
						{
							case 'a' :H.B--;break;
							case 'b' :H.B-=2;break;
						}
						break;
						
			case 'A' :	if(R.cmd=='b')	H.B-=2;break;
			
			case 'B' :	if(R.cmd=='a')	H.B--;break;
		}
	else 
	{
		if(H.cmd=='a')
			if(R.cmd=='E' || R.cmd=='B')	R.B--;			
	
		if(H.cmd=='b')
			if(R.cmd=='E' || R.cmd=='a' || R.cmd=='A')	R.B-=2;	
		
		if(R.cmd=='a')
			if(H.cmd=='E' || H.cmd=='B')	H.B--;
			
		if(R.cmd=='b')
			if(H.cmd=='E' || H.cmd=='a' || H.cmd=='A')	H.B-=2;
	}
}
void Energy_Change() {
	if(!fangui)
	{
		if(H.cmd=='a')	H.E--;
		if(H.cmd=='b')	H.E-=2;
	}	
	if(H.cmd=='E')	H.E++;
	/////////////////////////////////////////////////////////////
	if(R.cmd=='a')	R.E--;
	if(R.cmd=='b')	R.E-=2;	
	if(R.cmd=='E')	R.E++;
}
void Print_Operate() {
	cout<<name; 
	switch(H.cmd)
	{
		case 'E' :	cout<<"���ܣ�";break;
		
		case 'a' :	if(!fangui)	cout<<"ʹ����ͨ������";
					else	cout<<"�������㣬����Ѫ���Թ���";
					break;	
						
		case 'b' :	if(!fangui)	cout<<"ʹ�ô��У�";
					else	cout<<"�������㣬����Ѫ���Թ���";
					break;	
					
		case 'A' : cout<<"ʹ���չ��θ񵲣�";break;
		
		case 'B' : cout<<"ʹ�ô��Фθ񵲣�";break;
	}
	cout<<endl;
	///////////////////////////////////////////////////////////////
	cout<<"AI";
	switch(R.cmd)
	{
		case 'E' : cout<<"���ܣ�";break;
		case 'a' : cout<<"ʹ����ͨ������";break;
		case 'b' : cout<<"ʹ�ô��У�";break;
		case 'A' : cout<<"ʹ���չ��θ񵲣�";break;
		case 'B' : cout<<"ʹ�ô��Фθ񵲣�";break;
	}
}
void print1() {
	cout<<"  AI������="<<R.E;
	for(int i=0;i<R.E;i++)	cout<<"��";
	cout<<endl;
	
	cout<<"  AI��Ѫ��="<<R.B;
	for(int i=0;i<R.B;i++)	cout<<" "<<char(3);
}
void print2() {
	cout<<name<<"������="<<H.E;
	for(int i=0;i<H.E;i++)	cout<<"��";
	cout<<endl;
	
	cout<<name<<"��Ѫ��="<<H.B;
	for(int i=0;i<H.B;i++)	cout<<" "<<char(3);
}
bool Birth() {
	srand(time(0));
	waigua=false;
	fangui=false;
	cin>>H.cmd;
	if(H.cmd=='Q')
	{
		waigua=true;
		system("cls");
		return false;
	}
	else
	{
		system("cls");
		int temp=(R.E>=2)?2:R.E ;
		switch(H.E)
		{	
			case 0 : R.cmd=cmd1[rand()%(temp+1)];break;
			case 1 : R.cmd=cmd2[rand()%(temp+2)];break;
			default : R.cmd=cmd3[rand()%(temp+3)];		
		}
		Blood_Change();
		Energy_Change();
		cout<<endl;
		Print_Operate();
		cout<<endl<<endl;
		print1();
		cout<<endl<<endl;
		print2(); 
		cout<<endl<<endl;
		if(R.B<=0 || H.B<=0)	return false;
		else	return true;	
	}
}
int main() {
	cout<<"��������:"; 
	cin>>name;
	cout<<"������Ϸ�Ѷȣ�1 ~ +�����ε�����4Ϊ�����Ѷȣ���";
	cin>>R.B; 	
	while(Birth());
	if(waigua==true)
	{
		cout<<name<<"ʹ�����һ����ɱAI\n"<<name<<"��ʤ��";
		system("pause");
		return 0;
	}
	if(H.B<=0)
	{
		int a=rand()%3;
		switch(a)
		{
			case 0 :	cout<<name<<"�����ʺ����";break;
			case 1 :	cout<<name<<"��������˿��ӣ�";break;
			case 2 :	cout<<name<<"����������費��ʶ�㣡";break; 
		}	
	}	
	if(R.B<=0)
	{	
		int a=rand()%2;
		switch(a)
		{
			case 0 :	cout<<name<<"��ʤ��������ȥ�����£�";break;
			case 1 :	cout<<name<<"��ʤ�����������İ�����";break; 			
		}
	}
	system("pause");
	return 0; 
} 







