import sys

n, r, c = map(int, sys.stdin.readline().strip().split())

z_path = [(0, 0), (0, 1), (1, 0), (1, 1)]


def operation_z(n, last_idx, start_r, start_c):
    if n == 1:
        print(last_idx + z_path.index((r-start_r, c-start_c)) + 1)
        return
    # 사분면 폭
    area_w = pow(2, n-1)
    # 어느 사분면에 속하는지 판별
    area = (0 if r-area_w-start_r < 0 else 1,
            0 if c-area_w-start_c < 0 else 1)
    operation_z(n-1, last_idx + pow(4, n-1) * z_path.index(area),
                start_r+area_w*area[0], start_c+area_w*area[1])


operation_z(n, -1, 0, 0)
