class Solution {
public:
    int averageValue(vector<int>& nums) {
        int res=0,cnt=0;
        for(auto i:nums)
            if(i%6==0)
                res+=i,cnt++;
        if(cnt==0)  return 0;
        else return res/cnt;
        
    }
};