#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1001;
    
    int max_length=s.length()/2;
    
    if(s.length()==1) return 1;
    
    for(int len=1;len<=max_length;len++){
        
        vector<pair<int,string>> result;
        
        string temp1=s.substr(0,len);
        int ptr=len;
        int cnt=1;
        
        while((ptr+len)<=s.length()){
            
            string temp2=s.substr(ptr,len);
            ptr+=len;
            
            if(temp1==temp2) cnt++;
            else{
                result.push_back({cnt,temp1});
                temp1=temp2;
                cnt=1;
            }
        }
        
        result.push_back({cnt,temp1});
        result.push_back({1,s.substr(ptr,len)});
        
        string temp="";
        for(auto x:result){            
            if(x.first==1) temp+=x.second;
            else temp+=to_string(x.first)+x.second;
        }
        
        int t=temp.length();
        answer=min(answer,t);
    }
    
    return answer;
}