#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Helper(string& s, unordered_set<string>& vars, unordered_map<string, char>& sc, int index, string result){
    if (index >= s.size()){
        vars.insert(result);
    }
    string cpy = result;
    cpy.push_back(sc[string(1, s[index])]);
    Helper(s, vars, sc, index + 1, move(cpy));
    if (index != s.size() - 1) {
        auto it = sc.find(string(1, s[index]) + string(1, s[index + 1]));
        if (it != sc.end()) {
            result.push_back(it->second);
            Helper(s, vars, sc, index + 2, move(result));
        }
    }
}

int numDecodings(string s) { // TODO
    unordered_set<string> vars;
    unordered_map<string, char> sc = {
            {"1", 'A'},            {"2", 'B'},            {"3", 'C'},            {"4", 'D'},
            {"5", 'E'},            {"6", 'F'},            {"7", 'G'},            {"8", 'H'},
            {"9", 'I'},            {"10", 'J'},            {"11", 'K'},            {"12", 'L'},
            {"13", 'M'},            {"14", 'N'},            {"15", 'O'},            {"16", 'P'},
            {"17", 'Q'},            {"18", 'R'},            {"19", 'S'},            {"20", 'T'},
            {"21", 'U'},            {"22", 'V'},            {"23", 'W'},            {"24", 'X'},
            {"25", 'Y'},            {"26", 'Z'},            };
    string result;
    Helper(s, vars, sc, 0, result);
    return vars.size();
}

int main() {

    string s = "12345678920";
    string s2 = "10987654321";
    cout << numDecodings(s) << endl;

    return 0;
}
