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
string name; 
bool waigua=false; 

int main() {
	srand(time(0));
	//cout<<"��������:"; 
	//cin>>name;
	name="����"; 
	do
	{
		cin>>H.cmd;
		if(H.cmd=='L')
		{
			waigua=true;
			break;
		}				
		bool fangui=false;
		int temp=(R.E>=2)?2:R.E ;
		switch(H.E)
		{
			case 0 : R.cmd=cmd1[rand()%(temp+1)];break;
			case 1 : R.cmd=cmd2[rand()%(temp+2)];break;
			default : R.cmd=cmd3[rand()%(temp+3)];		
		}
		/////////////////////////////////////////////////////////////
		if(H.E<=0)
			switch(H.cmd)
			{
				case 'a' :	switch(R.cmd)
							{
								case 'a' : H.B-=2;break;
								case 'b' : H.B-=3;break;
								default : H.B--;
							}fangui=true;break;
				case 'b' :	switch(R.cmd)
							{
								case 'a' : H.B-=3;break;
								case 'b' : H.B-=4;break;
								default : H.B-=2;
							}fangui=true;break;
				case 'E' :	switch(R.cmd)
							{
								case 'a' :H.B--;break;
								case 'b' :H.B-=2;break;
							}break;
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
							}break;
				case 'b' :	switch(R.cmd)
							{
								case 'a' : H.B-=3;break;
								case 'b' : H.B-=4;break;
								default : H.B-=2;
							}fangui=true;break;
				case 'E' :	switch(R.cmd)
							{
								case 'a' :H.B--;break;
								case 'b' :H.B-=2;break;
							}break;
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
		//////////////////////////////////////////////////////////////////////////////////
		if(!fangui)
		{
			if(H.cmd=='a')	H.E--;
			if(H.cmd=='b')	H.E-=2;
		}	
		if(H.cmd=='E')	H.E++;
	
		if(R.cmd=='a')	R.E--;
		if(R.cmd=='b')	R.E-=2;	
		if(R.cmd=='E')	R.E++;
		//////////////////////////////////////////////////////////////////////////////////
		cout<<name; 
		switch(H.cmd)
		{
			case 'E' :	cout<<"���ܣ�";break;
			
			case 'a' :  if(!fangui)	cout<<fangui<<"ʹ����ͨ������";
					    else	cout<<fangui<<"�������㣬����Ѫ���Թ���";
						break;	
						
			case 'b' :	if(!fangui)	cout<<fangui<<"ʹ�ô��У�";
						else	cout<<fangui<<"�������㣬����Ѫ���Թ���";
						break;	
						
			case 'A' : cout<<"ʹ���չ��θ񵲣�";break;
			
			case 'B' : cout<<"ʹ�ô��Фθ񵲣�";break;
		}
		cout<<"\nAI";
		switch(R.cmd)
		{
			case 'E' : cout<<"���ܣ�";break;
			case 'a' : cout<<"ʹ����ͨ������";break;
			case 'b' : cout<<"ʹ�ô��У�";break;
			case 'A' : cout<<"ʹ���չ��θ񵲣�";break;
			case 'B' : cout<<"ʹ�ô��Фθ񵲣�";break;
		}
		cout<<endl;
		///////////////////////////////////////////////////////////////////////////////////
		cout<<"\n  AI������="<<R.E;
		for(int i=0;i<R.E;i++)	cout<<"��";
		cout<<"\n  AI��Ѫ��="<<R.B;
		for(int i=0;i<R.B;i++)	cout<<" "<<char(3);
		cout<<endl;
		///////////////////////////////////////////////////////////////////////////////////////
		cout<<endl<<name<<"������="<<H.E;
		for(int i=0;i<H.E;i++)	cout<<"��";
		cout<<endl<<name<<"��Ѫ��="<<H.B;
		for(int i=0;i<H.B;i++)	cout<<" "<<char(3);
		cout<<"\n";
		cout<<endl;
		
	}
	while(H.B>0 && R.B>0);
	if(waigua==true)
	{
		cout<<"dd";
		return 0; 
	}
	if(H.B<=0)	cout<<"AI��ʤ��";
	if(R.B<=0)	cout<<name<<"��ʤ��";
	system("pause");
	return 0; 
} 



