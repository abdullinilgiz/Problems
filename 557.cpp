#include <string>
#include <iostream>

using namespace std;

string reverseWords(string s) {
    size_t space_pos = 0;
    auto next_pos = space_pos;
    char c;
    while (space_pos < s.size() - 1){
        next_pos = s.find(' ', space_pos);
        if (next_pos == s.npos){
            next_pos = s.size();
        }
        --next_pos;
        for(size_t i = 0; i < (next_pos + 1 - space_pos) / 2; ++i){
           c = s[space_pos + i];
           s[space_pos + i] = s[next_pos - i];
           s[next_pos - i] = c;
        }
        space_pos = next_pos + 2;
    }
    return s;
}

int main() {

    string s = "a";
    cout << reverseWords(s) << endl;

    return 0;
}
