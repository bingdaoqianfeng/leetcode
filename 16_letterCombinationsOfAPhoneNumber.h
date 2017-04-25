/**********************************************************************************
*
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
*
*
**********************************************************************************/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		char telnums[10][4]={{'\0', '\0', '\0', '\0'},//0
							{'\0', '\0', '\0', '\0'},//1
							{'a', 'b', 'c', '\0'},//2
							{'d', 'e', 'f', '\0'},//3
							{'g', 'h', 'i', '\0'},//4
							{'j', 'k', 'l', '\0'},//5
							{'m', 'n', 'o', '\0'},//6
							{'p', 'q', 'r', 's'},//7
							{'t', 'u', 'v', '\0'},//8
							{'w', 'x', 'y', 'z'},//9
							};        
    	vector<string> result;
		return result;
	}
	int testCase(){
		return 0;
	}
};
