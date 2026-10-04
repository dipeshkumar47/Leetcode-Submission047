class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> nge;
        reverse(nums2.begin(), nums2.end());

        for(int curr_num: nums2){
            
            while(!st.empty() && st.top() < curr_num){
                st.pop();
            }

            if(!st.empty()){
                nge[curr_num] = st.top();
            }

            st.push(curr_num);
        }

        vector<int> res;

        for(int curr: nums1){
            if( nge.find(curr) != nge.end()){
                res.push_back(nge[curr]);
            }
            else{
                res.push_back(-1);
            }
        }

        return res;
    }
};