#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;    
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    bool check[101][101]={false,};
    queue<pair<int,int>> q;
    
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]!=0 && !check[i][j]){
                int tmp=0;
                q.push({i,j});
                check[i][j]=true;
                while(!q.empty()){
                    int yy=q.front().first;
                    int xx=q.front().second;
                    q.pop();
                    tmp++;
                    for(int k=0;k<4;k++){
                        int ny=yy+dy[k];
                        int nx=xx+dx[k];
                        if(ny>=m || ny<0 || nx>=n || nx<0) continue;
                        if(check[ny][nx]) continue;
                        if(picture[ny][nx]==picture[yy][xx]){
                            check[ny][nx]=true;
                            q.push({ny,nx});
                        }
                    }
                }
                answer[0]++;
                answer[1]=max(answer[1],tmp);
            }
            
        }
    }
    
    return answer;
}