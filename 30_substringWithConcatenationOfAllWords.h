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
        if(wordsfound.size() == wordsmap.size()){
            cout<<"******"<<s<<", index"<<index<<"******"<<endl;
            map<string, int>::iterator it=wordsmap.begin(), at=wordsfound.begin();
            for(; it!=wordsmap.end();it++, at++){
                cout<<it->first<<"==>"<<it->second<<endl;
                cout<<at->first<<"==>"<<at->second<<endl;
            }
            int i;
            for(i=0; i<words.size(); i++){
                if(wordsfound[words[i]] != wordsmap[words[i]])
                    break;
            }
            if(i>=words.size()){
                result.push_back(index);
                return true;
            }
        }

        if(s.length() < len)
            return false;

        string substr = s.substr(0,len);
        //cout<<"substr: "<<substr<<"index: "<<index<<endl;
        if(wordsmap.count(substr)){
            cout<<"substr: "<<substr<<", index: "<<index<<endl;
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
        }
#if 1
        for(map<string, int>::iterator it=wordsmap.begin(); it!=wordsmap.end();it++){
            cout<<it->first<<"==>"<<it->second<<endl;
        }
#endif

        for(int i=0; i<s.length(); i++){
            //cout<<"i: "<<i<<endl;
            recursivefindSubstring(words, s.substr(i), result, len, i, wordsmap, wordsfound);
            wordsfound.clear();
        }
        return result;
    }
    int testCase(){
#if 1
        string s = "barfoothefoobarman";  //expect [0,9]
        string str[] = {"bar","foo"};
        cout<<"expect: 0,9"<<endl;
#endif
#if 0
        string s = "barfoofoobarthefoobarman";  //expect [6,9,12]
        string str[] = {"bar","foo","the"};
        cout<<"expect: 6,9,12"<<endl;
#endif
#if 0
        string s = "wordgoodgoodgoodbestword";  //expect [8]
        string str[] = {"word","good","best","good"};
        cout<<"expect: 8"<<endl;
#endif
#if 0
        string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
        string str[] = {"fooo","barr","wing","ding","wing"};
        cout<<"expect: 13"<<endl;
#endif
        vector<string> words(str, str+sizeof(str)/sizeof(string));
        printsrc(s, words);

        vector<int> result;
        result = findSubstring(s, words);
        printout(result);
        return 0;
    }
    void printout(vector<int> result){
        for(int i=0; i<result.size(); i++)
            printf("%d, ", result[i]);
        printf("\n");
    }
    void printsrc(string s,vector<string> words){
        cout<<s<<endl;
        for(int i=0; i<words.size(); i++)
            cout<<words[i]<<endl;
    }
};
