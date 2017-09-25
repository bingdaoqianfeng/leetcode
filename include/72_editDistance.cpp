/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
* 
*               
**********************************************************************************/
class Solution {
public:
    int testCase(){
        string word1="abb", word2="abccb";
		int steps = minDistance(word1, word2);

		cout << word1 << ", " << word2 << " : " << steps << endl;
		return 0;
    }
};
