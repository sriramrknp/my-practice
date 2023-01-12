#include<bits/stdc++.h>
using namespace std;

    int ex = 0;
    vector<vector<int> > subset(vector<int> &nums, vector<vector<int> > &ans, int n)
    {
        if (n == nums.size())
            return ans;

        int sze = ans.size();

        for (int i = 0; i < sze; i++)
        {
            ans.push_back(ans[i]);
        }
        for (int i = (int)pow(2, ex); i < ans.size(); i++)
        {
            ans[i].push_back(nums[n]);
        }
        ex++;
        n++;
        return subset(nums, ans, n);
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > ans;
        vector<vector<int> > ans1;
        vector<int> v;
        ans.push_back(v);
        int n = 0;
        return subset(nums, ans, n);
    }

int main()
{
    vector<vector<int> > ans;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    ans = subsets(nums);
    cout << ans;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
}