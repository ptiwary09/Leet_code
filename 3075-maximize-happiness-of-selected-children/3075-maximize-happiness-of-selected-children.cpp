class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long total=0;
        sort(happiness.rbegin(),happiness.rend());
        for(long long i=0;i<k;i++){
            
        
        long long currH;
        currH=happiness[i];
        if(currH-i>=0) total+=currH-i;
        
    }
        return total;
    
        
        
        
    }
};