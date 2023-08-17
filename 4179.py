import sys
from collections import deque

n, m = map(int, sys.stdin.readline().strip().split())

vis = [list(sys.stdin.readline().strip()) for _ in range(n)]
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]


queue = deque()

j_pt = ()
for i in range(n):
  for j in range(m):
    if vis[i][j] == "F":
      queue.append((i, j, "F", 1))
    if vis[i][j] == "J":
      j_pt = i, j

queue.appendleft((j_pt[0], j_pt[1], "J", 1))


can_escape = False
elapsed_t = 1

while queue:
  y, x, who, t = queue.popleft()
  if who == "J" and vis[y][x] == "F":
    continue
  for d in dirs:
    n_y, n_x = y + d[0], x + d[1]
    if who == "J" and (n_y in [-1, n] or n_x in [-1, m]):
      can_escape = True
      elapsed_t = t
      break
    if (not 0 <= n_y < n
       or not 0 <= n_x < m
       or not vis[n_y][n_x] in [".", "J"]):
      continue
    if vis[n_y][n_x] == "J" and who == "J":
      continue
    queue.append((n_y, n_x, who, t+1))
    vis[n_y][n_x] = who

  if can_escape:
    break


if can_escape:
  print(elapsed_t)
else:
  print("IMPOSSIBLE")
