class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    stack<int> monotonicStack;

    unordered_map<int, int> nextGreaterMap;

    reverse(nums2.begin(), nums2.end());

    for(int currentNum: nums2){

        while(!monotonicStack.empty() && monotonicStack.top() < currentNum){
            monotonicStack.pop();
        }

        if(!monotonicStack.empty()){
            nextGreaterMap[currentNum] = monotonicStack.top();
        }

        monotonicStack.push(currentNum);
    }

    vector<int> result;

    for(int num: nums1){
        if(nextGreaterMap.find(num) != nextGreaterMap.end()){
            result.push_back(nextGreaterMap[num]);
        }
        else{
            result.push_back(-1);
        }
    }

        return result;
    }
};