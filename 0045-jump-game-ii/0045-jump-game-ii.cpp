class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumpCount = 0, maxReach = 0, currentJumpEnd = 0;

        for(int i=0; i < nums.size() - 1 ; i++){
            
            maxReach = max(maxReach, i + nums[i]);

            if(i == currentJumpEnd){
                jumpCount++;
                currentJumpEnd = maxReach;
            }
        }

        return jumpCount;
    }
};