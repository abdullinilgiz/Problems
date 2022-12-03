#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool Is_palindrome(string& palindrome, int i, int j, const string& s){
    int first = i, last = j;
    while(j > i){
        if (s[i] != s[j]){
            return false;

        }
        --j;
        ++i;
    }
    if (palindrome.size() < last - first + 1){
        palindrome = s.substr(first, last - first + 1);
    }
    return true;
}

string longestPalindrome(string s) {
    if (s.size() < 2){
        return s;
    }
    unordered_map<char, vector<int>> cinds;
    for(int i = 0; i < s.size(); ++i){
        cinds[s[i]].push_back(i);
    }
    string palindrome = "";
    for (auto& item : cinds){
        auto& vec = item.second;
        int n = static_cast<int>(vec.size());
        for (int i = 0; i < n; ++i){
            for(int j = n - 1; j > i; --j){
                if (Is_palindrome(palindrome, vec[i], vec[j], s)){
                    break;
                }
            }
        }
    }
    if(palindrome.empty() && !cinds.empty()){
        palindrome = cinds.begin()->first;
    }
    return palindrome;
}

int main() {

    cout << longestPalindrome("aacabdkacaa") <<  "| aca" << endl;
    cout << longestPalindrome("cbbd") << "| bb" << endl;
    cout << longestPalindrome("babad") << "| bab || aba"<<endl;
    cout << longestPalindrome("abcde") << "| empty string " << endl;
    cout << longestPalindrome("")  << "| empty string " << endl;
    cout << longestPalindrome("aa")  << "| aa" << endl;
    cout << longestPalindrome("ac")  << "| a || c" << endl;
    cout << longestPalindrome("a") <<  "| a" << endl;

    return 0;
}