import sys
from collections import deque

m, n = map(int, sys.stdin.readline().strip().split())

vis = [[i for i in list(map(int, sys.stdin.readline().strip().split()))]
       for _ in range(n)]
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]


queue = deque()

# 익은 토마토들 좌표를 큐에 등록
# 포맷: (y 좌표, x 좌표, 출발지로부터 거리)
for i in range(n):
  for j in range(m):
    if vis[i][j] == 1:
      queue.append((i, j, 0))


# 최대거리 기록
max_dist = 0


# bfs 진행
while queue:
  cur_y, cur_x, dist = queue.popleft()
  for d in dirs:
    adj_y, adj_x = cur_y + d[0], cur_x + d[1]
    if (not (0 <= adj_y < n)
       or not (0 <= adj_x < m)
       or not (vis[adj_y][adj_x] == 0)):
        continue
    vis[adj_y][adj_x] = 1
    queue.append((adj_y, adj_x, dist + 1))

  if max_dist < dist:
    max_dist = dist


# 남은 안익은 토마토가 있는지 검사
is_infeasible = False
for i in range(n):
  if 0 in vis[i]:
    is_infeasible = True
    break


if is_infeasible:
  print(-1)
else:
  print(max_dist)
