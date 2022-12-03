#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

int concatenatedBinary(int n) {
    vector<string> s;
    string istr;
    map<char, size_t> mp{{'0', 0}, {'1', 1}};
    size_t cnt = 0;
    for (int i = n; i > 0 && cnt < 30; --i){
        while(i > 0) {
            istr += to_string(i % 2);
            i /= 2;
            ++cnt;
        }
        reverse(istr.begin(), istr.end());
        s.push_back(istr);
    }
    for (int i = s.size() - 1; i > s.size() - 31 && i > -1; --i){
        sum += mp[s[i]]
    }
}


int main() {



    return 0;
}
