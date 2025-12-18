class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long int currProfit = 0;
        for(int i = 0;i<strategy.size();i++)
            currProfit += (prices[i] * 1ll * strategy[i]);
        long long org = 0,mod = 0;
        for(int i = 0;i<k;i++){
            org += (strategy[i] * 1ll * prices[i]);
            if(i >= (k/2)){
                mod += (prices[i]);
            }
        }
        long long best = max(0*1ll,mod - org);
        for(int i = k;i<prices.size();i++){
            org += (-strategy[i-k] * 1ll * prices[i-k]);
            org += (strategy[i] * 1ll * prices[i]);

            mod -= (prices[i - (k/2)]);
            mod += (prices[i]);
            
            best = max(best,mod - org);
        }
        return currProfit + best;
    }
};