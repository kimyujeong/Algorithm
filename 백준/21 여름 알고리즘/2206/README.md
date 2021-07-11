## 2206 - 벽 부수고 이동하기
* BFS
* 일반적인 BFS 풀이라면 queue에 {y,x} 좌표만 저장하고
* Visited 또한 [y][x]에 대해 저장한다.
* 하지만, 벽을 1회 부실수 있다는 특수성이 있기 때문에 변수를 다르게 선언하여야 한다.
* queue<pair<pair<int,int>,int>> q : {{y,x},벽을 부순 횟수} : 여기서 마지막 "벽을 부순 횟수"가 0이라면 1번 부술 기회가 남아있는 것
* Visited[y][x][2] : 마지막 인자를 0에 저장하면 벽을 부수지 않고 이동, 1은 벽을 부수고 이동
* 또한 Visited 배열을 단순 'check'의 목적으로 사용하는 것이 아닌, 좌표까지의 최단 경로도 함께 저장한다.

``` c++
q.push({ { 0,0 },0 });
Visited[0][0][0] = 1; // 최단 경로

// 처음 bfs()에 진입했을 때
// 큐에 {0,0} 좌표와 벽을 부수지 않음(0)을 함께 push
```

``` c++
int node_y = q.front().first.first;
int node_x = q.front().first.second;
int block = q.front().second; // 0이라면 1번 부술 기회가 있는 것

if (node_y == n - 1 && node_x == m - 1) return Visited[node_y][node_x][block];
// 마지막 좌표까지 이동하면 Visited(==최단경로)를 return
```

``` c++
if (Map[next_y][next_x] == 0 && !Visited[next_y][next_x][block]) { // 지나갈 수 있는지
	  Visited[next_y][next_x][block] = Visited[node_y][node_x][block] + 1;
	  q.push({ { next_y,next_x },block });
}
```

``` c++
else if (Map[next_y][next_x] == 1 && !Visited[next_y][next_x][block]) { // 막혀있는지
		if (!block) { // block == 0 이라면 -> 아직 부순 적이 없다면
				Visited[next_y][next_x][1] = Visited[node_y][node_x][block] + 1;
        // Visited[][][1]에 저장
     
				q.push({ { next_y,next_x },1 });
        // q.push({{ , },1})
		}
}
```
