class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        const int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st;

        for(int i=0; i < n*2; i++){

            const int num = nums[i % n];
            while(!st.empty() && nums[st.top()] < num){
                ans[st.top()] = num, st.pop();
            }

            if(i < n) st.push(i);
        }

        return ans;
    }
};