// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<long long> result;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long levelSum = 0;
            long long levelSize = q.size();

            for (long long i = 0; i < levelSize; i++) {
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
            result.push_back(levelSum);
        }

        std::sort(result.begin(), result.end());

        if (k >= 1 && k <= result.size()) {
            // Return the kth largest level sum
            return result[result.size() - k];
        } else {
            // Handle the case where k is out of range
            return -1; // You can choose an appropriate value or raise an error.
        }
    }
};

int main() {
    // Create a sample binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int k = 2;

    Solution solution;
    long long kthLargestSum = solution.kthLargestLevelSum(root, k);

    if (kthLargestSum != -1) {
        std::cout << "The " << k << "th largest level sum is: " << kthLargestSum << std::endl;
    } else {
        std::cout << "Invalid value of k." << std::endl;
    }

    // Remember to free the dynamically allocated memory for the tree nodes
    // (not included in this code for simplicity)

    return 0;
}
