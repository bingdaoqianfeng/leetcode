/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, determine if s can be segmented 
* into a space-separated sequence of one or more dictionary words.
* 
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
* 
* Return true because "leetcode" can be segmented as "leet code".
* 
*               
**********************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {

public:

//recursion
bool wordBreakRecursion(string s, set<string> &dict) {
	if(dict.size() == 0)
		return false;
	set<string>::iterator it;
	for(it=dict.begin(); it!=dict.end(); it++){
		string str = *it;
		cout<<s<<endl;
		cout<<str<<endl;
		cout<<"------------------"<<endl;
		if(s==str)
			return true;
		if(s.compare(0,str.length(), str) == 0){
			bool ret = false;
			ret = wordBreakRecursion(s.substr(str.length()), dict);
			if(ret)
				return true;
		}
	}
	return false;
}

//dj
bool wordBreak(string s, set<string> &dict) {
    //using an array to mark subarray from 0 to i can be broken or not
    vector<bool> v(s.size(),false);

    for(int i=0; i<s.size(); i++){
        //check the substring from 0 to i is int dict or not
        string w = s.substr(0,i+1);
        v[i] = (dict.find(w)!=dict.end());

        //if it is, then use greedy algorithm
        if (v[i]) continue;

        //if it is not, then break it to check
        for(int j=0; j<i; j++){
            //if the substring from 0 to j can be borken, then check the substring from j to i
            if (v[j]==true){
                w = s.substr(j+1, i-j);
                v[i] = (dict.find(w)!=dict.end());
                if (v[i]) break;
            }
        }
    }
    return v.size() ? v[v.size()-1] : false;
}

int testCase(){
	string s;
    set<string> dict;
    
	s = "dogs";
    string d[]={"dog","s","gs"};
    dict.insert(d, d+3);
    //cout << wordBreak(s, dict) << endl;
    cout << wordBreakRecursion(s, dict) << endl;
	return 0;
}

};
