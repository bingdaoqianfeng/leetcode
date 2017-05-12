/**********************************************************************************
*
* Implement wildcard pattern matching with support for '?' and '*'.
*
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
*
* The matching should cover the entire input string (not partial).
*
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
*
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
*
**********************************************************************************/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j;
        for(i = 0, j = 0; i < s.length() && j < p.length(); i++, j++){
            if(s[i] != p[j] && p[j] != '?'){
                if(p[j] != '*'){
                    return false;
                }
                else{
                    while((p[j] == '?' || p[j] == '*') && j<p.length())
                        j++;
                    if(j >= p.length())
                        return true;
                    else{
                        while(s[i] != p[j] && i<s.length()) 
                            i++;
                        if(i>=s.length())
                            return false;
                    }
                }
            }
        }
        if(i<s.length() || j<p.length())
            return false;
        return true;
    }
    int testCase(){
        string s;
        string p;
        s = "aa";
        p = "a";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;
        return 0;
    }
};
