#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    map<int, int> mp;
    for(auto item : changed){
        ++mp[item];
    }
    vector<int> result;
    for(auto& [key, value] : mp){
        while(value > 0){
            result.push_back(key);
            --value;
            --mp[2 * key];
            if (mp[2 * key] < 0){
                return {};
            }
        }
    }
    return result;
}

int main() {

    vector<int> vec = {1,3,4,2,6,8};
    auto ans = findOriginalArray(vec);
    for (auto i : ans){
        cout << i << " ";
    }

    return 0;
}