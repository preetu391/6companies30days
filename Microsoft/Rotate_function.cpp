#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
        int s=0, sum=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            sum+=(i*nums[i]);
        }
        int mx=sum;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=(s-((nums.size())*nums[i]));
            mx=max(mx, sum);
        }
        return mx;
    }
int main()
{
    vector<int> v={4,3,2,6};
    maxRotateFunction(v);
}