import sys
from collections import deque

n, m = sys.stdin.readline().strip().split()
n, m = int(n), int(m)

# 그림 0->1, 1->0 반전해 방문표시 배열로
# 1 이면 이미 방문 혹은 그림 없음, 0 이면 미방문
vis = [[0 if int(j) == 1 else 1 for j in list(sys.stdin.readline().strip().split())] for i in range(n)]

dirs = [(0,1), (1,0), (0,-1), (-1,0)]

draw_cnt = 0
max_size = 0

for i in range(n):
    for j in range(m):
        if vis[i][j] == 1:
            continue
        vis[i][j] = 1
        queue = deque()
        queue.append([i,j])

        size_temp = 0
        draw_cnt = draw_cnt + 1

        while queue:
            cur_pt = queue.popleft()
            for dir in dirs:
                x, y = cur_pt[0]+dir[0], cur_pt[1]+dir[1]
                # 방문한 혹은 인덱스 초과하는 방향 거르기
                if (not (0 <= x < n) 
                   or not (0 <= y < m) 
                   or vis[x][y] == 1): continue
                vis[x][y] = 1
                queue.append([x,y])

            size_temp = size_temp + 1
        
        if max_size < size_temp: max_size = size_temp

print(draw_cnt, max_size)

