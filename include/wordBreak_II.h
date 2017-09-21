/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence 
* where each word is a valid dictionary word.
* 
* Return all such possible sentences.
* 
* For example, given
* s = "catsanddog",
* dict = ["cat", "cats", "and", "sand", "dog"].
* 
* A solution is ["cats and dog", "cat sand dog"].
* 
*               
**********************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {

public:
// ---------------
//  Recursive Way
// ---------------
// The recursive method is quite straight forward.
//
//    1) if a substring from 0 to i is a word, then take the rest substring to evaluate. 
//    2) during the recursion, keep tracking the result
//
//  For example:
//
//    s = "catsanddog",
//    dict = ["cat", "cats", "and", "sand", "dog"].
//
//       
//                            +---> sand / dog ---> dog           
//                            |                   
//         +-------> cat / sanddog                 
//         |                                      
//       catsanddog                               
//          |                                     
//          +------> cats / anddog                  
//                            |                    
//                            +----> and / dog ---> dog           
//       
//
// However, the recursive could produce a lot duplicated calculation, we need use a cache to avoid.
//

//To avoid time limit error, need to add cache
//recursion
void wordBreak(string s, set<string> &dict, string str, vector<string>& result) {

    string org_str = str;

    for(int i=0; i<s.size(); i++){
        string w = s.substr(0,i+1);

        // if the current substring is a word
        if (dict.find(w)!=dict.end()) {
            str = org_str;
            if (str.size()>0){
                str +=" ";
            }
            str = str + w;

            // foud the solution, add it into the result
            if (i==s.size()-1){
                result.push_back(str);
                return;
            }

            //recursively to solve the rest subarray
            wordBreak(s.substr(i+1, s.size()-i-1), dict, str, result);
        }
    }
}


//---------------------
// Dynamic Programming
//---------------------
//
//  Define substring[i, j] is the sub string from i to j.
//
//       (substring[i,j] == word) :   result[i] = substring[i,j] + {result[j]}
//
//      So, it's better to evaluate it backword. 
//
//  For example:
//
//    s = "catsanddog",
//    dict = ["cat", "cats", "and", "sand", "dog"].
//  
//       0  c  "cat"  -- word[0,2] + {result[3]}  ==> "cat sand dog"
//             "cats" -- word[0,3] + {result[4]}  ==> "cats and dog" 
//       1  a  ""
//       2  t  ""
//       3  s  "sand" --  word[3,6] + {result[7]} ==> "sand dog"
//       4  a  "and"  --  word[4,6] + {result[7]} ==> "and dog"
//       5  n  ""
//       6  d  ""
//       7  d  "dog"
//       8  o  ""
//       9  g  ""
vector<string> wordBreak_dp(string s, set<string> &dict) {
    vector< vector<string> > result(s.size());

    for(int i=s.size()-1; i>=0; i--) {
        vector<string> v;
        result[i] = v;
        for(int j=i+1; j<=s.size(); j++) {
            string word = s.substr(i, j-i);
            if (dict.find(word) != dict.end()){
                if (j==s.size()){
                    result[i].push_back(word);
                }else{
                    for(int k=0; k<result[j].size(); k++){
                        result[i].push_back(word + " " + result[j][k]);
                    }
                }
            }
        }
    }

    return result[0];
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
