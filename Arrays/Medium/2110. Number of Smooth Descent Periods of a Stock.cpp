class Solution {
public:
    long long getDescentPeriods(vector<int>& prices){
        long long int sz = 0;
        long long int ans = 0;
        for(int i = 0;i<prices.size();i++){
            if(sz == 0) sz++;
            else if(prices[i] - prices[i-1] == -1)
                sz++;
            else if(sz > 0 && prices[i] - prices[i-1] != -1){
                ans += (sz*1ll*(sz + 1)*1ll)/2*1ll;
                sz = 1;
            }
        }
        ans += (sz*1ll*(sz + 1)*1ll)/2*1ll;
        return ans;
    }
};