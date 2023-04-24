/**
 * @file    :   7-86 宿舍谁最高？
 * @author  :   Tanphoon
 * @date    :   2023/04/18 01:39
 * @version :   2023/04/18 01:39
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    int height, weight;
};
map<int, Node> mp;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int num, height, weight;
        string name;
        cin >> num >> name >> height >> weight;
        // 如果这个宿舍还没往里面加人，或者宿舍里这个人的身高不如当前这个人高，更新这个宿舍的最高人
        if (!mp.count(num) || mp[num].height < height)
            mp[num] = Node{name, height, weight};
    }
    // map按照键值的大小排序，也就是按照宿舍号升序排
    for (auto &[k, e] : mp) {
        printf("%06d %s %d %d\n", k, e.name.c_str(), e.height, e.weight);
    }
    return 0;
}