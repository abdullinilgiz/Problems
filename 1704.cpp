#include <string>
#include <unordered_set>

using namespace std;

bool halvesAreAlike(string s) {
    int half = s.size() / 2;
    unordered_set<char> vowels =
            {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int cnt1 = 0, cnt2 = 0;
    int i = 0;
    for(; i < half; ++i){
        if (vowels.end() == vowels.find(s[i])){
            ++cnt1;
        }
    }
    for(;i < s.size(); ++i){
        if (vowels.end() == vowels.find(s[i])){
            ++cnt2;
        }
    }
    if(cnt2 == cnt1){
        return true;
    }
    return false;
}
