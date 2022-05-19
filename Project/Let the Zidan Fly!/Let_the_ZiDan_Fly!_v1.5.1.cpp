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
	cout<<"游戏规则：初始血量为4，能量为0\n";
	cout<<"[E]能量+1\n[a]消耗1个能量普通攻击对方一次，若成功攻击，则对方血量-1\n;";
	cout<<"[A]=只能格挡对手的普通攻击\n";
	cout<<"[b]消耗2个能量释放大招攻击对方一次，若成功攻击，则对方血量-2\n;";
	cout<<"[B]=只能格挡对手的大招\n";
	//cout<<"输入姓名:"; 
	//cin>>name;
	name="马靖"; 
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
			case 'E' :	cout<<"充能！";break;
			
			case 'a' :  if(!fangui)	cout<<fangui<<"使用普通攻击！";
					    else	cout<<fangui<<"能量不足，消耗血量以攻击";
						break;	
						
			case 'b' :	if(!fangui)	cout<<fangui<<"使用大招！";
						else	cout<<fangui<<"能量不足，消耗血量以攻击";
						break;	
						
			case 'A' : cout<<"使用普攻の格挡！";break;
			
			case 'B' : cout<<"使用大招の格挡！";break;
		}
		cout<<"\nAI";
		switch(R.cmd)
		{
			case 'E' : cout<<"充能！";break;
			case 'a' : cout<<"使用普通攻击！";break;
			case 'b' : cout<<"使用大招！";break;
			case 'A' : cout<<"使用普攻の格挡！";break;
			case 'B' : cout<<"使用大招の格挡！";break;
		}
		cout<<endl;
		///////////////////////////////////////////////////////////////////////////////////
		cout<<"\n  AIの能量="<<R.E;
		for(int i=0;i<R.E;i++)	cout<<"▉";
		cout<<"\n  AIの血量="<<R.B;
		for(int i=0;i<R.B;i++)	cout<<" "<<char(3);
		cout<<endl;
		///////////////////////////////////////////////////////////////////////////////////////
		cout<<endl<<name<<"の能量="<<H.E;
		for(int i=0;i<H.E;i++)	cout<<"▉";
		cout<<endl<<name<<"の血量="<<H.B;
		for(int i=0;i<H.B;i++)	cout<<" "<<char(3);
		cout<<"\n";
		cout<<"//////////////////////////////";
		cout<<endl;
		
	}
	while(H.B>0 && R.B>0);
	if(waigua==true)
	{
		cout<<"dd";
		return 0; 
	}
	if(H.B<=0)	cout<<"AI获胜！";
	if(R.B<=0)	cout<<name<<"获胜！";
	getchar();
	getchar();
	getchar();
	getchar();
	return 0; 
} 



