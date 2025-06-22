#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int map[N][M];

    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            cin >> map[i][j];
    }

    bool visited[N][M];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) visited[i][j] = false;


    /**
     * (상하좌우) 움직일 수 있는 방향에 대한 성분값.
     */
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int maxSize = 0;
    int pictureCount =0;

    /**
     * 이 이중 반복문의 의미는 '시작점 찾기' 인데, 그러니깐 각 분리된 영역의 시작점이 어딘지 알 방법이 없으니깐 순회를 통해 찾겠다는 거임.
     */
    for(int i =0;i<N;i++) {
        for(int j=0;j<M;j++) {
            //cout<<i<<j<<endl;

            /**
             * 0이거나 이미 방문한 좌표면 건너뜀.
             */
            if (map[i][j] == 0 || visited[i][j]) {
                continue;
            }

            /**
             * 시작점을 찾았을 때 도달함. 즉, 그림 하나를 찾은 것임
             */
            pictureCount++;

            /**
             * bfs를 위한 queue 선언
             */
            queue<pair<int, int>> q;
            
            /**
             * 시작점에서 부터 search 시작할거니깐 시작점 queue에 집어 넣는다.
             */
            q.emplace(i, j);

            int currentAreaSize = 0; // 현재 그림의 넓이를 저장함

            /**
             * 현재 그림의 넓이를 bfs를 이용하여 계산하는 반복문. (bfs 알고리즘을 명확히 숙지하세요)
             */
            while (q.size() > 0) {
                pair<int, int> now = q.front();q.pop();

                int nowX = now.first;
                int nowY = now.second;


                if(visited[nowX][nowY] == true) {
                    continue;
                }

                currentAreaSize ++; // 넓이 1 증가

             //   cout << nowX << " " << nowY <<" "<< currentAreaSize << endl; // for debugging
                visited[nowX][nowY] = true;

                /**
                 * 상, 하, 좌, 우 네 방향에 대한 search
                 */
                for (int d = 0; d < 4; d++) {
                    int newX = nowX + dx[d];
                    int newY = nowY + dy[d];

                    if(
                            newX >= N || newX < 0 || // 이동할 x가 범위를 벗어났거나
                            newY >= M || newY < 0 || // 이동할 y가 범위를 벗어났거나
                            map[newX][newY] == 0 ||  // 이동할 위치가 막혀있거나
                            visited[newX][newY] == true // 이동할 위치가 이미 갔었던 곳이면
                    )
                        continue;                       // 다음 위치를 조사한다.

                    else
                        q.emplace(newX, newY);  // 아니면 search할 목록 (queue)에 추가한다.
                }
            }

            // while문이 종료되었다는 건 한 연결된 영역을 마친 것임 이때 영역 최대 크기 갱신해주자
            maxSize = max(currentAreaSize, maxSize);
        }
    }

    cout << pictureCount << "\n" << maxSize;
}
