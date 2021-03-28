#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int X,Y;
    
    for(int x=1;x<=yellow;x++){
        if(x*(brown/2-2-x)==yellow){
            X=x;
            Y=brown/2-2-x;
            break;
        }
    }
    
    answer.push_back(X+2);
    answer.push_back(Y+2);
    
    sort(answer.begin(),answer.end(),greater<int>());
      
    
    return answer;
}