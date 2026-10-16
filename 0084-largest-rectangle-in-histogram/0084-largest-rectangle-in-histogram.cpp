class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
    int n = arr.size();
    stack<int> st;

    int res = 0;
    int tp, curr;

    for (int i = 0; i < n; i++) {      
         
        while (!st.empty() && arr[st.top()] >= arr[i]) {
          
            tp = st.top(); 
            st.pop();
          

            int width = st.empty() ? i : i - st.top() - 1;
          
            res = max(res,  arr[tp] * width);
        }
        st.push(i);
    }

  
    while (!st.empty()) {
        tp = st.top(); st.pop();
        curr = arr[tp] * (st.empty() ? n : n - st.top() - 1);
        res = max(res, curr);
    }

    return res;
    }
};