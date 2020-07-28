class Solution 
{
    private:
            int digitSum(int num) 
            {
                int sum = 0;
                while (num > 0) 
                {
                    int dig = num % 10;
                    sum += dig;
                    num /= 10;
                }
                return sum;
            }
    public:
            int countLargestGroup(int n) 
            {
                unordered_map<int, int> mp;
                int max_size = 0, cnt = 0;
                for (int i=1; i<=n; ++i) 
                {
                    mp[digitSum(i)]++;
                }
                for (auto it=mp.begin(); it!=mp.end(); ++it) 
                {
                    max_size = max(max_size, it->second);
                }
                for (auto it=mp.begin(); it!=mp.end(); ++it) 
                {
                    if (it->second == max_size)
                        ++cnt;
                }
                return cnt;
            }
};