#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isBracketValid(string &str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push('(');
        else if (!s.empty())
            s.pop();
        else
            return false;
    }
    return s.empty() ? true : false;
}
int main()
{
    string str;
    cin >> str;
    cout << (isBracketValid(str) ? "Yes" : "No");
    return 0;
}
/* 
#include<stdio.h>//uncle-lu
#include<string.h>
//利用差分来找是否有未配对）在（前面的
char line[10010];
int flag[10010];

int main()
{
	scanf("%s",line+1);

	int len = strlen(line+1);

	for(int i=1; i<=len; ++i)
	{
		if(line[i]=='(')flag[i] = 1;
		else flag[i] = -1;
		__________//objective 2抹平差分数组
	}

	bool f = true;
	for(int i=1; i<=len; ++i)
	{
		if(__________)f = false;//objective 1什么情况是发现了故障？
	}
	if(f)
		printf("Yes");
	else
		printf("No");

	return 0;
}
 */