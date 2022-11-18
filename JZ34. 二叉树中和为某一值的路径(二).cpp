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
class Solution {
public:
    void findPath(vector<vector<int>>& Solutions,vector<int>& Solution,
    TreeNode* root, int target)
    {
        //边界处理 
        if(root == nullptr)
            return;        
        //处理当前值
        Solution.push_back(root->val);
        target -= root->val;
        //满足条件，存储路径
        if(target == 0 && root->left == nullptr && root->right == nullptr)
        {
            Solutions.push_back(Solution);
        } 

        //处理左、右子树
        findPath(Solutions,Solution,root->left, target);
        findPath(Solutions,Solution,root->right,target);
        // 回溯
        Solution.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) 
    {
        vector<vector<int>> Solutions;
        vector<int> Solution;
        findPath(Solutions,Solution,root,target);
        return Solutions;
    }
};