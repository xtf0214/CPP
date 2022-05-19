#include <bits/stdc++.h>
using namespace std;

void start1(bool Switch);
void start2(bool Switch);
void start3(bool Switch);
void start4(bool Switch);
void start5(bool Switch);

string student[51];
struct Seat
{
    string name;
    int book;
} seat[7][10];
struct VIS
{
    int x, y;
    string name;
} vis[24];
int tx[8][4] = {{0, 0, 0}, {0, 2, 1}, {1, 0, 2}, {0, 0, 2}, {2, 0, 2}, {0, 2, 0}, {0, 2, 2}};
int ty[8][4] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 1}, {0, 1, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0, 1}};
struct V_seat
{
    int y, x, book;
} v_seat[9] = {{0, 0, 0}, {1, 1, 0}, {1, 4, 0}, {1, 7, 0}, {3, 1, 0}, {3, 4, 0}, {3, 7, 0}, {5, 1, 0}, {5, 4, 0}};
int temp_pass;
int main()
{
    system("chcp 65001");
    srand(time(0));
    ifstream fin("name2.txt");
    bool Switch = false;
    Switch = true;
    int n;
    cin>>n;
    n = Switch ? (n - 12) : n;
    int m = Switch ? 12 : 0;
    for (int i = 0; i < n; i++)
        fin >> student[i];
    for (int i = 0; i < m; i++)
        fin >> vis[i].name;

    /* for (int i = 0; i < m; i++)
        cout << vis[i].name << endl; */
    while (true)
    {
        for (int y = 1; y <= 6; y++)
            for (int x = 1; x <= 9; x++)
                seat[y][x].book = 0;
        for (int i = 0; i < 9; i++)
            v_seat[i].book = 0;
        start1(Switch);
        start2(Switch);
        start3(Switch);
        start4(Switch);
        start5(Switch);

        for (int i = 0; i < n; i++)
            swap(student[i], student[rand() % (n - i) + i]);
        int s = 0;
        for (int y = 1; y <= 6; y++)
            for (int x = 1; x <= 9; x++)
            {
                if (y == 6 && x == 7)
                    break;
                if (seat[y][x].book == 1)
                    continue;
                seat[y][x].name = student[s++];
            }
        for (int y = 1; y <= 6; y++)
        {
            for (int x = 1; x <= 9; x++)
                cout << seat[y][x].name << "    ";
            cout << endl;
        }
        system("pause");
    }
}

void start1(bool Switch)
{
    if (Switch == false)
        return;
    int temp1 = rand() % 5 + 4;
    temp_pass = temp1;
    int temp2 = rand() % 6 + 1;
    v_seat[temp1].book = 1;
    int s = 0;

    for (int i = 0; i < 3; i++)
    {
        vis[i].x = v_seat[temp1].x + tx[temp2][s++];
        vis[i].y = v_seat[temp1].y + ty[temp2][s++];
        seat[vis[i].y][vis[i].x].book = 1;
        seat[vis[i].y][vis[i].x].name = vis[i].name;
    }
}
void start2(bool Switch)
{
    if (Switch == false)
        return;
    int apart[9] = {0, 8, 7, 7, 3, 3, 1, 3, 1};
    int temp1 = apart[temp_pass];
    int temp2 = rand() % 6 + 1;
    v_seat[temp1].book = 1;
    int s = 0;
    for (int i = 3; i < 6; i++)
    {
        vis[i].x = v_seat[temp1].x + tx[temp2][s++];
        vis[i].y = v_seat[temp1].y + ty[temp2][s++];
        seat[vis[i].y][vis[i].x].book = 1;
        seat[vis[i].y][vis[i].x].name = vis[i].name;
    }
}
void start3(bool Switch)
{
    if (Switch == false)
        return;
    v_seat[temp_pass - 3].book = 1;
    vis[6].y = vis[0].y - 2;
    vis[6].x = vis[0].x;
    vis[7].y = vis[6].y;
    vis[7].x = (vis[6].x % 3 == 1 || vis[6].x % 3 == 2) ? (vis[6].x + 1) : (vis[6].x - 1);
    for (int i = 6; i < 8; i++)
    {
        seat[vis[i].y][vis[i].x].book = 1;
        seat[vis[i].y][vis[i].x].name = vis[i].name;
    }
}
void start4(bool Switch)
{
    if (Switch == false)
        return;
    int temp1;
    do
    {
        temp1 = rand() % 8 + 1;
    } while (v_seat[temp1].book == 1);
    vis[8].y = v_seat[temp1].y;
    vis[8].x = v_seat[temp1].x;
    vis[9].y = vis[8].y;
    vis[9].x = (vis[8].x % 3 == 1 || vis[8].x % 3 == 2) ? (vis[8].x + 1) : (vis[8].x - 1);
    for (int i = 8; i < 10; i++)
    {
        seat[vis[i].y][vis[i].x].book = 1;
        seat[vis[i].y][vis[i].x].name = vis[i].name;
    }
}
void start5(bool Switch)
{
    if (Switch == false)
        return;
    int temp1;
    do
    {
        temp1 = rand() % 8 + 1;
    } while (v_seat[temp1].book == 1);
    vis[10].y = v_seat[temp1].y;
    vis[10].x = v_seat[temp1].x;
    vis[11].y = vis[10].y;
    vis[11].x = (vis[10].x % 3 == 1 || vis[10].x % 3 == 2) ? (vis[10].x + 1) : (vis[10].x - 1);
    for (int i = 10; i < 12; i++)
    {
        seat[vis[i].y][vis[i].x].book = 1;
        seat[vis[i].y][vis[i].x].name = vis[i].name;
    }
}
