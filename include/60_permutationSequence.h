/********************************************************************************** 
* 
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* 
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
* 
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* 
* Given n and k, return the kth permutation sequence.
* 
* Note: Given n will be between 1 and 9 inclusive.
*               
**********************************************************************************/
/* Extreamly Optimized */
string getPermutation(int n, int k) {
    vector<int> num;
    int total = 1;
    for(int i=1; i<=n; i++){
        num.push_back(i);
        total *= i;
    }

    //invalid k;
    if( total < k ) {
        return "";
    }

    // Construct the k-th permutation with a list of n numbers
    // Idea: group all permutations according to their first number (so n groups, each of
    // (n-1)! numbers), find the group where the k-th permutation belongs, remove the common
    // first number from the list and append it to the resulting string, and iteratively
    // construct the (((k-1)%(n-1)!)+1)-th permutation with the remaining n-1 numbers
    int group = total;
    stringstream ss;
    while (n>0) {
        group = group / n;
        int idx = (k-1) / group;
        ss << num[idx];
        num.erase(num.begin()+idx);
        n--;
        //the next k also can be caculated like this: 
        //    k = (k-1)%group + 1; 
        k -= group * idx;
    }

    return ss.str();
}
