#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    vector<string> conseq;
    conseq.resize(numRows, "");
    for (auto &item: conseq) {
        item.reserve(s.size() / numRows + 1);
    }
    int index = 0, di = -1;
    for (auto c: s) {
        conseq[index] += c;
        if (index == 0 || index == conseq.size() - 1) {
            di *= -1;
        }
        index += di;
    }
    string result;
    for (auto &item: conseq) {
        result += move(item);
    }
    return result;
}

int main() {
    cout << convert("PAYPALISHIRING", 3) << endl;
    cout << "PAHNAPLSIIGYIR" << endl;
}

