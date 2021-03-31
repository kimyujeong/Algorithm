#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check[200]={false,};
vector<int> v[200];
queue<int> q;

void bfs(int x){
    q.push(x);
    check[x]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<v[node].size();i++){
            int next=v[node][i];
            if(check[next]) continue;
            check[next]=true;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){ // 인접 행렬에 입력
        for(int j=i;j<n;j++){
            if(i==j) continue;
            if(computers[i][j]==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(!check[i]){
            bfs(i);
            answer++;
        }
    }
    
    return answer;
}