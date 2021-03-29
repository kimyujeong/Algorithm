#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(const pair<string,int> &a, const pair<string,int> &b){
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,int> Genres; // 장르별 재생 횟수
    
    map<string,int> Idx; // 장르의 인덱스 -> priority queue로 저장하기 위함
    priority_queue<pair<int,int>> pq[100]; // 장르별 <재생 횟수,인덱스> 저장
    
    int temp=0; // 증가시켜 줄 인덱스 번호
    for(int i=0;i<genres.size();i++){
        
        Genres[genres[i]]+=plays[i];
        
        if(Idx.count(genres[i])==0) Idx[genres[i]]=temp++;
        
        pq[Idx[genres[i]]].push({plays[i],-i});
    }
    
    vector<pair<string,int>> tmp(Genres.begin(),Genres.end()); // 벡터에 장르 복사하여 정렬
    sort(tmp.begin(),tmp.end(),cmp);
    
    for(int i=0;i<tmp.size();i++){
        // tmp[i].first 가 장르이름
        int x=Idx[tmp[i].first];
        
        answer.push_back(-pq[x].top().second);
        pq[x].pop();
        
        if(!pq[x].empty()){
            answer.push_back(-pq[x].top().second);
            pq[x].pop();
        }
    }
    
    return answer;
}