import sys
from collections import deque
import copy

board = [list(map(int, sys.stdin.readline().strip().split()))
         for _ in range(10)]

remaining = [5, 5, 5, 5, 5]


def check_area(r, c, n, board):
    for i in range(n):
        for j in range(n):
            if board[r+i][c+j] == 0:
                return False
    return True


def remove_ones(r, c, n, board):
    for i in range(n):
        for j in range(n):
            board[r+i][c+j] = 0


def find_candidate(board, n):
    for r in range(11-n):
        for c in range(11-n):
            if not check_area(r, c, n, board):
                continue
            return (r,c)
    return -1


def cnt_ones(board):
    cnt = 0
    for i in range(10):
        for j in range(10):
            if board[i][j] == 1:
                cnt = cnt+1
    return cnt


q = deque()

for s in reversed(range(1,6)):
  candidate = find_candidate(board,s)
  if candidate == -1: continue
  b_new = copy.deepcopy(board)
  remove_ones(candidate[0], candidate[1], s, b_new)
  n_remain_copy = copy.deepcopy(remaining)
  q.append((1, s, remaining, ))
  


def bfs():
    min_cnt = 100
    while q:
        (cnt, n_size, n_remain, b) = q.popleft()
        one_cnt = cnt_ones(b)
        if one_cnt == 0:
            min_cnt = min(min_cnt, cnt)
            return
        for s in reversed(range(1, n_size+1)):
            if s == n_size and n_remain == 0:
                continue
            candidate = find_candidate(b, s)
            if candidate == -1: continue
            b_new = copy.deepcopy(b)
            remove_ones(candidate[0], candidate[1], s, b_new)
            q.append((cnt+1, s, n_remain_copy-1, b_new))

    return -1 if min_cnt == 100 else cnt

print(bfs())