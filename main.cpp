#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

/****************finished*******************/
//#include "3_LongestSubstringWithoutRepeatingCharacters.hpp"
//#include "4_medianOfTwoSortedArrays.hpp"
//#include "5_longestPalindromicSubstring.hpp"
//#include "6_zigZagConversion.hpp"
//#include "7_reverseInteger.hpp"
//#include "8_stringToIntegerAtoi.h"
//#include "9_palindromeNumber.h"
//#include "10_regularExpressionMatching.h"
//#include "11_containerWithMostWater.h"
//#include "14_longestCommonPrefix.h"
//#include "3Sum.h"
//#include "15_3SumClosest.h"
//#include "16_letterCombinationsOfAPhoneNumber.h"
//#include "18_removeNthNodeFromEndOfList.h"
//#include "20_validParentheses.h"
//#include "22_generateParentheses.h"
//#include "23_mergeKSortedLists.h"
//#include "24_swapNodesInPairs.h"
//#include "25_reverseNodesInKGroup.h"
//#include "36_validSudoku.h"
//#include "37_sudokuSolver.h"
//#include "39_combinationSum.h"
//#include "29_divideTwoInt.h"
//#include "30_substringWithConcatenationOfAllWords.h"
//#include "33_searchInRotatedSortedArray.h"
//#include "34_searchForRange.h"
//#include "40_combinationSum.II.h"
//#include "42_trappingRainWater.h"
//#include "41_firstMissingPositive.h"
//#include "44_wildcardMatching.h"
//#include "45_jumpGame.II.h"
//#include "46_permutations.h"
//#include "47_permutations.II.h"
//#include "48_rotateImage.h"
//#include "49_groupAnagrams.h"
//#include "50_pow.h"
//#include "51_nQueuens.h"
//#include "52_nQueuens_II.h"
//#include "53_maximumSubArray.h"
//#include "54_spiralMatrix.h"
//#include "55_jumpGame.h"

/****************to be continue*****************/
//#include "56_mergeIntervals.h"
#include "1_twoSum.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printVector( vector<string>&  pt);
void printVectorVector(vector< vector<string> >& v);
void printMatrix(vector< vector<int> > &matrix);
void printList(ListNode *head);
void createMatrix();
void createBoard();
void createList();
void createVector();
vector< vector<int> > createVV(int a[], int len, int n);

int main(int argc, char** argv)
{
    Solution mysolution;
    mysolution.testCase();

    //how to init  two-dimensional array
    int n = 3;
    vector< vector<int> > chessboard(n, vector<int>(n, 0));

    return 0;
}

void printList(ListNode *head){
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void createVector()
{
    const char* s[]={"bbab","aba","abc"};
    vector<string> v(s, s+3);
    printVector(v);

    int a[]={-1, 2, 1, -4};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
}

void createList()
{ //23_mergeKSortedLists.h
    ListNode head(-1);
    ListNode *ptr = NULL;
    int a[] = {1,2,3,4,5};
    //create list
    int len = sizeof(a)/sizeof(int);
    ptr = &head;
    for(int i=0; i<len; i++){
        ListNode *node = new ListNode(a[i]);
        ptr->next = node;
        ptr = node;
    }
    printList(head.next);
}

void createBoard(){
    vector< vector<char> > board(9);
    vector<string> s(9);
    s[0] = "53..7....";
    s[1] = "6..195...";
    s[2] = ".98....6.";
    s[3] = "8...6...3";
    s[4] = "4..8.3..1";
    s[5] = "7...2...6";
    s[6] = ".6....28.";
    s[7] = "...419..5";
    s[8] = "....8..79";
    for(int i = 0; i<9; i++){
        string str = s[i];
        board[i].resize(9);
        for(int j=0; j<9; j++){
            //printf("%c ", str[j]);
            board[i][j] = str[j];
        }
    }
}

vector< vector<int> > createVV(int a[], int len, int n){
        vector< vector<int> > matrix;
        printf("len: %d, n: %d\n", len, n);
        vector<int> row;
        for(int i=1; i<=len; i++){
            row.push_back(a[i-1]);
            if(i%n == 0){
                matrix.push_back(row);
                row.clear();
            }
        }
        return matrix;
}

void createMatrix(){
    int n = 5;
    vector< vector<int> > matrix;
    for (int i=1; i<=n; i++) {
        vector<int> v;
        for(int j=1; j<=n; j++){
            v.push_back( (i-1)*n + j );
        }
        matrix.push_back(v);
    }
}

void printMatrix(vector< vector<int> > &matrix)
{
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        cout << endl;
    }
    cout << endl;
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
