//#include<stdio.h>
//
//
// 局部多个关系 联系
// int main()
//{
//	int cou_Arr[26] = { 0 }, cou_arr[26] = { 0 }, i = 0,clon = 0;
//	/ar ch_arr[27] = { 'A','B','C','D','E','F','G','H','I','J','K'''''''''''''''''''''''}, ch = '0';
//	//产生 a b c这是浪费时间的写法
//	//由一个产生多个
//	char ch_A = 'A';
//	char ch_a = 'a',ch = '0';
//	while ((ch = getchar()) != '\n')
//	{
//		for (i = 0; i < 26; i++)
//		{
//			if (ch == (ch_A  + i))
//			{
//				cou_Arr[i]++;	//i 为 0 那么是 a
//			}
//
//		}
//		for (i = 0; i < 26; i++)
//		{
//			if (ch == (ch_a + i))
//			{
//				cou_arr[i]++;	//i 为 0 那么是 a
//			}
//
//		}
//	}
//	for (i = 0; i < 26; i++)//输出
//	{
//
//		if (cou_Arr[i] != 0)
//		{
//			printf("%c--%d", (ch_A + i), cou_Arr[i]);
//			clon++;
//			if (clon != 10)
//			{
//				printf(" ");
//
//			}
//			if (clon %10==0)
//			{
//				printf("\n");
//			}
//		}
//
//
//
//
//	}
//	for (i = 0; i < 26; i++)
//	{
//		if (cou_arr[i] != 0)
//		{
//			printf("%c--%d", (ch_a + i), cou_arr[i]);
//			clon++;
//			if ((clon != 10)&(cou_arr[i+1] != 0))
//			{
//				printf(" ");
//
//			}
//		}
//
//		while (clon >= 10)
//		{
//			printf("\n");
//			clon -= 10;
//		}
//
//	}
//	printf("\n");
//	return 0;
//}

//建立在整体 对象上
//利用 局部 关系重新分配整体

#include <stdio.h>
struct words
{
    int id;
    int cnt; //顺序  次数
    char c;  //他的值
} words_arr[60];
int main()
{

    char ch_A = 'A', ch_a = 'a', ch;
    int i = 0, j = 0, clon = 0;
    static int cou = 0;
    while ((ch = getchar()) != '\n')
    {
        for (i = 0; i < 26; i++) //产生26字母
        {
            if (ch == (ch_A + i) || (ch == (ch_a + i))) // 26字母比较
            {
                for (j = 0; j < 52; j++)
                {
                    if (ch == words_arr[j].c) //字符出现过
                    {
                        //保存字符  以后出现这个字符都保存到里面
                        words_arr[j].cnt++; //出现次数

                        break;
                    } //字符已经赋值
                }
                if (j == 52) //新值
                {
                    words_arr[cou].c = ch;
                    words_arr[cou].cnt++;
                    words_arr[cou].id = cou;
                    cou++;
                }
            }
        }
        // cou = 26;
        // for (i = 0; i < 26; i++)			//产生26字母
        //{
        //	if (ch == (ch_a + i))	//26字母比较
        //	{
        //		for (j = 26; i < 52; j++)
        //		{
        //			if (ch == words_arr[j].c)	//字符出现过
        //			{
        //				//保存字符  以后出现这个字符都保存到里面
        //				words_arr[j].cnt++;	//出现次数

        //				break;
        //			}//字符已经赋值

        //		}
        //		if (j == 52)//新值
        //		{
        //			words_arr[cou].c = ch;
        //			words_arr[cou].cnt++;
        //			words_arr[cou].id = cou;
        //			cou++;
        //		}
        //	}
        //}
    }
    for (i = 0; i < 52; i++)
    {
        if (words_arr[i].cnt != 0)
        {
            clon % 10 == 0 ? printf("%c--%d", words_arr[i].c, words_arr[i].cnt) : printf(" %c--%d", words_arr[i].c, words_arr[i].cnt);
            clon++;
        }
        if (clon >= 10)
        {
            printf("\n");
            clon -= 10;
        }
    }

    printf("\n");
    return 0;
}
