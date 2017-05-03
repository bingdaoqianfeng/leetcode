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
	bool recursivefindSubstring(string s, vector<int>& result, int len, int index,  map<string, int> wordsmap, map<string, int> wordsfound){
		if(s.length() < len ){
			return false;
		}
		if(wordsfound.size() == wordsmap.size()){
			result.push_back(index);
			return true;
		}

		string substr = s.substr(0,len);
		cout<<"substr: "<<substr<<"index: "<<index<<endl;
		if(wordsmap.count(substr)){
			if(!wordsfound.count(substr)){
				wordsfound[substr] = 1;
				return recursivefindSubstring(s.substr(len), result, len, index, wordsmap, wordsfound);
			}
			return false;
		}
		else{
			return false;
		}
	}
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if(s.length() == 0 || words.size() == 0)
			return result;
		int len = words[0].length();
		map<string, int> wordsmap;
		map<string, int> wordsfound;
		for(int i=0; i<words.size(); i++){
			wordsmap[words[i]] = 1;
		}

		for(int i=0; i<s.length();){
			cout<<"i: "<<i<<endl;
			if(recursivefindSubstring(s.substr(i), result, len, i, wordsmap, wordsfound)){
				//i += len*words.size();
				i++;
			}
			else
				i++;
			wordsfound.clear();
		}	
		return result;       
    }
	int testCase(){
		//string s = "barfoothefoobarman";
		//string a = "foo";
		//string b = "bar";
		
		//string s = "barfoofoobarthefoobarman";
		//string a = "bar";
		//string b = "foo";
		//string c = "the";
		
		string s = "wordgoodgoodgoodbestword";
		string a = "word";
		string b = "good";
		string c = "best";
		string d = "good";
		vector<string> words;
		words.push_back(a);
		words.push_back(b);
		words.push_back(c);
		words.push_back(d);

		if(a == b)
			cout<<"a == b"<<endl;
		else
			cout<<"a != b"<<endl;
		
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
