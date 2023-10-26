// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include <iostream>
#include <map>
#include <queue>
#include <climits>

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::map<int, int> levelSumMap;

        std::queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* front = q.front();
                q.pop();

                levelSum += front->val;

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }

            levelSumMap[level] = levelSum;
            level++;
        }

        int maxSum = INT_MIN;
        int maxLevel = 0;

        for (const auto& pair : levelSumMap) {
            if (pair.second > maxSum) {
                maxSum = pair.second;
                maxLevel = pair.first + 1;
            }
        }

        return maxLevel;
    }
};

int main() {
    // Create a sample tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution solution;
    int maxLevel = solution.maxLevelSum(root);

    std::cout << "The level with the maximum sum is: " << maxLevel << std::endl;

    // Remember to free the dynamically allocated memory
    // (not included in this code for simplicity)

    return 0;
}
