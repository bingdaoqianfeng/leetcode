/*******************************************************************************
*Given a string s, find the longest palindromic substring in s. 
*You may assume that the maximum length of s is 1000.
*Example:
*Input: "babad"
*Output: "bab"
*Note: "aba" is also a valid answer.
*Example:
*Input: "cbbd"
*Output: "bb"
********************************************************************************/
class Solution {
private:
	string findPalindrome(string s, int left, int right){
		int indexleft, indexright;
		indexleft = indexright = left;
		while(left>=0 && right<s.length() && s[left]==s[right]){
				indexleft = left;
				indexright = right;
				left--;
				right++;
		}
		return s.substr(indexleft, (indexright-indexleft+1));
	}
public:
    string longestPalindrome(string s) {
		string longest;
		for(int i = 0; i<s.length(); i++){
			//for ***X***
			string str = findPalindrome(s, i, i);
			if(str.length()>longest.length())
				longest = str;
			//for ***XX***
			if(i<s.length()-1 && s[i]==s[i+1]){
				string str = findPalindrome(s, i, i+1);
				if(str.length()>longest.length())
					longest = str;
			}
		}
		return longest;	    
    }
	int testCase(){
		string s = "abacdfgdcaba";
    	cout << s << " : " << longestPalindrome(s) << endl;
    
    	s = "321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123";
    	cout <<  s << " : " << longestPalindrome(s) << endl;
    	return 0;	
	}
};
