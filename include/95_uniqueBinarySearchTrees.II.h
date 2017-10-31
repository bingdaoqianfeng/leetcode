/**********************************************************************************
*
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
*
* For example,
* Given n = 3, there are a total of 5 unique BST's.
*
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
*
** OJ's Binary Tree Serialization:
*
* The serialization of a binary tree follows a level order traversal, where '#' signifies
* a path terminator where no node exists below.
*
* Here's an example:
*
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
*
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>


class Solution {
public:
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int n) {

    vector<TreeNode*> v;
    v = generateTrees(1, n);
    return v;
}

/*
”这道题是求解所有可行的二叉查找树，从Unique Binary Search Trees中我们已经知道，可行的二叉查找树的数量是相应的卡特兰数，不是一个多项式时间的数量级，所以我们要求解所有的树，自然是不能多项式时间内完成的了。算法上还是用求解NP问题的方法来求解，也就是N-Queens中
介绍的在循环中调用递归函数求解子问题。思路是每次一次选取一个结点为根，然后递归求解左右子树的所有结果，最后根据左右子树的返回的所有子树，依次选取
然后接上（每个左边的子树跟所有右边的子树匹配，而每个右边的子树也要跟所有的左边子树匹配，总共有左右子树数量的乘积种情况），构造好之后作为当前树的
结果返回。
“
这道题的解题依据依然是：
当数组为 1，2，3，4，.. i，.. n时，基于以下原则的BST建树具有唯一性：
以i为根节点的树，其左子树由[1, i-1]构成， 其右子树由[i+1, n]构成。 
*/
vector<TreeNode*> generateTrees(int low, int high){
    vector<TreeNode*> v;
    if (low > high || low<=0 || high<=0){
        v.push_back(NULL);
        return v;
    }
    if (low==high){
        TreeNode* node = new TreeNode(low);
        v.push_back(node); 
        return v;
    }
    for (int i=low; i <= high; i++){
        vector<TreeNode*> vleft = generateTrees(low, i-1);
        vector<TreeNode*> vright = generateTrees(i+1, high);
        for (int l=0; l<vleft.size(); l++){
            for (int r=0; r<vright.size(); r++){
                TreeNode *root = new TreeNode(i);
                root->left = vleft[l];
                root->right = vright[r];
                v.push_back(root);
            }
        }
    }
    return v;
}

void printTree(TreeNode *root){
    if (root == NULL){
        printf("# ");
        return;
    }
    printf("%d ", root->val );

    printTree(root->left);
    printTree(root->right);
}

    int testCase(){
    int n = 3;
    vector<TreeNode*> v = generateTrees(n);
    for(int i=0; i<v.size(); i++){
        printTree(v[i]);
        printf("\n");
    }
        return 0;
    }
};
