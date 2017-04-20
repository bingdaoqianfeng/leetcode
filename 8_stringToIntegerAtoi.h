/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge,
*       please do not see below and ask yourself what are the possible input cases.
*
* Notes:
*   It is intended for this problem to be specified vaguely (ie, no given input specs).
*   You are responsible to gather all the input requirements up front.
*
*
* Requirements for atoi:
*
* The function first discards as many whitespace characters as necessary until the first
* non-whitespace character is found. Then, starting from this character, takes an optional
* initial plus or minus sign followed by as many numerical digits as possible, and interprets
* them as a numerical value.
*
* The string can contain additional characters after those that form the integral number,
* which are ignored and have no effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral number,
* or if no such sequence exists because either str is empty or it contains only whitespace
* characters, no conversion is performed.
*
* If no valid conversion could be performed, a zero value is returned. If the correct value
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
* is returned.
*
**********************************************************************************/
#include <stdio.h>
#include <stdint.h>

class Solution {
public:
    int myAtoi(string str) {
        //return atoi(str.c_str());
        int retval = 0;
        int flag = 1;
        for(int i=0; i<str.length(); i++){
            if(str[i] == ' '){
                continue;
            }
            if(retval == 0 && (str[i] == '-' || str[i] == '+')){
                if(str[i] == '-') flag = -1;
                continue;
            }
            if(str[i]>'9' || str[i]<'0'){
                break;
            }
            if(retval*flag>INT32_MAX/10 ||
               (retval*flag==INT32_MAX/10 && (INT32_MAX%10<=(str[i]-'0'))))
                return INT32_MAX;

            if(retval*flag < INT32_MIN/10 ||
               (retval*flag==INT32_MIN/10 && (INT32_MIN%10>=(str[i]-'0')*flag)))
                return INT32_MIN;

            retval = retval*10 + str[i] - '0';
        }
        return retval*flag;
    }
    int testCase(){
        string teststr;
        teststr = "123";
        printf("\"%s\" = %d\n", "123", myAtoi("123"));
        printf("\"%s\" = %d\n", "1 2 3", myAtoi("1 2 3"));
        printf("\"%s\" = %d\n", "   123", myAtoi("    123"));
        printf("\"%s\" = %d\n", "+123", myAtoi("+123"));
        printf("\"%s\" = %d\n", " -123", myAtoi(" -123"));
        printf("\"%s\" = %d\n", "123ABC", myAtoi("123ABC"));
        printf("\"%s\" = %d\n", " abc123ABC", myAtoi(" abc123ABC"));
        printf("\"%s\" = %d\n", "2147483647", myAtoi("2147483647"));
        printf("\"%s\" = %d\n", "-2147483648", myAtoi("-2147483648"));
        printf("\"%s\" = %d\n", "2147483648", myAtoi("2147483648"));
        printf("\"%s\" = %d\n", "-2147483649", myAtoi("-2147483649"));
        return 0;
    }
};
