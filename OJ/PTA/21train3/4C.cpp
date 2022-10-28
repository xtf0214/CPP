#include <iostream>  
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <stack>  
#include <stdlib.h>  
  
using namespace std;  
  
stack <double> q;  
int main(){  
  
    string a[100];  
    bool error = 0;  
    int n = 0;  
  
    while(cin>>a[n++]){}///读到文件结尾自动结束  
  
    n -= 1;///注意这里n是个数，需要减一，可自己尝试确认  
  
    for(int i = n-1; i>=0; i--){  
        ///如果是符号  
        if(a[i].length() == 1 && (a[i][0]== '+' || a[i][0]=='-' || a[i][0]=='*' || a[i][0]=='/')){  
            if(q.size()<2) {error = 1; break;}  
            double aa = q.top(); q.pop();  
            double bb = q.top(); q.pop();  
            if(a[i][0]== '+') q.push(aa+bb);  
            else if(a[i][0]== '-') q.push(aa-bb);  
            else if(a[i][0]== '*') q.push((aa*bb));  
            else if(a[i][0]== '/') {  
                if(bb==0){error = 1; break;}  
                q.push(aa/bb);  
            }  
        }  
        else{  
            /// c_str() 函数是转化为字符数组  
            ///atof() 是c语言中将字符数组转化为浮点型数据函数  
            double x = atof(a[i].c_str());  
            q.push(x);  
        }  
    }  
  
    if(q.size() != 1) error = 1;  
  
    if(error) printf("ERROR");  
    else printf("%.1f",q.top());  
    return 0;  
}  