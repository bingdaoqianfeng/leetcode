/**********************************************************************************
*
* You are given a string, S, and a list of words, L, that are all of the same length.
* Find all starting indices of substring(s) in S that is a concatenation of each word
* in L exactly once and without any intervening characters.
*
* For example, given:
* S: "barfoothefoobarman"
* L: ["foo", "bar"]
*
* You should return the indices: [0,9].
* (order does not matter).
*
*
**********************************************************************************/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    }
	int testCase(){
		string s = "barfoothefoobarman";
		string a = "foo";
		string b = "bar";
		vector<string> words;
		words.push_back(a);
		words.push_back(b);
		
		vector<int> result;
		result = findSubstring(s, words);
		printout(s, words, result);
		return 0;
	}
	void printout(string s,vector<string> words, vector<int> result){
		cout<<s<<endl;
		for(int i=0; i<words.size(); i++)
			cout<<words[i]<<endl;
		for(int i=0; i<result.size(); i++)
			printf("%d", result[i]);
		printf("\n");
	}
};
