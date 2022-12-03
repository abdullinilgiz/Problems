#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

void Helper(vector<int>& nums, vector<vector<int>>& result, int index, vector<int> comb){
    if (index == nums.size()){
        result.push_back(move(comb));
        return;
    }
    Helper(nums, result, index + 1, comb);
    comb.push_back(nums[index]);
    Helper(nums, result, index + 1, move(comb));
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> comb;
    Helper(nums, result,  0, comb);
    return result;
}

int main() {

    vector<int> vec = {1, 2, 3};
    auto ans = subsets(vec);
    for (auto i : ans){
        cout << '*';
        for (auto j : i){
            cout << j << " ";
        }
        cout << '*';
        cout << endl;
    }

    return 0;
}