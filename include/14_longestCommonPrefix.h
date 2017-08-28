/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
*
**********************************************************************************/
class Solution {

public:

    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.size()<1)
            return result;
        int j = 0;
        while(j<strs[0].length()){
            for(int i=1; i<strs.size(); i++){
                if((j<strs[i].length() && strs[i][j] != strs[0][j]) ||
                    j>=strs[i].length()){
                    return result;
                }
            }
            result += strs[0][j];
            j++;
        }
        return result;
    }

    int testCase(){
        const char* s[]={"abab","aba","abc"};
        vector<string> v(s, s+3);
        //const char* s[]={"bbab","aba","abc"};
        //vector<string> v(s, s+3);
		printVector(v);
        cout << longestCommonPrefix(v) <<endl;
		return 0;
    }
	void printVector( vector<string>&  pt)
	{
    	cout << "[ ";
    	for(int j=0; j<pt.size(); j++){
        	cout << pt[j] << "  ";
    	}
    	cout << "] " << endl;
	}
};
