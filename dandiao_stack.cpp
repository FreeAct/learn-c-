#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	if (n < 2)
		return 0;
	stack<int> rain;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		while (!rain.empty() && height[rain.top()] < height[i]) {
			int top = rain.top();
			rain.pop();
			if (rain.empty())
				break;
			int left = rain.top();
			int currWidth = i - left - 1;
			int currHeight = min(height[left], height[i]) - height[top];
			ans += currWidth * currHeight;
		}
		rain.push(i);
	}
	return ans;

};