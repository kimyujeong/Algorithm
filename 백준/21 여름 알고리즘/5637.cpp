#include <iostream>
#include <string>
#include <algorithm> // transform
#include <ctype.h> // tolower
using namespace std;

int main() {

    string max_word = "";

    bool flag = false;
    
    while (1) {
        string s;
        getline(cin, s); // 공백까지 입력받음

        string temp = "";
        int ptr = 0;

        while (ptr != s.length()) {
            if ((s[ptr] >= 'a'&&s[ptr] <= 'z') || (s[ptr] >= 'A' && s[ptr] <= 'Z') || s[ptr] == '-') {
                temp += s[ptr];
            }

            else {
                if (temp.length() > max_word.length()) max_word = temp;
                temp = "";
            }
            ptr++;

            if (temp == "E-N-D") {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    transform(max_word.begin(), max_word.end(), max_word.begin(), (int(*)(int))tolower);
    cout << max_word << endl;

    return 0;
}