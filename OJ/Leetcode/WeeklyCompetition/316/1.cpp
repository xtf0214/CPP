#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        if (event1[0] > event2[0])
            event1.swap(event2);
        return event1[1] >= event2[0] ? true : false;
    }
};