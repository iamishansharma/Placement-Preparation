vector<int> Solution::stepnum(int A, int B)
{
    vector<int> ans;

    if (A <= 0)
        ans.push_back(0);

    queue<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});

    while (nums.front() <= B)
    {
        int temp = nums.front();
        nums.pop();

        if (temp >= A)
            ans.push_back(temp);

        int lastd = temp % 10;

        if (lastd > 0)
            nums.push(temp * 10 + (lastd - 1));

        if (lastd < 9)
            nums.push(temp * 10 + (lastd + 1));
    }

    return ans;
}
