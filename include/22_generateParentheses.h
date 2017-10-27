/**********************************************************************************
*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* "((()))", "(()())", "(())()", "()(())", "()()()"
*
**********************************************************************************/
class Solution {
public:
    void generateParenthesis(vector<string> &result, string s, int left, int right) {
        if(left == 0 && right == 0){
            result.push_back(s);
            return;
        }
        if(left > 0){
            generateParenthesis(result, s+"(", left-1, right);
        }
        if(right > 0 && left<right){
            generateParenthesis(result, s+")", left, right-1);
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generateParenthesis(result, s, n, n);
        return result;
    }

    int testCase(){
        vector<string> result;
        int n;
        n=3;
        result = generateParenthesis(n);
        for(int i=0; i<result.size(); i++){
            cout<<result[i]<<endl;
        }
        return 0;
    }
};
