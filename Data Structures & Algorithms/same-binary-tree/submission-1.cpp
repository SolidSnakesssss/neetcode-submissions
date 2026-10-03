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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Might wanna do BFS instead of DFS
        std::queue<TreeNode*> pComp;
        std::queue<TreeNode*> qComp;

        pComp.push(p);
        qComp.push(q);

        while (!pComp.empty() && !qComp.empty()) {
            if(!pComp.front() && !qComp.front()) {
                pComp.pop();
                qComp.pop();
                
                continue;
            }

            else if (!pComp.front() || !qComp.front() || pComp.front()->val != qComp.front()->val) {
                return false;
            }
            
            else {
                pComp.push(pComp.front()->left);
                pComp.push(pComp.front()->right);

                qComp.push(qComp.front()->left);
                qComp.push(qComp.front()->right);

                pComp.pop();
                qComp.pop();
            }
        }

        return true;
    }
};

