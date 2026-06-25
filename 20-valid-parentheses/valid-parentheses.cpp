class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;

        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            if(ch=='{' || ch=='(' || ch=='['){
                sk.push(ch);
            }else{
                if(sk.empty()){
                    return false;
                }

                int top=sk.top();
                if((top=='(' && ch==')')||
                    (top=='{' && ch=='}')||
                    (top=='[' && ch==']')){
                        sk.pop();
                    }else{
                        return false;
                }
            }
        }
        return sk.empty();
    }
};