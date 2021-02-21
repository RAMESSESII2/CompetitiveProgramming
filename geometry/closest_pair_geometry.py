import sys
sys.stdout = open('out.txt', 'w')
sys.stdin = open('in.txt', 'r')


import math

def main():
    N=int(input())
    while(N!=0):
        points = []
        for _ in range(N):
            points.append(list(map(int,input().split())))
        points.sort()
        m = closest_pair(N, points)
        print(round(m, 4) if m<10000 else "INFINITY")
        N = int(input())

def closest_pair(N, points):
    if N <= 3:
        mind = find_min_dist(N, points)
        return mind
    else: 
        pi = N//2
        left = closest_pair(pi, points[:pi])
        right = closest_pair(N-pi, points[pi:])
        d = min(left, right)
        mid_case = []
        for i in points:
            if abs(i[0] - points[pi][0])<d:
                mid_case.append(i)

        return min(d, bottle_neck(mid_case, len(mid_case), d))

def find_min_dist(N, points):
    minm = float("inf")
    for index, i in enumerate(points):
        for j in points[index+1:]:
            ed = math.sqrt(((i[0]-j[0])**2)+((i[1]-j[1])**2))
            minm = min(minm, ed)
    return minm
            
def bottle_neck(mid_case, N, d):
    minm = d
    mid_case.sort()
    for i in range(N):
        j = i+1
        while j<N and (mid_case[i][1]-mid_case[j][1])<minm:
            minm = math.sqrt(((mid_case[i][0]-mid_case[j][0])**2)+((mid_case[i][1]-mid_case[j][1])**2))
            j += 1
    return minm


if __name__ == "__main__":
    main()
