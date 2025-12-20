class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> dels(strs[0].size(),false);
        for(int j = 0;j<strs[0].size();j++){
            // char prev = '0';
            bool del = false;
            for(int i = 1;i<strs.size();i++){
                if(strs[i][j] < strs[i-1][j]){
                    del = true;
                    break;
                }
            }
            dels[j] = del;
        }
        int s = 0;
        for(bool b: dels)
            s += b;
        return s;
    }
};