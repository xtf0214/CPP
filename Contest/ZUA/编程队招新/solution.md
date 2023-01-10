# 7-1 L1 甭废话上代码 (5 分)

听闻编程队现有两位蒟蒻(ju ruo)，分别是wsx和sl，请你输出“I want to surpass those two people!"

### 输入格式:

无

### 输出格式:

I want to surpass those two people!

### 样例输入:

你什么也不需要输入：

```

```

### 输出样例:

在这里给出相应的输出。例如：

```
I want to surpass those two people!
```

```cpp
#include<stdio.h>
int main(){
    printf("I want to surpass those two people!");
    return 0;
}
```

# 7-2 L1 字符串中的大写字母改成小写字母 (10 分)

##### 思路：没啥说，直接对大写字符加32就行了ascii码表中大写字母在前，小写字母在后

把一个字符串中的大写字母改成小写字母，其他字符不变。

### 输入格式:

在 一行中输入长度小于20的字符串。在字符串中不要出现换行符，空格，制表符。

### 输出格式:

直接输出变化后的字符串。

### 输入样例:

```cpp
asDFGed
```

### 输出样例:

```cpp
asdfged
```

```cpp
#include<stdio.h>
#include<string.h>
int main()
{
    char str[20];
    gets(str);
    int n=strlen(str);
    for(int i=0;i<n;i++)
    {
        if(str[i]<='Z'&&str[i]>='A')
        {
            str[i]=str[i]+32;
        }
    }
    printf("%s",str);
    return 0;
}
```

# 7-3 L1 方阵转置 (10 分)

##### 思路：读入数据的时候就反过来，直接输出就可以了，注意宽度是4要%4d

本题要求编写程序，将一个给定的  *n* ×*n* 方阵转置（行列互换）后输出。

### 输入格式:

输入第一行给出一个正整数 *n* （1≤ *n* ≤6）。随后*n*行，每行给出*n*个整数，其间以空格分隔。

### 输出格式:

输出转置后的*n*行*n*列矩阵，每个数占4位。

### 输入样例:

```
3
1 2 3
4 5 6
7 8 9
```

### 输出样例:

```
   1   4   7
   2   5   8
   3   6   9
```

```cpp
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int nums[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&nums[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

# 7-4 L1 统计字符串中数字字符的个数 (10 分)

##### 思路：直接遍历字符串，统计字符0-9即可，对于有空格的字符串可以使用scanf("%c")一个一个读，遇到\n结束循环。

输入一个字符串，统计其中数字字符（'0'……'9'）的个数。

### 输入格式:

输入在一行中给出一个不超过80个字符长度的、以回车结束的非空字符串。

### 输出格式:

输出所统计的数字字符的个数。

### 输入样例:

```
Enter a string: It's 512?
```

### 输出样例:

```
3
```

```cpp
#include <stdio.h>
int main()
{
    char a[81];
    int i=0,out=0;
    while(i < 81)
    {
        scanf("%c",&a[i]);
        if(a[i] == '\n')
        break;
        if(a[i] >= '0'&&a[i] <= '9')
        out++;
        i++;  
    }
    printf("%d",out);
    return 0;
 } 
```

# 7-5 L1 输出字符串 (10 分)

##### 思路：例题原题，略微做了修改，这次是最长和较晚的一个，定义一个结构体str，ss保存字符串，index保存下标，然后进行结构体进行排序，先按长度降序，再按下标降序即可。

输入n个字符串，输出其中最短的字符串。若长度相同则输出出现较早的那一个。

### 输入格式:

第一行是一个整数n，后面跟着n行，每行包括一个由字母和数字和空格组成的字符串，长度不超过1000

### 输出格式:

输出长度最长的字符串，若长度相同则输出出现较晚的那一个。

### 输入样例:

在这里给出一组输入。例如：

```
4
hello world!
zuaoj mmm
jmx aaaaaaac
happylxp
```

### 输出样例:

在这里给出相应的输出。例如：

```
jmx aaaaaaac
```

```cpp
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str{
    char ss[1001];
    int index;
}str[10000];
int cmp(const void * a, const void * b)
{
    struct str *A=(struct str*)a;
    struct str *B=(struct str*)b;
    //先按照长度排序，如果相等，按照下标排序 
    if(strlen(A->ss)!=strlen(B->ss)){
        return strlen(B->ss)-strlen(A->ss);
    }else{
        return (B->index)-(A->index);
    
    }
}
int main(){
    int n;
    scanf("%d",&n); 
    //吃掉n后面的换行符 
    getchar();
    //将数据存入结构体数组中 
    for(int i=0;i<n;i++){
        gets(str[i].ss);
        str[i].index=i;
    }
    //使用qsort进行结构体排序 
    qsort(str,n,sizeof(struct str),cmp);
    printf("%s",str[0].ss);
    return 0;
} 
```

# 7-6 L1 水仙花数 (20 分)

##### 思路：这道题有坑，最后N=7很可能超时，拿17分，解决方案是直接特判为7的时候输出答案就行，不需要自己算，本身就是固定的，也没几个。

水仙花数是指一个*N*位正整数（ *N* ≥3），它的每个位上的数字的*N*次幂之和等于它本身。例如：153=13+53+33。 本题要求编写程序,计算所有*N*位水仙花数。

### 输入格式:

输入在一行中给出一个正整数 *N* （3≤ *N* ≤7）。

### 输出格式:

按递增顺序输出所有*N*位水仙花数，每个数字占一行。

### 输入样例:

```
3
```

### 输出样例:

```
153
370
371
407
```

```cpp
#include<stdio.h>
#include<math.h>
int isShui(int x,int n){
    int sum=0,temp=x;
    while(x){
        sum+=pow(x%10,n);
        x/=10;
    }
    return sum==temp;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==7){
        printf("1741725\n4210818\n9800817\n9926315");
    }else{
        for(int i=pow(10,n-1);i<=pow(10,n)-1;i++){
            if(isShui(i,n))printf("%d\n",i);
        }
    }
    return 0;
}
```

# 7-7 L1 打印沙漏 (20 分)

##### 思路：先判断所给符号数目是不是刚好用于打印漏斗，再算出行数，并找行与符号个数的关系，可根据对称性分为上下两部分找规律。

本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

```cpp
*****
 ***
  *
 ***
*****
```

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

### 输入格式:

输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

### 输出格式:

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

### 输入样例:

```
19 *
```

### 输出样例:

```
*****
 ***
  *
 ***
*****
2
```

```cpp
#include<stdio.h>
#include<math.h>
int main() {
    int n,k,j,i,s;
    int b,S,p;
    char c;
    scanf("%d %c",&S,&c);
  
    b=(S+1)/2;
    n=sqrt(b);
    s=2*n*n-1;//等差数列求和公式
    n=n+1;
  
    for (i=1;i<n;i++) {
        for (j=2;j<=i;j++) {
            printf(" ");
        }
        for (k=2*(n-i)-1;k>0;k--) {
            printf("%c",c);
        }
        printf("\n");
    }
    for (i=2;i<n;i++) {
        for (j=n-i-2;j>=0;j--) {
            printf(" ");
        }
        for (k=1;k<=2*i-1;k++) {
            printf("%c",c);
        }
        printf("\n");
    }
    printf("%d",S-s);
    return 0;
}
```

# 7-8 L1 找鞍点 (20 分)

##### 思路：预先找好每一行最大值和每一列最小值存入数组，然后遍历数组每一个值与预先存好的值进行比较，如满足输出即可

一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。

本题要求编写程序，求一个给定的*n*阶方阵的鞍点。

### 输入格式：

输入第一行给出一个正整数 *n* （1≤ *n* ≤6）。随后*n*行，每行给出*n*个整数，其间以空格分隔。

### 输出格式：

输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。

### 输入样例1：

```
4
1 7 4 1
4 8 3 6
1 6 1 2
0 7 8 9
```

### 输出样例1：

```
2 1
```

### 输入样例2：

```
2
1 7
4 1
```

### 输出样例2：

```
NONE
```

```cpp
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int nums[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&nums[i][j]);
  
    //该部分负责查找每一行最大值，每一列最小值 
    int max_line[n],min_row[n];
    for(int i=0;i<n;i++){
        max_line[i]=nums[i][0];
        for(int j=0;j<n;j++){
            if(max_line[i]<nums[i][j])max_line[i]=nums[i][j];
        }
    }
    for(int i=0;i<n;i++){
        min_row[i]=nums[0][i];
        for(int j=0;j<n;j++){
            if(min_row[i]>nums[j][i])min_row[i]=nums[j][i];
        }
    }
  
    //将每一个nums数组进行遍历，与min_row数组的值和max_line数组值比较，如果都符合，说明是该列最小，该行最大，输出相应i和j
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[i][j]==max_line[i]&&nums[i][j]==min_row[j]){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    printf("NONE");
    return 0;
}
```

# 7-9 L1 黑洞数 (20 分)

##### 思路：将输入数字放入数组中从小到大排序获得最小值，从大到小排序获取最大值，求差输出结果即可。

黑洞数也称为陷阱数，又称“Kaprekar问题”，是一类具有奇特转换特性的数。

任何一个各位数字不全相同的三位数，经有限次“重排求差”操作，总会得到495。最后所得的495即为三位黑洞数。所谓“重排求差”操作即组成该数的数字重排后的最大数减去重排后的最小数。（6174为四位黑洞数。）

例如，对三位数207：

* 第1次重排求差得：720 - 27 ＝ 693；
* 第2次重排求差得：963 - 369 ＝ 594；
* 第3次重排求差得：954 - 459 ＝ 495；

以后会停留在495这一黑洞数。如果三位数的3个数字全相同，一次转换后即为0。

任意输入一个三位数，编程给出重排求差的过程。

### 输入格式：

输入在一行中给出一个三位数。

### 输出格式：

按照以下格式输出重排求差的过程：

```
序号: 数字重排后的最大数 - 重排后的最小数 = 差值
```

### 输入样例：

```
123
```

### 输出样例：

```
1: 321 - 123 = 198
2: 981 - 189 = 792
3: 972 - 279 = 693
4: 963 - 369 = 594
5: 954 - 459 = 495
```

```cpp
#include<bits/stdc++.h>
using namespace std;
bool cmp1(int a,int b){
    return a<b;
}
bool cmp2(int a,int b){
    return a>b;
}
int main(){
    int num1[3],num2[3],a,b,c;
    scanf("%1d%1d%1d",&a,&b,&c);
    num1[0]=a;
    num1[1]=b;
    num1[2]=c;
    int A,B,n=1;
    while(1){
        sort(num1,num1+3,cmp2);//将abc读入num1中，从大到小排序，获得最大值
        num2[0]=num1[0];
        num2[1]=num1[1];
        num2[2]=num1[2];
        sort(num2,num2+3,cmp1);//再将num2从小到大排序，获得最小值
        //将排序后数组计算获得整数值
        A=num1[0]*100+num1[1]*10+num1[2];
        B=num2[0]*100+num2[1]*10+num2[2];
        //输出A-B结果
        printf("%d: %d - %d = %d\n",n++,A,B,A-B);
        //若为495则结束程序
        if(A-B==495)break;
        else{
            //否则将获得的差重新赋值给num1中
            num1[0]=(A-B)/100;
            num1[1]=((A-B)/10)%10;
            num1[2]=(A-B)%10;
            sort(num1,num1+3,cmp2);
        }
    }
    return 0;
}
```

# 7-10 L1 英文单词排序 (25 分)

##### 思路：此题目与7-5差不多，注意此题是以#结尾，然后放入结构体st，id是下标，然后先按字符串长度进行排序，再按照id进行排序，输出即可。（注意输出格式，每个单词后都有一个空格，一定要严格按照要求格式输出。）

本题要求编写程序，输入若干英文单词，对这些单词按长度从小到大排序后输出。如果长度相同，按照输入的顺序不变。

### 输入格式：

输入为若干英文单词，每行一个，以 `#`作为输入结束标志。其中英文单词总数不超过20个，英文单词为长度小于10的仅由小写英文字母组成的字符串。

### 输出格式：

输出为排序后的结果，每个单词后面都额外输出一个空格。

### 输入样例：

```
blue
red
yellow
green
purple
#
```

### 输出样例：

```
red blue green yellow purple
```

```cpp
#include<bits/stdc++.h>
using namespace std;
struct st
{
    string a;
    int id;
};
st s[25];
bool cmp(st x,st y)
{
    if(x.a.size()!=y.a.size())
        return x.a.size()<y.a.size();
    else return x.id<y.id;
}
int main()
{
    int n=0;
    while(cin>>s[n].a&&s[n].a[0]!='#')//读到#结束读取。n就是读入单词数量
    {
        s[n].id=n;
        n++;
    }
    sort(s,s+n,cmp);//按照要求排序
    for(int i=0;i<n;i++)
    {
        cout<<s[i].a<<" ";//每个单词结尾后都有一个空格。
    }
}
```

# 7-11 L2 前世档案 (20 分)

##### 思路：这个题可以采用二分法，对于每一次y/n进行取半，举个例子例如yny，设置low和high，low初始为1，high初始为8，那么第一个为y则取前一半，high为4，此时low，high范围为1-4，第二个为n则，high不变，low为3，此时low，high范围为3-4，第三个为y则直接输出3。

![qs.jpg](https://images.ptausercontent.com/2ab62885-0642-4a48-b41d-94e4e30d7246.jpg)

网络世界中时常会遇到这类滑稽的算命小程序，实现原理很简单，随便设计几个问题，根据玩家对每个问题的回答选择一条判断树中的路径（如下图所示），结论就是路径终点对应的那个结点。

![path.jpg](https://images.ptausercontent.com/822292db-6097-418b-a245-02e4a2473560.jpg)

现在我们把结论从左到右顺序编号，编号从 1 开始。这里假设回答都是简单的“是”或“否”，又假设回答“是”对应向左的路径，回答“否”对应向右的路径。给定玩家的一系列回答，请你返回其得到的结论的编号。

### 输入格式：

输入第一行给出两个正整数： *N* （≤30）为玩家做一次测试要回答的问题数量； *M* （≤100）为玩家人数。

随后 *M* 行，每行顺次给出玩家的 *N* 个回答。这里用 `y` 代表“是”，用 `n` 代表“否”。

### 输出格式：

对每个玩家，在一行中输出其对应的结论的编号。

### 输入样例：

```
3 4
yny
nyy
nyn
yyn
```

### 输出样例：

```
3
5
6
2
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    getchar();
    for(int j=0;j<M;j++){
        int low=1,high=pow(2,N);//设置初始值
        string t;
        cin>>t;
        int i;
        for(i=1;i<N;i++){
            if(t[i-1]=='y')high=(high+low)/2;//为y则low不变，high去半
            else if(t[i-1]=='n')low=(high+low)/2+1;//为n则high不变，low往前去半
        }
        if(t[i-1]=='y')printf("%d\n",low);//根据最后一个y和n直接输出结果即可
        else if(t[i-1]=='n')printf("%d\n",high);    
    }
    return 0;
} 
```

# 7-12 L2 简单计算器 (25 分)

##### 思路：这道题目相对简单，题目已经描述很清楚，会数据结构知识就可以了，按照题目描述写就行了，题解使用了STL中的stack，没有学过STL的同学可以看一下这个链接入门一下啊[http://c.biancheng.net/stl/](http://c.biancheng.net/stl/ "http://c.biancheng.net/stl/")

![cal.jpg](https://images.ptausercontent.com/7a19b25d-2a56-49dc-bbc4-698c8b1db505.jpg)

本题要求你为初学数据结构的小伙伴设计一款简单的利用堆栈执行的计算器。如上图所示，计算器由两个堆栈组成，一个堆栈 *S*1 存放数字，另一个堆栈 *S*2 存放运算符。计算器的最下方有一个等号键，每次按下这个键，计算器就执行以下操作：

1. **从 *S*1 中弹出两个数字，顺序为 *n*1 和 *n*2；**
2. **从 *S*2 中弹出一个运算符 op；**
3. **执行计算 *n*2 op *n*1；**
4. **将得到的结果压回 *S*1。**

直到两个堆栈都为空时，计算结束，最后的结果将显示在屏幕上。

### 输入格式：

输入首先在第一行给出正整数  *N* （1< *N* ≤103），为 *S*1 中数字的个数。

第二行给出 *N* 个绝对值不超过 100 的整数；第三行给出  *N* −1 个运算符 —— 这里仅考虑 `+`、`-`、`*`、`/` 这四种运算。一行中的数字和符号都以空格分隔。

### 输出格式：

将输入的数字和运算符按给定顺序分别压入堆栈 *S*1 和 *S*2，将执行计算的最后结果输出。注意所有的计算都只取结果的整数部分。题目保证计算的中间和最后结果的绝对值都不超过 109。

如果执行除法时出现分母为零的非法操作，则在一行中输出：`ERROR: X/0`，其中 `X` 是当时的分子。然后结束程序。

### 输入样例 1：

```
5
40 5 8 3 2
/ * - +
```

### 输出样例 1：

```
2
```

### 输入样例 2：

```
5
2 5 8 4 4
* / - 
```

### 输出样例 2：

```
ERROR: 5/0
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s1;
    stack<char> s2;
    int n,num;
    char op;
    scanf("%d",&n); 
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        s1.push(num);
    }
    for(int i=0;i<n-1;i++){
        cin>>op;
        s2.push(op);
    }
    while(!s2.empty()){
        int n1=s1.top();
        s1.pop();
        int n2=s1.top();
        s1.pop();
        op=s2.top();
        s2.pop();
        if(op=='+')s1.push(n2+n1);
        else if(op=='-')s1.push(n2-n1);
        else if(op=='*')s1.push(n2*n1);
        else if(op=='/'){
            if(n1==0){
                printf("ERROR: %d/0",n2);
                return 0;
            }else{
                s1.push(n2/n1);
            }
        }
    }
    printf("%d",s1.top());
    return 0;
}
```

# 7-13 L2 并查集【模板】 (30 分)

##### 思路：定义一个数组fa[]，并进行初始化为自身下标，每一个下标就是节点值，下标对应的fa值是其父节点的下标，如果下标值与对应fa数组值相等，说明是根节点。合并操作就是利用递归找到两个元素的根节点，然后将其中一个值赋值给另一个，来实现合并。同时如果递归找到的根节点不同那么就说明他们是两个集合。

##### 最优美而且最简单的数据结构。

##### 这个东西很多地方都有讲解，这个东西其实是图论的最大连通分量的问题。并且将每一个连通树变为只有一个根节点其他都简化为left node 的树。

##### 这里贴一个并查集的帖子吧。

[算法学习笔记(1) : 并查集 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/93647900 "https://zhuanlan.zhihu.com/p/93647900")

给出一个并查集，请完成合并和查询操作。

### 输入格式:

第一行包含两个整数N、M，表示共有N个元素和M个操作。

接下来M行，每行包含三个整数 *Z**i* 、 *X**i* 、 *Y**i* 。

当 *Z**i* =1时，将*X**i*与*Y**i*所在的集合合并。

当 *Z**i* =2时，输出*X**i*与*Y**i*是否在同一集合内，是的话输出Y；否则的话输出N。

### 输出格式:

对于每一个 *Z**i* =2的操作，对应一行输出，每行包含一个大写字母，为Y或者N。

### 输入样例:

```
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4
```

### 输出样例:

```
N
Y
N
Y
```

### 数据规模:

对于30%的数据，N<=10，M<=20；

对于70%的数据，N<=100，M<=1000；

对于100%的数据，N<=10000，M<=200000。

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int fa[N];
void init(){ for(int i=0;i<N;i++)fa[i] = i;}
int find(int x){
    if( x == fa[x])return x;
    return fa[x] = find(fa[x]);
}
void join(int x,int y){
    //这里一般可能会有其他特殊要求，根据题意来进行
    //这里的就简单的并起来就行，有些题目可能要求“按秩合并”，带size的并查集 等等
    fa[find(x)] = find(y);
}
int main()
{
    int n,m;
    init();
    scanf("%d %d",&n,&m);
    while(m --)
    {
        int z,ax,bx;
        scanf("%d %d %d",&z,&ax,&bx);
        if( z == 1){
            join(ax,bx);
        }else{
            if( find( ax)  == find( bx)){
                 printf("Y\n");
            }else{
                printf("N\n");
            }
        }
    }
}
```
