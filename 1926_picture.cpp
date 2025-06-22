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
    
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int maxSize = 0;
    int pictureCount =0;
    
    for(int i =0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if (map[i][j] == 0 || visited[i][j]) {
                continue;
            }
            
            pictureCount++;
            
            queue<pair<int, int>> q;
            q.emplace(i, j);

            int currentAreaSize = 0; 

            while (q.size() > 0) {
                pair<int, int> now = q.front();q.pop();

                int nowX = now.first;
                int nowY = now.second;
                
                if(visited[nowX][nowY] == true) {
                    continue;
                }

                currentAreaSize ++;
                visited[nowX][nowY] = true;
                
                for (int d = 0; d < 4; d++) {
                    int newX = nowX + dx[d];
                    int newY = nowY + dy[d];

                    if(
                            newX >= N || newX < 0 ||
                            newY >= M || newY < 0 ||
                            map[newX][newY] == 0 ||  
                            visited[newX][newY] == true 
                    )
                        continue;                      

                    else
                        q.emplace(newX, newY);
                }
            }

            maxSize = max(currentAreaSize, maxSize);
        }
    }

    cout << pictureCount << "\n" << maxSize;
}
