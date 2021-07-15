#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> _split(string str) { // u, v로 분리
    int opened = 0;
    int closed = 0;

    int ptr = 0;
    while (ptr != str.length()) {
        if (str[ptr] == '(') opened++;
        else closed++;

        ptr++;

        if (opened == closed) break;
    }

    vector<string> temp;
    temp.push_back(str.substr(0, ptr));
    temp.push_back(str.substr(ptr, str.length() - ptr));

    return temp;
}

string _swap(string str) { // 괄호 뒤집기
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') temp += ")";
        else temp += "(";
    }
    return temp;
}

bool check(string str) { // (올바른 괄호문자열) 인지 확인
    stack<char> temp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') temp.push('(');
        else {
            if (!temp.empty()) temp.pop();
            else return false;
        }
    }
    return true;
}

string func(string p) { // 메인 함수(재귀)

    string answer = "";

    if (p == "") return answer;

    string u, v;

    vector<string> temp = _split(p);
    u = temp[0];
    v = temp[1];

    if (check(u)) {
        answer = answer + u + func(v);
        return answer;
    }
    else {
        answer += "(";
        answer += func(v);
        answer += ")";
        answer += _swap(u.substr(1, u.length() - 2));
        return answer;
    }

}

string solution(string p) {
    string answer = "";

    answer = func(p);

    return answer;
}