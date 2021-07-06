#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> id_nickname;
    vector<pair<string,int>> history;
    
    for(auto x:record){
        if(x[0]=='E'){ // Enter
            int ptr=6;
            int cnt=0;
            while(x[ptr]!=' '){
                ptr++;
                cnt++;
            }
            id_nickname[x.substr(6,cnt)]=x.substr(ptr+1,x.length());
            history.push_back({x.substr(6,cnt),0});
        }
        else if(x[0]=='L'){ //Leave
            history.push_back({x.substr(6,x.length()),1});
        }
        else if(x[0]=='C'){ //Change
            int ptr=7;
            int cnt=0;
            while(x[ptr]!=' '){
                ptr++;
                cnt++;
            }
            id_nickname[x.substr(7,cnt)]=x.substr(ptr+1,x.length());
        }
    }
    
    for(auto x:history){
        if(x.second==0) answer.push_back(id_nickname[x.first]+"님이 들어왔습니다.");
        else answer.push_back(id_nickname[x.first]+"님이 나갔습니다.");
    }
    
    return answer;
}