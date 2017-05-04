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
	bool recursivefindSubstring(vector<string> words, string s, vector<int>& result, int len, int index,  map<string, int> wordsmap, map<string, int> wordsfound){
		//cout<<"******"<<s<<"******"<<endl;
		if(s.length() < len ||
		   wordsfound.size() == wordsmap.size()){
			int i;
			for(i=0; i<words.size(); i++){
				if(wordsfound[words[i]] != wordsmap[words[i]])
					break;
			}
			if(i>=words.size()){	
				result.push_back(index);
				return true;
			}
			return false;
		}

		string substr = s.substr(0,len);
		//cout<<"substr: "<<substr<<"index: "<<index<<endl;
		if(wordsmap.count(substr)){
			if(!wordsfound.count(substr)){
				wordsfound[substr] = 1;
				return recursivefindSubstring(words, s.substr(len), result, len, index, wordsmap, wordsfound);
			}
			else if(wordsfound[substr] < wordsmap[substr]){
				wordsfound[substr] += 1;
				return recursivefindSubstring(words, s.substr(len), result, len, index, wordsmap, wordsfound);
			}
		}
		return false;
	}
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if(s.length() == 0 || words.size() == 0)
			return result;
		int len = words[0].length();
		map<string, int> wordsmap;
		map<string, int> wordsfound;
		for(int i=0; i<words.size(); i++){
			if(wordsmap.count(words[i])){
				wordsmap[words[i]] += 1;
			}
			else{
				wordsmap[words[i]] = 1;
			}
			//cout<<wordsmap[words[i]]<<endl;
		}

		for(int i=0; i<s.length(); i++){
			//cout<<"i: "<<i<<endl;
			recursivefindSubstring(words, s.substr(i), result, len, i, wordsmap, wordsfound);
			wordsfound.clear();
		}	
		return result;       
    }
	int testCase(){
#if 0
		string s = "barfoothefoobarman";  //expect [0,9]
		string a = "foo";
		string b = "bar";
#endif
#if 1
		string s = "barfoofoobarthefoobarman";  //expect [6,9,12]
		string a = "bar";
		string b = "foo";
		string c = "the";
#endif
#if 0
		string s = "wordgoodgoodgoodbestword";  //expect [8]
		string a = "word";
		string b = "good";
		string c = "best";
		string d = "good";
#endif
		vector<string> words;
		words.push_back(a);
		words.push_back(b);
		words.push_back(c);
//		words.push_back(d);

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
