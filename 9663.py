import sys
from collections import deque
import copy

n = int(sys.stdin.readline().strip())

queue = deque()

for i in range(n):
    # 0: \, 1: /
    diag = [[0 for _ in range(2*n-1)] for _ in range(2)]
    vert = [0 for _ in range(n)]
    diag[0][-i+n-1] = 1
    diag[1][i] = 1
    vert[i] = 1
    queue.append((0, i, diag, vert, [j for j in range(n)]))

cnt = 0

while queue:
    r, c, d, v, r_range = queue.popleft()

    if r == n-1:
        cnt = cnt + 1
        continue

    for i in r_range:
        next_r, next_c = r+1, i
        d_able = (d[0][next_r - next_c+n-1], d[1][next_r + next_c])
        v_able = v[next_c]
        if not d_able[0] == 0 or not d_able[1] == 0 or not v_able == 0:
            continue
        d_copy = copy.deepcopy(d)
        v_copy = copy.copy(v)
        range_copy = copy.copy(r_range)
        d_copy[0][next_r - next_c+n-1] = 1
        d_copy[1][next_r + next_c] = 1
        v_copy[next_c] = 1
        range_copy.remove(next_c)
        queue.append((r+1,  next_c, d_copy, v_copy, range_copy))

print(cnt)

# 파이썬으로는 시간초과를 해결하기 힘들다. 15까지의 답을 모두 미리 하드코딩 하지않는 이상