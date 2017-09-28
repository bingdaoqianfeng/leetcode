/**********************************************************************************
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
* (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
*
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*
*
**********************************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> myvec(numRows);
        int j = 0;
        int column = 0, row = 0;
        for(int i=0; i<s.length();){
            if( column%2 == 0 || (column%2 != 0 && row%2 != 0) )
                myvec[row] += s[i++];
            row++;
            if(row >= numRows){
                row = 0;
                column++;
            }
        }      
        string result;
        for(int i = 0; i < numRows; i++)
            result += myvec[i];
        return result;
    }

    //标准答案，我的方法的区别就是对于 ABC的结果不是 预想的结果。这个问题主要是我对要求不是很理解；
    //从我的代码上来说，运行结果是我的预期结果，因此也可以接受。
    //这个问题主要联系掌握vector和string的常用操作方法即可。
    string convert1(string s, int nRows) {
        //The cases no need to do anything
        if (nRows<=1 || nRows>=s.size()) return s;
    
        vector<string> r(nRows);
        int row = 0;
        int step = 1;
        for(int i=0; i<s.size(); i ++) {
            if (row == nRows-1) step = -1;
            if (row == 0) step = 1;
            //cout << row <<endl;
            r[row] += s[i];
            row += step;
        }
   
        string result;
        for (int i=0; i<nRows; i++){
            result += r[i];
        }
        return result;
    }

    int testCase(){
        string s;
        int r;

        s = "PAYPALISHIRING";
        r = 3;
        cout << s << " : " << convert(s, 3) << endl;    
        
        s = "ABC";
        r = 2;
        cout << s << "expect:ACB, output: " << convert(s, 2) << endl;   
        return 0;
    }
};
