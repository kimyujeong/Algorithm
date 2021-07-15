#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>

using namespace std;

bool check(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z')) return true;
    else return false;
}

vector<string> word(string str){
    
    vector<string> temp;
    
     // 소문자로 통일
    transform(str.begin(),str.end(),str.begin(),(int(*)(int))tolower);
    
    // 부분 문자열 만들기
    for(int i=0;i<str.length()-1;i++){
        if(check(str[i]) && check(str[i+1])) temp.push_back(str.substr(i,2));
    }
    
    return temp;
}

int solution(string str1, string str2) {
    int answer = 65536;
    
    vector<string> str1_word=word(str1);
    vector<string> str2_word=word(str2);
    
    int str1_size=str1_word.size();
    int str2_size=str2_word.size();
    
    if(str1_size==0 && str2_size==0) return answer;
    
    int intersect=0;
    for(int i=0;i<str1_word.size();){
        bool flag=false;
        for(int j=0;j<str2_word.size();j++){
            if(str1_word[i]==str2_word[j]){
                intersect++; // 교집합 갯수
                str1_word.erase(str1_word.begin()+i);
                str2_word.erase(str2_word.begin()+j);
                flag=true; break;
            }
        }
        if(!flag) i++;
    }
    
    int plus=str1_size+str2_size-intersect;
    
    answer=int(intersect*65536/plus);
    
    return answer;
}