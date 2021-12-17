#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;



string count(string& s) {
    int n = s.length();
    vector<int>cnt(26, 0);
    for (int i = 0; i < n; ++i)
        cnt[s[i] - 'a']++;
    string str;
    for (int i = 0; i < 26; ++i)
        str += cnt[i] + '0';
    return str;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    int n = strs.size();
    if (n == 0)
        return {};
    vector<vector<string>> ans;
    unordered_map<string, vector<string>>mymap;
    for (int i = 0; i < n; ++i) {
        string tmp = count(strs[i]);
        mymap[tmp].push_back(strs[i]);
    }
    for (auto iter = mymap.begin(); iter != mymap.end(); ++iter) {
        ans.push_back(iter->second);
    }
    return ans;
}

/*
int main() {
    vector<string>strs = { "eat","tea", "tan", "ate", "nat", "bat" };
    groupAnagrams(strs);
    return 0;

}
*/