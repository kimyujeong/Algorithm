#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
    return (a+b) > (b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    for(auto x:numbers){
        temp.push_back(to_string(x));
    }
        
    sort(temp.begin(),temp.end(),cmp);
    if(temp[0]=="0") return "0";
    
    for(auto x:temp){
        answer+=x;
    }    
    
    return answer;
}