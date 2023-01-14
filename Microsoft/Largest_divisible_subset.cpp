#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int mx = 1;
    int lastIndex = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > mx)
        {
            mx = dp[i];
            lastIndex = i;
        }
    }
    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    return ans;
}
int main()
{
    vector<int> v = {4, 3, 2, 6};
    largestDivisibleSubset(v);
}