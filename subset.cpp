#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

vector<vector<int>> ans;
void dfs(int i, vector<int>& nums, vector<int>& tmp) {
    int n = nums.size();
    ans.push_back(tmp);
    if (i == (n - 1))
        return;
    for (int j = i + 1; j < n; ++j) {
        tmp.push_back(nums[j]);
        dfs(j, nums, tmp);
        tmp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    ans.clear();
    ans.push_back({});
    vector<int> tmp;
    for (int i = 0; i < n; ++i) {
        tmp.push_back(nums[i]);
        dfs(i, nums, tmp);
        tmp.pop_back();
    }
    return ans;

}

//int main() {
//    vector<int> nums = { 1,2,3 };
//    subsets(nums);
//    return 0;
//}