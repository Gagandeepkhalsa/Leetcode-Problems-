class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }
            else{
                if(stk.empty()) return false;
                if(stk.top() == '(' && ch != ')' ||
                    stk.top() == '[' && ch != ']' ||
                    stk.top() == '{' && ch != '}'){
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.empty()) return true;
        else return false;
    }
};