/***********************************************************
*Given a string, find the length of the longest substring without repeating characters.
*Examples:
*Given "abcabcbb", the answer is "abc", which the length is 3.
*Given "bbbbb", the answer is "b", with the length of 1.
*Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
***********************************************************/
/*
 * Idea:
 *
 * Using a map store each char's index.
 *
 * So, we can be easy to know the when duplication and the previous duplicated char's index.
 *
 * Then we can take out the previous duplicated char, and keep tracking the maxiumn length.
 *
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mymap;
        int maxsublen = 0;
        int repeatpos = -1; //repeatpos之前的数据不应该再考虑，已经是重复的数据了
        for(int i=0; i<s.length(); i++){
            if(mymap.count(s[i])==1 && mymap[s[i]]>repeatpos){
                repeatpos = mymap[s[i]];
            }
            if(i-repeatpos>maxsublen)
                maxsublen = i - repeatpos;
            mymap[s[i]] = i;
        }      
        return maxsublen;
    }
    
    int testCase(){
        string s = "abcabcbb";
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;

        s = "bbbbb";
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;

        s = "bbabcdb";
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;
        return 0;
    }
};
