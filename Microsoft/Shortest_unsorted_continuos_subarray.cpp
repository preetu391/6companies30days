#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());
    int i = 0, j = nums.size() - 1;
    while (i < nums.size() && v[i] == nums[i])
    {
        i++;
    }
    while (j >= 0 && v[j] == nums[j])
    {
        j--;
    }
    if (i >= j)
        return 0;
    return (j - i) + 1;
}

int main()
{
    vector<int> v = {1, 2, 5, 1, 4};
    findUnsortedSubarray(v);
}