/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/
vector<int> plusOne(vector<int> &digits) {
    int carry=1;
    vector <int> v;
    while(digits.size()>0){
        int x = digits.back();
        digits.pop_back();
        x = x + carry;
        v.insert(v.begin(), x%10);
        carry = x/10;
    }
    if (carry>0){
        v.insert(v.begin(), carry);
    }
    return v;

}

class Solution {
public:
	int testCase(){
        int n=3;
        vector< vector<int> > matrix = generateMatrix(n, n);
        printVV(matrix);
        return 0;
    }
};	
