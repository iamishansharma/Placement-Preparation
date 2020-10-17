/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode *makeAVLTree(vector<int> &list, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(list[mid]);

    root->left = makeAVLTree(list, start, mid - 1);
    root->right = makeAVLTree(list, mid + 1, end);

    return root;
}
TreeNode *Solution::sortedListToBST(ListNode *A)
{
    vector<int> list;
    ListNode *temp = A;

    while (temp != NULL)
    {
        list.push_back(temp->val);
        temp = temp->next;
    }

    return makeAVLTree(list, 0, list.size() - 1);
}
