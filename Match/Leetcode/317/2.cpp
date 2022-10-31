#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        map<string, pair<int, string>> Map;
        vector<pair<string, pair<int, string>>> arr;
        vector<vector<string>> res;
        int n = creators.size();
        for (int i = 0; i < n; i++)
        {
            if (Map.count(creators[i]) == 0)
                Map[creators[i]] = {views[i], ids[i]};
            else
            {
                auto cur = Map[creators[i]];
                if (views[i] > cur.first)
                {
                    Map[creators[i]].second = ids[i];
                }
                else if (views[i] == cur.first && ids[i] < cur.second)
                {

                    Map[creators[i]].second = ids[i];
                }
                Map[creators[i]].first += views[i];
            }
        }
        for (auto &i : Map)
            arr.push_back(i);
        sort(arr.begin(), arr.end(), [](const pair<string, pair<int, string>> &a, const pair<string, pair<int, string>> &b)
             { return a.second.first > b.second.first; });
        int cnt = 1;
        for (int i = 1; i < arr.size();i++)
            if(arr[i].second.first!=arr[0].second.first)
                break;
            else
                cnt++;
        for (int i = 0; i < cnt;i++)
            res.push_back({arr[i].first, arr[i].second.second});
        return res;
    }
};
int main()
{
    Solution res;
    vector<string> creators{"alice", "bob", "alice", "chris"};
    vector<string> ids{"one", "two", "three", "four"};
    vector<int> views{5, 10, 5, 4};
    res.mostPopularCreator(creators, ids, views);
}