#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool equationsPossible(vector<string>& equations) { //TODO
    unordered_map<char, unordered_set<char>> equal;
    unordered_map<char, unordered_set<char>> not_equal;
    for (auto& eq : equations){
        if (eq[1] == '!'){
            not_equal[eq[0]].insert(eq[3]);
            //not_equal[eq[0]].insert(equal[eq[3]].begin(), equal[eq[3]].end());
            not_equal[eq[3]].insert(eq[0]);
            //not_equal[eq[3]].insert(equal[eq[0]].begin(), equal[eq[0]].end());
        } else {
            equal[eq[0]].insert(eq[3]);
            //equal[eq[0]].insert(equal[eq[3]].begin(), equal[eq[3]].end());
            equal[eq[3]].insert(eq[0]);
            //equal[eq[3]].insert(equal[eq[0]].begin(), equal[eq[0]].end());
        }
    }
    for (auto& item : equal){
        for (auto& c : item.second){
            item.second.insert(equal[c].begin(), equal[c].end());
        }
    }
    for (auto& item : not_equal){
        for (auto& c : item.second){
            item.second.insert(equal[c].begin(), equal[c].end());
        }
    }
    for (auto& item : not_equal){
        if (item.second.find(item.first) != item.second.end()){
            return false;
        }
    }
    return true;
}

int main() {

    vector<string> vec = {"a==z","a==b","b==c","c==d","b==y","c==x","d==w","g==h","h==i","i==j","a==g","j!=y"};
    cout << equationsPossible(vec) << endl;


    return 0;
}