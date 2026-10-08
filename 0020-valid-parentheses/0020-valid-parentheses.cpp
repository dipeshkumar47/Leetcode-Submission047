class Solution {
public:
    bool isValid(string s) {
        
        string stack;

        for(char curr_char: s){
            
            if(curr_char == '(' || curr_char == '{' || curr_char == '[' ){
                stack.push_back(curr_char);
            }
            else if( stack.empty() || !isMatchingPair(stack.back(), curr_char)){
                return false;
            }
            else{
                stack.pop_back();
            }
        }

        return stack.empty();
    }

private:
    bool isMatchingPair(char l, char r){

        return (l == '(' && r == ')') ||
               (l == '{' && r == '}') ||
               (l == '[' && r == ']');
    }

};