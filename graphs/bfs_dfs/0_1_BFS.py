from collections import deque
def main():
    h,w=map(int,input().split())
    ch,cw=map(int,input().split())
    dh,dw=map(int,input().split())
    ch,cw,dh,dw=ch-1,cw-1,dh-1,dw-1
    s=[input() for _ in range(h)]
    que=deque([[ch,cw,0]])
    que2=[[ch,cw,0]]
    que3=[]
    visited=[[-1 for _ in range(w)] for _ in range(h)]
    A=[[-1,0],[0,1],[1,0],[0,-1]]
    B=[[-1,-1],[-1,1],[1,1],[1,-1],[-2,-2],[-2,-1],[-2,0],[-2,1],[-2,2],[-1,2],[0,2],[1,2],[2,2],[2,1],[2,0],[2,-1],[2,-2],[1,-2],[0,-2],[-1,-2]]
    while que:
        y,x,c=que.pop()
        for dy,dx in A:
            nowy,nowx=y+dy,x+dx
            if 0<=nowy<h and 0<=nowx<w:
                if s[nowy][nowx]!="#" and visited[nowy][nowx]==-1:
                    visited[nowy][nowx]=c
                    que.append([nowy,nowx,c])
                    que2.append([nowy,nowx,c])
        if not que:
            while que2:
                y,x,c=que2.pop()
                for dy,dx in B:
                    nowy,nowx=y+dy,x+dx
                    if 0<=nowy<h and 0<=nowx<w:
                        if s[nowy][nowx]!="#" and visited[nowy][nowx]==-1:
                            visited[nowy][nowx]=c+1
                            que.append([nowy,nowx,c+1])
                            que3.append([nowy,nowx,c+1])
            que2=que3
            que3=[]
    print(visited[dh][dw])
    
if __name__ == "__main__":
    main()