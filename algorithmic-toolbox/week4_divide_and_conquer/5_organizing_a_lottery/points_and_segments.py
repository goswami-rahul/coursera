# Uses python3
import sys

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    n = len(points)
    arr = []
    for i, p in enumerate(points):
        arr.append([p, 2, i])
    for x in starts:
        arr.append([x, 1, 42])
    for x in ends:
        arr.append([x, 3, 42])
    arr.sort()
    active = 0
    for x in arr:
        if x[1] == 2:
            # point
            cnt[x[2]] = active
        elif x[1] == 1:
            # start
            active += 1
        elif x[1] == 3:
            # end
            active -= 1

    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    # use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
