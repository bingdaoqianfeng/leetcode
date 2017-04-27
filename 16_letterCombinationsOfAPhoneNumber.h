/**********************************************************************************
*
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
*
*
**********************************************************************************/
class Solution {
public:

    //Methord two.这个方法有两个知识点：
    //1. isdigit的使用
    //2. vector可以直接赋值 result = r。
     vector<string> letterCombinations(string digits) {
        char  phone[10][4]={ {' ',  '\0', '\0', '\0' }, //0
                         {'\0', '\0', '\0', '\0' }, //1
                         {'a',  'b',  'c',  '\0' }, //2
                         {'d',  'e',  'f',  '\0' }, //3
                         {'g',  'h',  'i',  '\0' }, //4
                         {'j',  'k',  'l',  '\0' }, //5
                         {'m',  'n',  'o',  '\0' }, //6
                         {'p',  'q',  'r',  's'  }, //7
                         {'t',  'u',  'v',  '\0' }, //8
                         {'w',  'x',  'y',  'z'  }  //9
                       };

        vector<string> result;
        if (digits.size()<=0){
            result.push_back("");
            return result;
        }
        for( int i=0; i<digits.size(); i++ ) {
            if (!isdigit(digits[i])) {
                vector<string> r;
                return r;
            }
            int d = digits[i] - '0';
            if (result.size()<=0){
                for( int j=0; j<4 && phone[d][j]!='\0'; j++ ){
                    string s;
                    s += phone[d][j];
                    result.push_back(s);
                }
                continue;
            }
            vector<string> r;
            for (int j=0; j<result.size(); j++){
                for( int k=0; k<4 && phone[d][k]!='\0'; k++ ){
                    string s = result[j] + phone[d][k];
                    //sort(s.begin(), s.end());
                    r.push_back(s); 
                }
            }
            result = r;
        }
        //sort(result.begin(), result.end());
        return result; 
    }

	
	void combinationstr(vector<string> &result, string digits, string str){
		char telnums[10][4]={{'\0', '\0', '\0', '\0'},//0
							{'\0', '\0', '\0', '\0'},//1
							{'a', 'b', 'c', '\0'},//2
							{'d', 'e', 'f', '\0'},//3
							{'g', 'h', 'i', '\0'},//4
							{'j', 'k', 'l', '\0'},//5
							{'m', 'n', 'o', '\0'},//6
							{'p', 'q', 'r', 's'},//7
							{'t', 'u', 'v', '\0'},//8
							{'w', 'x', 'y', 'z'},//9
							};        
		if(digits.length() == 0){
			result.push_back(str);
			//cout<<str<<endl;
			return;
		}

		string temp = digits.substr(0,1);	
		int num = atoi(temp.c_str());
		for(int i=0; i<4; i++){
			string a;
			if(telnums[num][i] == '\0')
				break;
			else
				a = telnums[num][i];
			a = str + a;
			combinationstr(result, digits.substr(1), a);
		}	
		return;
	}
	
    vector<string> letterCombinations(string digits) {
		vector<string> result;
		string str;
		if(digits.length() == 0)
			return result;		
		combinationstr(result, digits, str);	
		return result;
	}
	int testCase(){
		//vector<string> result = letterCombinations("23");
		vector<string> result = letterCombinations("2");
		//vector<string> result = letterCombinations("123");
		for(int i=0; i<result.size(); i++)
			cout<<result[i]<<endl;
		return 0;
	}
};
