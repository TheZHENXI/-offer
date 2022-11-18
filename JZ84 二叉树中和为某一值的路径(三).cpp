class Solution {
public:        

    vector<vector<int>> Solutions;
	vector<int> Solution;
    int res = 0;
	void allPath(TreeNode* root, int sum,int& res)
	{
		if(root == nullptr)
			return;
		//处理当前值
		sum -= root->val;
		if(sum == 0)
		{
			res++;
		}
		//搜索所有的可能
		allPath(root->left, sum,res);
		allPath(root->right,sum,res);	
	}
    //求以所有节点为根节点的路径
    int FindPath(TreeNode* root, int sum) 
	{
        if(root == nullptr) return 0;

		allPath(root,sum,res);

        FindPath(root->left,sum);
        FindPath(root->right,sum);
		
		return res;
    }
};
/*
//超出内存
class Solution {
public:        

    vector<vector<int>> Solutions;
	vector<int> Solution;

	void allPath(vector<vector<int>>& Solutions,vector<int>& Solution,
	TreeNode* root, int sum)
	{
		if(root == nullptr)
			return;
		//处理当前值
		Solution.push_back(root->val);
		sum -= root->val;
		if(sum == 0)
		{
			Solutions.push_back(Solution);
		}
		//搜索所有的可能
		allPath(Solutions,Solution,root->left, sum);
		allPath(Solutions,Solution,root->right,sum);
        //回溯
        Solution.pop_back();		
	}
    int FindPath(TreeNode* root, int sum) 
	{
        if(root == nullptr) return 0;

		allPath(Solutions,Solution,root,sum);

        FindPath(root->left,sum);
        FindPath(root->right,sum);
		
		return Solutions.size();
    }
};
*/