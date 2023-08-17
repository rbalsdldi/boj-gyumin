import sys

n, m = map(int, sys.stdin.readline().strip().split())

office = [list(map(int, sys.stdin.readline().strip().split()))
          for _ in range(n)]

# 감시카메라 종류별 방향 (r,c)
cam_t = {
    1: [(0, 1)],
    2: [(0, 1), (0, -1)],
    3: [(0, 1), (1, 0)],
    4: [(0, 1), (0, -1), (1, 0)],
    5: [(0, 1), (0, -1), (1, 0), (-1, 0)]
}

# 감시카메라 방향별 다음 회전 방향
next_d = {
    (1, 0): (0, -1),
    (-1, 0): (0, 1),
    (0, 1): (1, 0),
    (0, -1): (-1, 0)
}


wall_cnt = 0
cams = []
for r in range(n):
    for c in range(m):
        if office[r][c] in range(1, 6):
            cams.append((r, c, office[r][c]))
        elif office[r][c] == 6:
            wall_cnt = wall_cnt + 1


def calc_area(stack):
    check = {}
    area = 0
    for (r, c, t, o) in stack:
        cnt = 0
        for (d_r, d_c) in cam_t[t]:
            for i in range(o):  # 방향 회전시키기
                (d_r, d_c) = next_d[(d_r, d_c)]
            idx = 0
            temp = 0
            while True:
                cur_r, cur_c = r + d_r*idx, c+d_c*idx
                if not 0 <= cur_r < n or not 0 <= cur_c < m or office[cur_r][cur_c] == 6:
                    break
                idx = idx + 1
                if check.get((cur_r, cur_c)) == '#':
                    continue
                check[(cur_r, cur_c)] = '#'
                temp = temp + 1

            cnt = cnt + temp
        area = area + cnt
    return area


max_area = 0


def iterate():
    global max_area
    for i in range(pow(4, len(cams))):
        stack = []
        temp = i
        for r, c, t in cams:
            stack.append((r, c, t, temp % 4))
            temp = temp // 4
        max_area = max(max_area, calc_area(stack))


iterate()

print(n*m - max_area - wall_cnt)
