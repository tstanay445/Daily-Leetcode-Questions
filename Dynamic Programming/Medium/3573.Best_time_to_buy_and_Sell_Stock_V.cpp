class Solution {
public:
    long long f(vector<int>& prices, int k,vector<vector<vector<vector<long long>>>>& dp,int i = 0,int isNormal = false,int hasBrought = false){
        if(i == prices.size() && (!hasBrought)) return 0;
        if(i == prices.size() && hasBrought) return INT_MIN;
        if(k == 0) {return 0;}
        if(dp[i][k][hasBrought][isNormal] != -1) return dp[i][k][hasBrought][isNormal]; 
        long long a1 = 0,a2 = 0,a3 = 0,a4 = 0;
        if(hasBrought){
            if(isNormal)
                a1 = prices[i]*1ll + f(prices,k-1,dp,i+1,false,false)*1ll;
            else
                a1 = -prices[i]*1ll + f(prices,k-1,dp,i+1,false,false)*1ll;
            a2 = f(prices,k,dp,i+1,isNormal,hasBrought);
            return dp[i][k][hasBrought][isNormal] = max(a1*1ll,a2*1ll);
        }
        else{
            a1 = -prices[i]*1ll + f(prices,k,dp,i+1,true,true)*1ll;
            a2 = prices[i]*1ll + f(prices,k,dp,i+1,false,true)*1ll;
            a3 = f(prices,k,dp,i+1,isNormal,hasBrought)*1ll;
            return dp[i][k][hasBrought][isNormal] = max(a1*1ll,max(a2*1ll,a3*1ll));
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
       vector<vector<vector<vector<long long>>>> dp(prices.size(),vector<vector<vector<long long>>>(k+1,vector<vector<long long>>(2,vector<long long>(2,-1))));
        return f(prices,k,dp);
    }
};