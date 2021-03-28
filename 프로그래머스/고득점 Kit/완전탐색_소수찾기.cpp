#include <string>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

string s;
char ans[8];
int M=0;

bool check[8]={false,};
set<int> st;

bool prime(int num){  // 소수인지 판단
    if (num == 1) return false;
    for(int i=2;i<num;i++){
        if(num%i==0) return false;
    }
    return true;
}

void go(int cnt){    
    if(cnt==M){
        string temp="";
        for(int j=0;j<cnt;j++){
            if(temp=="" && ans[j]=='0') continue;
            temp+=ans[j];
            if(prime(stoi(temp))){
                st.insert(stoi(temp));
            }
        }
        return;
    }    
    for(int i=0;i<s.length();i++){
        if(!check[i]){
            check[i]=true;
            ans[cnt]=s[i];
            go(cnt+1);
            check[i]=false;
        }
    }
    return;
}


int solution(string numbers) {
    int answer = 0; 
    
    s=numbers;
    
    for(int i=1;i<=numbers.size();i++){
        M=i; // 자릿수
        go(0);
    }
    
    answer=st.size();
    
    return answer;
}