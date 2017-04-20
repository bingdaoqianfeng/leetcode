/**********************************************************************************
*
* Determine whether an integer is a palindrome. Do this without extra space.
*
*
* Some hints:
*
* Could negative integers be palindromes? (ie, -1)
*
* If you are thinking of converting the integer to string, note the restriction of using extra space.
*
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
* you know that the reversed integer might overflow. How would you handle such case?
*
* There is a more generic way of solving this problem.
*
*
**********************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
		
		if(x<0) //for leetcode,it think negatie intergers is not palindrome. so add this.
			return false;		

		vector<int> myvector;
		int val = x;
		while(val){
			myvector.push_back(val%10);
			val = val/10;
		}
		int i=0, j=myvector.size()-1;
		while(i<=j){
			if(myvector[i] != myvector[j]){
				return false;
			}
			i++;
			j--;
		} 
		return true;
    }

	int testCase(){
		printf("1 is %d \n", isPalindrome(1));
		printf("11 is %d \n", isPalindrome(11));
		printf("12 is %d \n", isPalindrome(12));
		printf("67899876 is %d \n", isPalindrome(67899876));
		printf("6789876 is %d \n", isPalindrome(6789876));
		printf("%d is %d\n", 2147447412, isPalindrome(2147447412) );
		printf("%d is %d\n", -2147447412, isPalindrome(-2147447412) );
		return 0;
	}
};
