/********************************************************************************** 
*
* Implement regular expression matching with support for '.' and '*'.
*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
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
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
*
*这道题我想复杂了，认为s,p都可能含有变量，其实只有p才含有变量。
*
**********************************************************************************/
class Solution {

public:
	bool isMyMatch(string s, string p){
		if(p.length() == 0) //递归的退出条件就是P到结尾。
			return s.length()==0;

		//p's length 1 is apecial case
		if(p.length() == 1){
			if(p[0] == '*')
				return true;
			if(s.length()<1)
				return false;
			if(p[0] != s[0] && p[0] != '.')
				return false;
			return isMyMatch(s.substr(1), p.substr(1));	
		}
		
		if(p[1] != '*'){
			if(p[0] == '*')
				return true;
			if(s.length()<1)
				return false;
			if(p[0] != s[0] && p[0] != '.')
				return false;
			return isMyMatch(s.substr(1), p.substr(1));	
		}
		else{
			//the second is *.
			if(p[0]!=s[0] && p[0] != '.')
				return false;
			if(p.length() == 2)
				return true;
			int i = 1;
			int len = s.length();
			while(i<len){
				if(isMyMatch(s.substr(i), p.substr(2)))
					return true;
				i++;
			}		
		}
		return false;
	}	

	bool isMatchNew(const char *s, const char *p) {
    	if (*p=='\0') {
        	return *s == '\0';
    	}
    	//p's length 1 is special case
    	if (*(p+1) == '\0' || *(p+1) !='*' ) {
        	if (*s=='\0' || ( *p !='.' && *s != *p )) {
            	return false;
        	}
        	return isMatchNew(s+1, p+1);
    	}
    	int len = strlen(s);
    	int i = -1;
    	while (i < len && (i <0 || *p=='.' || *p==*(s+i)) ){
        	if (isMatchNew(s+i+1, p+2)) {
            	return true;
        	}
        	i++;
    	}
    	return false;
	}
    bool isMatch(string s, string p) {
		//这个网上一个人的解题结果，我认为是有问题的，没有考虑完全.
    	//base case
        if(p.length() == 0){
            return s.length() == 0;
        }
         
        //special case
        if(p.length() == 1){
             
            //if the length of s is 0, return false
            if(s.length() < 1){
                return false;
            }
             
            /*if the first char of s and the first char of p is not the same, 
            and the char of p is not '.', return false */
            else if((p[0] != s[0]) && (p[0] != '.')){
                return false;
            }
             
            //otherwise, compare the rest of the string of s and p.
            else{
                return isMatch(s.substr(1), p.substr(1));
            }
        }
        //case 1: when the second char of p is not '*', easy case.
        if(p[1] != '*'){
            if(s.length() < 1){
                return false;
            }
            if((p[0] != s[0]) && (p[0] != '.')){
                return false;
            }
            else{
                return isMatch(s.substr(1), p.substr(1));
            }
        }
        //case 2: when the second char of p is '*', complex case.
        else{
             
            //when the '*' stands for 0 preceding element
            if(isMatch(s, p.substr(2))){ //"abc","d*abc" ?
                return true;
            }
             
            /*when the '*' stands for 1 or more preceding element,
            try every possible number*/
            int i = 0;
            while(i < s.length() && (s[i] == p[0] || p[0] == '.')){
                if(isMatch(s.substr(i+1), p.substr(2))){
                    return true;
                }
                i++;
            }
            return false;
        }
	}

	void func1(){
		string s, p;
		s = "aa"; p="a";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "aaaaabc"; p="a*bc";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "aaaaabc"; p="a*bcd";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abc"; p="*";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abc"; p="*c";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abcdef"; p="ab*f";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abbbbbf"; p="ab*f";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abababf"; p="ab*f";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "ab"; p=".*";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abc"; p=".*";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
		s = "abc"; p="d*abc";
        cout << s << ", " << p << " : " << isMatch(s,p) << endl;
	}

	void func2(){
		string s, p;
		s = "abc"; p=".*";
        cout << s << ", " << p << " : " << isMatchNew("abc",".*") << endl;
		s = "abbbbbf"; p="ab*f";
        cout << s << ", " << p << " : " << isMatchNew("abbbbbf","ab*f") << endl;
		s = "abababf"; p="ab*f";
        cout << s << ", " << p << " : " << isMatchNew("abababf","ab*f") << endl;
		s = "abc"; p="d*abc";
        cout << s << ", " << p << " : " << isMatchNew("abababf","ab*f") << endl;
	}
	
	void func3(){
		string s, p;
		s = "aa"; p="a";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "aaaaabc"; p="a*bc";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "aaaaabc"; p="a*bcd";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abc"; p="*";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abc"; p="*c";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abcdef"; p="ab*f";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abbbbbf"; p="ab*f";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abababf"; p="ab*f";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "ab"; p=".*";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abc"; p=".*";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
		s = "abc"; p="d*abc";
        cout << s << ", " << p << " : " << isMyMatch(s,p) << endl;
	}

    int testCase(){
        func1();
		cout << "**************************" << endl;
		func2();
		cout << "**************************" << endl;
		func3();
		return 0;
    }
};
