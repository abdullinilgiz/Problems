#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

void Push_comb(vector<int>& l, vector<int>& r, vector<vector<int>>& result) {
    for(auto i : l){
        for(auto j : r){
            result.push_back({i, j});
        }
    }
}

vector<vector<int>> palindromePairs(vector<string>& words) { // TODO
    vector<vector<int>> result;
    unordered_map<string, vector<int>> str_i;
    for(int i = 0; i < words.size(); ++i){
        str_i[words[i]].push_back(i);
    }
    string reversed;
    for(auto it = str_i.begin(); it != str_i.end(); ++it){
        reversed = it->first;
        reverse(reversed.begin(), reversed.end());
        auto itr = str_i.find(reversed);
        if (itr != it && itr != str_i.end()){
            Push_comb(it->second, itr->second, result);
        }
    }
    return result;
}

int main() {



    return 0;
}