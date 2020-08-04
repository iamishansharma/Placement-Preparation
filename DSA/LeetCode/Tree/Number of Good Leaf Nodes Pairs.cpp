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
class Solution 
{
    public:
            int d;
            int count(TreeNode* r, map<int, int>& a) 
            {
                map<int, int> z, y;

                if(r == NULL) 
                    return 0;
                else if(r -> left == NULL && r -> right == NULL) 
                {
                    a[1] = 1;
                    return 0;
                }
                else
                {
                    int m = count(r -> left, z);
                    int n = count(r -> right, y);
                    for(auto& i : z) a[i.first + 1] += i.second;
                    for(auto& i : y) a[i.first + 1] += i.second;

                    int presum = 0, res = m + n;
                    auto p2 = y.begin();

                    for(auto p1 = z.rbegin(); p1 != z.rend(); p1++) 
                    {
                        res += presum * p1->second;
                        while(p2 != y.end() && p2->first + p1->first <= d) 
                        {
                            res += p2->second * p1 -> second;
                            presum += p2->second;
                            p2++;
                        }
                    }
                    return res;
                }
            }

            int countPairs(TreeNode* root, int distance) 
            {
                d = distance;
                map<int, int> a;
                return count(root, a);
            }
};