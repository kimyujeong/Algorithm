#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int Size=jobs.size();
    // Type 1
    int end=0;
    for(int i=0;i<jobs.size();i++){
        
        if(end<jobs[i][0]){
            end+=jobs[i][0];
        }
        end+=jobs[i][1];
        answer+=end-jobs[i][0];
    }
    answer=answer/Size;
    
    // Type 2
    
    int tmp=0;
    end=0;
    
    multimap<int,int> st;
    for(int i=0;i<jobs.size();i++){
        st.insert({jobs[i][0],jobs[i][1]});
    }
    
    while(!st.empty()){
        multimap<int,int>::iterator iter=st.begin();
        while(iter!=st.end()){
            if((*iter).first<=end) iter++;
            else break;
        }
        
        if(iter==st.begin() && (*iter).first>end){
            end++;
            continue;
        }
        
        multimap<int,int>::iterator tmp_iter=st.begin();
        
        pair<int,int> Min={1001,1001};
        
        auto it=st.begin();
        
        while(it!=iter){
            if(Min.second>(*it).second){
                Min.first=(*it).first;
                Min.second=(*it).second;
                tmp_iter=it;
            }
            it++;
        }
        
        end+=Min.second;
        tmp+=(end-Min.first);
        
        st.erase(tmp_iter);
    }
          
    answer=min(answer,tmp/Size);
    
    return answer;
}