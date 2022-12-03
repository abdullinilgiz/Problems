#include <iostream>
#include <string>
#include <vector>

using namespace std;

string makeGood(string s) {
    if (s.size() < 2){
        return s;
    }
    string result, prev = s;
    do {
        prev = s;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1] && toupper(s[i]) == toupper(s[i + 1])) {
                s[i] = ' ';
                s[i + 1] = ' ';
                ++i;
            }
        }
        result.clear();
        for (auto &c: s) {
            if (c != ' ') {
                result += c;
            }
        }
        s = result;
    } while (prev != s && !s.empty());
    return s;
}

int main () {

    cout << makeGood("abBAcC") << endl << "" << endl ;
    return 0;
}