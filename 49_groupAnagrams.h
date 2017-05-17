/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/
class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
 		vector< vector<string> > result;
		return result;        
    }
	int testCase(){
		string s[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
		vector<string> strs(s, s+6);
		printVector(strs);
		return 0;
	}
	void printVector( vector<string>&  pt)
    {
        cout << "{ ";
        for(int j=0; j<pt.size(); j++){
            cout << pt[j] << "  ";
        }
        cout << "} " << endl;
    }
};
