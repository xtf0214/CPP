#include<bits/stdc++.h>
using namespace std;
int num[9], n, cnt;
char opera[8];
vector<string> ans;
void count() { // 根据先‘ ’，再‘*’，最后‘+’‘-’的顺序进行计算
    int sum;
    vector<int> data,     // 存进行过‘ ’运算的数据
        new_data;         // 存进行过‘*’运算之后的数据
    vector<char> operate, // 存除‘ ’外的运算符
        new_operate;      // 存除‘ ’，‘*’以外的运算符
    sum = num[0];         // 处理操作符与数据之间的错位
    for (int i = 0; i < n - 1; ++i) {
        if (opera[i] == ' ') {
            if (sum == 0) // 清除末尾有0但无‘ ’以外运算符的情况
                return;
            sum = sum * 10 + num[i + 1];
        } else {
            data.push_back(sum);
            operate.push_back(opera[i]);
            sum = num[i + 1];
        }
    }
    data.push_back(sum); // 存入最后一个划分好的数据
    sum = data[0];
    for (int i = 0; i < operate.size(); ++i) {
        if (operate[i] == '*')
            sum *= data[i + 1];
        else {
            new_data.push_back(sum);
            new_operate.push_back(operate[i]);
            sum = data[i + 1];
        }
    }
    new_data.push_back(sum);
    sum = new_data[0];
    for (int i = 0; i < new_operate.size(); ++i)
        if (new_operate[i] == '+')
            sum += new_data[i + 1];
        else
            sum -= new_data[i + 1];
    if (sum == 2000) {
        string res;
        for (int i = 0; i < operate.size(); ++i)
            res += to_string(data[i]) + operate[i];
        res += to_string(data[operate.size()]) + "=" + to_string(sum);
        ans.push_back(res);
        cnt++;
    }
}

void put_operator(int x) {
    if (x == n - 1) {
        count();
        return;
    }
    opera[x] = ' '; // 假定‘ ’为两位及两位以上数字之间的操作符
    put_operator(x + 1);
    opera[x] = '*';
    put_operator(x + 1);
    opera[x] = '+';
    put_operator(x + 1);
    opera[x] = '-';
    put_operator(x + 1);
}

int main() {
    while (cin >> n) {
        char c;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            num[i] = c - '0';
        }
        cnt = 0;
        put_operator(0);
        if (!cnt)
            cout << "IMPOSSIBLE" << endl;
        else {
            sort(ans.begin(), ans.end());
            for (auto &s : ans)
                cout << s << endl;
        }
    }
    return 0;
}
