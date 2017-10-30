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
        vector< vector<int> > record;
        for(int i=0; i<strs.size(); i++){
            vector<int> strtonums;
            for(int j=0; j<strs[i].length(); j++){
                strtonums.push_back(strs[i][j]);
            }
            sort(strtonums.begin(), strtonums.end());
            int k;
            for(k = 0; k<record.size(); k++){
                if(record[k] == strtonums){
                    result[k].push_back(strs[i]);
                    break;
                }
            }
            if(k >= record.size()){
                record.push_back(strtonums);
                vector<string> s;
                s.push_back(strs[i]);
                result.push_back(s);
            }

        }
        return result;
    }
    int testCase(){
        string s[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
        vector<string> strs(s, s+6);
        printVector(strs);

        vector< vector<string> > result;
        result = groupAnagrams(strs);
        printVectorVector(result);
        return 0;
    }
    void printVectorVector(vector< vector<string> >& v)
    {
        cout << "[ " <<endl;
        for(int j=0; j<v.size(); j++){
            printVector(v[j]);
        }
        cout << "] " << endl;
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
