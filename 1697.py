import sys
from collections import deque

n, k = map(int, sys.stdin.readline().strip().split())

# 2*k 보다 더 큰 x 좌표를 지나야 하는 경우는 n 이 그보다 큰 경우를 제외하면 없음
max_x = max(2*k, n)
min_x = 0


vis = [0 for _ in range(max_x+1)]

# 인덱스 초과 안되도록 범위 한정
moves = [lambda x: x+1 if x+1 < max_x else max_x,
         lambda x: x-1 if x-1 > min_x else min_x,
         lambda x: x*2 if x*2 < max_x else max_x]


queue = deque()
queue.append((n, 0))
vis[n] = 1


elapsed_t = 0

while queue:
    x, t = queue.popleft()
    if x == k:
      elapsed_t = t
      break
    for m in moves:
        next_x = m(x)
        if not vis[next_x] == 0:
            continue
        queue.append((next_x, t+1))
        vis[next_x] = 1

print(elapsed_t)
