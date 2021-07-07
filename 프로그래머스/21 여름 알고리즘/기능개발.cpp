#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int days=0;
    int ptr=0;
    while(ptr!=progresses.size()){
        
        int cnt=1;        
        int days_temp;
        
        if((100-days*speeds[ptr]-progresses[ptr])%speeds[ptr]==0) days_temp=(100-days*speeds[ptr]-progresses[ptr])/speeds[ptr];
        else days_temp=((100-days*speeds[ptr]-progresses[ptr])/speeds[ptr])+1;
        
        days+=days_temp;
        ptr++;
        
        while(ptr!=progresses.size()){
            
            if(progresses[ptr]+(speeds[ptr]*days)>=100){
                cnt++;
                ptr++;
            }
            else break;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

/*

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

*/