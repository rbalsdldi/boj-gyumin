import sys
from collections import deque

n = int(sys.stdin.readline().strip())

rods = [1, 2, 3]
move_cnt = 0

records = []

def move_disks(start, end, disk_cnt):
    global move_cnt
    if disk_cnt == 1:
        move_cnt = move_cnt + 1
        records.append((start, end))
        return

    third = [i for i in rods if i not in [start, end]][0]
    move_disks(start, third, disk_cnt-1)
    move_disks(start, end, 1)
    move_disks(third, end, disk_cnt-1)
    

move_disks(1, 3, n)

print(move_cnt)
for r in records:
  print(r[0], r[1])
