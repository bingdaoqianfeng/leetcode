/**********************************************************************************
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid
* but "(]" and "([)]" are not.
*
**********************************************************************************/
class Solution {

public:

    bool isValid(string s) {
        stack<char> mystack;
        for(int i=0; i<s.length(); i++){
            if(!mystack.empty()){
                switch(mystack.top()){
                    case '(':
                        if(s[i] == ')')
                            mystack.pop();
                        else
                            mystack.push(s[i]);
                        break;
                    case '[':
                        if(s[i] == ']')
                            mystack.pop();
                        else
                            mystack.push(s[i]);
                        break;
                    case '{':
                        if(s[i] == '}')
                            mystack.pop();
                        else
                            mystack.push(s[i]);
                        break;
                }
            }
            else{
                mystack.push(s[i]);
            }
        }

        return mystack.empty();
    }
    int testCase(){
        bool ret;
        string str;
        str = "()[]{}";
        ret = isValid(str);
        cout<<str<<":"<<ret<<endl;

        str = "([]{}";
        ret = isValid(str);
        cout<<str<<":"<<ret<<endl;
        return 0;
    }
};
