/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/08/12 15:22
 * @version :   2023/08/12 15:22
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/B
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    set<string> software, data;

    // 1. 安装`xxx`这款软件：sudo pacman -S xxx;
    // 2. 卸载`xxx`这款软件,但是不清除这个软件的个人数据：pacman -R xxx;
    // 3. 卸载`xxx`这款软件，并且一并清除这款软件的个人数据:pacman -Rscn xxx;
    // 4. 删库跑路：sudo rm -rf /*  (-请不要在自己的linux电脑上尝试这条命令哦～）

    // 同时，你需要回答亚托莉问你的几个问题，（后面是提问的形式）

    // 1. 亚托莉安装了xxx这款软件了么？：1 xxx
    // 2. 亚托莉有这款xxx软件的个人数据么？：2 xxx
    while (n--) {
        string s;
        cin >> s;
        if (s == "sudo") {
            cin >> s;
            if (s == "pacman") {
                cin >> s >> s;
                software.insert(s);
                data.insert(s);
            } else if (s == "rm") {
                puts("wuwuwu");
                return 0;
            }
        } else if (s == "pacman") {
            cin >> s;
            if (s == "-R") {
                cin >> s;
                software.erase(s);
            } else if (s == "-Rscn") {
                cin >> s;
                software.erase(s);
                data.erase(s);
            }
        } else if (s == "1") {
            cin >> s;
            puts(software.count(s) ? "yes" : "no");
        } else if (s == "2") {
            cin >> s;
            puts(data.count(s) ? "yes" : "no");
        }
    }
    return 0;
}