// https://leetcode.com/problems/symmetric-tree/
// 101 (Easy) - Checking symmetry in bst

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool checkSymmetry(TreeNode *left, TreeNode *right)
    {
        if (right == nullptr && left == nullptr)
        {
            return true;
        }
        if ((right == nullptr) || (left == nullptr))
        {
            return false;
        }

        if (left->val != right->val)
        {
            return false;
        }
        if (checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left))
        {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return checkSymmetry(root->left, root->right);
    }
};

int main()
{

    return 0;
}