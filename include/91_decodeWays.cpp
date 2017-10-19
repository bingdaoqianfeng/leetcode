/**********************************************************************************
*
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
*
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
*
* Given an encoded message containing digits, determine the total number of ways to decode it.
*
* For example,
* Given encoded message "12",
* it could be decoded as "AB" (1 2) or "L" (12).
*
* The number of ways decoding "12" is 2.
*
*
**********************************************************************************/
class Solution {
public:
    int check(char ch){
        return ( !isdigit(ch) || ch == '0') ? 0 : 1;
    }
    int check(char ch1, char ch2){
        //ch1,ch2是否为数字由上面的方法测试.
        return ( ch1 == '1' || (ch1 == '2' && ch2 <= '6') ) ? 1: 0;
    }

    //这里假设输入的字符串全是数字.
    int numDecodings(string s){
        int nums = 0;
        int *dp = new int[s.length()];

        if(s.length() <= 0)
            return nums;

        if(s.length() == 1)
            return 1;

        dp[0] = 1;
        dp[1] = dp[0];
        if(check(s[0], s[1]))
            dp[1] = 2;

        for(int i=2; i<s.length(); i++){
            dp[i] = dp[i-1];
            if(check(s[i-1], s[i]))
                dp[i] += dp[i-2];
        }
        nums = dp[s.length()-1];
        delete[] dp;
        return nums;
    }

    int testCase(){
        string s;
        s = "12";
        cout<<s<<": "<<numDecodings(s)<<endl;

        s = "121";
        cout<<s<<": "<<numDecodings(s)<<endl;

        s = "1212";
        cout<<s<<": "<<numDecodings(s)<<endl;
        return 0;
    }
};
