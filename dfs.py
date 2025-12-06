li = []

n = int(input())

for i in range(n) :
    line = input()
    temp = []
    for str in line :
        temp.append(int(str))

    li.append(temp)

visited = []

for i in range(n) :
    temp = []
    for j in range(n) :
        temp.append(False)
    visited.append(temp)

dx = [1,-1,0,0]
dy = [0,0,1,-1]

## 현재 0,0
# 현재 x 좌표 + dx

# 새로운 좌표a : 1,0
# 새로운 좌표b : -1, 0
# 새로운 좌표C : 0, 1
# 새로운 좌표d : 0 ,-1
result = []

for i in range(n) :
    for j in range(n) :
        if (not visited[i][j]) and li[i][j] == 1:

            stack = []
            stack.append((i,j))
 
            cnt = 0
            
            while(stack) :
                current = stack.pop() # 현재의 x,y좌표가 튜플로 있는거
                cnt += 1
                
                for d in range(0,4) :
                    if current[0] + dx[d] < 0:
                        continue
                    if current[0] + dx[d] >= n :
                        continue
                    if  current[1] + dy[d] < 0 :
                        continue
                    if current[1] + dy[d] >= n :
                        continue
                    #여기가 -> 리스트에서 새로운 좌표에 접근 가능한 것임


                    nX = current[0] + dx[d]
                    nY = current[1] + dy[d]

                    if visited[nX][nY]:
                        continue
                    # 새로운 데를 찾았는데, 걔를 이미 방문했으면 가면 안됨

                    if li[nX][nY] == 0 :
                        continue
                    # 0이면 가면 안됨
                    
                    visited[nX][nY] = True
                    stack.append((nX,nY))
            result.append(cnt)
        
result.sort()

print(len(result))

for x in result :
    print(x)
        
