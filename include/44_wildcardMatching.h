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
        int last_s = -1, last_p = -1;
        for(i = 0, j = 0; i<s.length();){
            if(j<p.length() && (s[i] == p[j] || p[j] == '?')){
                i++;
                j++;
                if(i>=s.length() && j>=p.length())
                    return true;
            }
            else if(j<p.length() && p[j] == '*'){
                //edge case
                if(j + 1 >= p.length())
                    return true;
                //skip the "*", and mark a flag
                j++;
                //use last_s and last_p to store where the "*" match starts.
                last_p = j;
                last_s = i;
            }
            else if(last_p != -1){
                // if meet "*" previously, and the *s != *p
                // reset the p, using '*' to match this situation
                last_s++;
                i = last_s;
                j = last_p;
            }
            else{
                return false;
            }
        }
        //edge case: "s" is done, but "p" still have chars. 
        while(j<p.length() && p[j] == '*') j++;
        if(j<p.length())    return false;
        return true;
    }
    bool isMatchOne(string s, string p) {
        int i, j;
        //cout<<"s: "<<s<<"  p: "<<p<<endl;
        if((s.length() == 0 && p.length() == 0) ||
            (p.length() == 1 && p[0] == '*'))
            return true;

        for(i = 0, j = 0; i < s.length() && j < p.length(); i++, j++){
            if(s[i] != p[j] && p[j] != '?'){
                if(p[j] != '*'){
                    return false;
                }
                else{
                    while(j<p.length() && p[j] == '*')
                        j++;
                    if(j >= p.length())
                        return true;
                    do{
                        //printf("s[%d]: %c, p[%d]: %c\n", i, s[i], j, p[j]);
                        while(s[i] != p[j] && p[j] != '?' && i<s.length()) 
                            i++;
                        if(i>=s.length())
                            return false;

                        if(isMatchOne(s.substr(i),p.substr(j)))
                            return true;
                        i++;
                    }while(i<s.length());
                }
            }
        }
        while(j<p.length()){
            if(p[j] == '*')
                j++;
            else
                break;
        }
        if(i<s.length() || j<p.length())
            return false;
        return true;
    }
    int testCase(){
        string s, p;
        bool ret;
        s = "c";
        p = "*?*";
        ret = isMatch(s,p);
        cout<<s<<" == "<<p<<" is "<<ret<<endl;
#if 1
        s = "b";
        p = "*?*?";
        ret = isMatch(s,p);
        cout<<s<<" == "<<p<<" is "<<ret<<endl;
        
        s = "a";
        p = "a*";
        ret = isMatch(s,p);
        cout<<s<<" == "<<p<<" is "<<ret<<endl;

        s = "aaaa";
        p = "***a";
        ret = isMatch(s,p);
        cout<<s<<" == "<<p<<" is "<<ret<<endl;

        s = "abefcdgiescdfimde";
        p = "ab*cd?i*de";
        ret = isMatch(s,p);
        cout<<s<<" == "<<p<<" is "<<ret<<endl;
        
        s = "aa";
        p = "a";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;

        s = "aa";
        p = "aa";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;
        
        s = "aaa";
        p = "aa";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;
        
        s = "aa";
        p = "*";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;
        
        s = "aa";
        p = "a*";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;

        s = "ab";
        p = "?*";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;
        
        s = "aab";
        p = "c*a*b";
        cout<<s<<" == "<<p<<" is "<<isMatch(s,p)<<endl;
#endif     
       return 0;
    }
};
