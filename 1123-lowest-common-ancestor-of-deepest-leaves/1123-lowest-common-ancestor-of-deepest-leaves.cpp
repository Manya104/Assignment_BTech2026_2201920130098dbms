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
    pair<TreeNode*, int> find(TreeNode* root) {
        bool left = false, right = false;
        pair<TreeNode*, int> l, r;

        if(root -> left) {
            l = find(root -> left);
            left = true;
        }
        if(root -> right) {
            r = find(root -> right);
            right = true;
        }

        if(left && right) {
            if(l.second == r.second) {
                return {root, l.second + 1};
            }
            else if(l.second > r.second) {
                return {l.first, l.second + 1};
            }
            else {
                return {r.first, r.second + 1};
            }
        }
        else if(left) {
            return {l.first, l.second + 1};
        }
        else if(right) {
            return {r.first, r.second + 1};
        }

        return {root, 0};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return find(root).first;
    }
};