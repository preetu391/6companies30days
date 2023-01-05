#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;
    CheckValidCombos(1, 0, ans, temp, n, k);
    return ans;
}

void CheckValidCombos(int num, int sum, vector<vector<int>> &ans, vector<int> temp, int n, int k)
{
    if (sum == n && k == 0)
    {
        ans.push_back(temp);
        return;
    }
    else if (sum > n)
    {
        return;
    }
    for (int i = num; i <= 9; i++)
    {
        if (i > n)
            break;
        temp.push_back(i);
        CheckValidCombos(i + 1, sum + i, ans, temp, n, k - 1);
        temp.pop_back();
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    combinationSum3(k,n);
}