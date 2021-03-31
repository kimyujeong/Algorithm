#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[50];

int possible(string a, string b)
{
    int i;
    int cnt = 0;

    for(i=0;i<a.length();i++)
    {
        if(a[i] != b[i]) cnt++;
    }

    if(cnt==1) return 1;
    else return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> Q;
    int i;
    string temp;
    int num;

    Q.push(make_pair(begin,0));
    while(!Q.empty())
    {
        temp = Q.front().first;
        num = Q.front().second;
        Q.pop();

        if(temp.compare(target) == 0)
        {
            answer = num;
            break;
        }

        for(i=0;i<words.size();i++)
        {
            if(visited[i]) continue;
            if(possible(temp, words[i]))
            {
                visited[i] = 1;
                Q.push(make_pair(words[i],num+1));
            }
        }
    }

    return answer;
}
