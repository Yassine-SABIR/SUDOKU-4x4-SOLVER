# SABIR Yassine
# 0 represents a blank entry
import numpy as np
q=[[1, 2, 3, 4], [1, 2, 4, 3], [1, 3, 2, 4], [1, 3, 4, 2], [1, 4, 2, 3], [1, 4, 3, 2], [2, 1, 3, 4], [2, 1, 4, 3], [2, 3, 1, 4], [2, 3, 4, 1], [2, 4, 1, 3], [2, 4, 3, 1], [3, 1, 2, 4], [3, 1, 4, 2], [3, 2, 1, 4], [3, 2, 4, 1], [3, 4, 1, 2], [3, 4, 2, 1], [4, 1, 2, 3], [4, 1, 3, 2], [4, 2, 1, 3], [4, 2, 3, 1], [4, 3, 1, 2], [4, 3, 2, 1]]
def isdr(k):
    f=True
    for j in range(4):
        e=[k[0][j],k[1][j],k[2][j],k[3][j]]
        for l in range(4):
            for n in range(4):
                if e[l]==e[n] and l!=n:
                    f=False
    return f
def isdt(l):
    p=np.array([[l[0][0],l[0][1],l[1][0],l[1][1]],[l[0][2],l[0][3],l[1][2],l[1][3]],[l[2][0],l[2][1],l[3][0],l[3][1]],[l[2][2],l[2][3],l[3][2],l[3][3]]])
    r=np.transpose(p)
    return isdr(r)
def sol_soduko(s):#s is matrix
    x=[s[0][i] for i in range(4)]
    y=[s[1][i] for i in range(4)]
    z=[s[2][i] for i in range(4)]
    w=[s[3][i] for i in range(4)]
    l=[x,y,z,w]
    a=[[x],[y],[z],[w]]
    for p in q:
        d=[0,0,0,0]
        for k in range(4):
            for i in range(4):
                if l[k][i]!=0 and p[i]!=l[k][i] :
                    d[k]=d[k]+1
        for j in range(4):
            if d[j]==0:
                a[j].append(p)
    for b in a[0][1:]:
        for c in a[1][1:]:
            for k in a[2][1:]:
                for m in a[3][1:]:
                    v=[b,c,k,m]
                    if isdr(v)==True and isdt(v)==True:
                        return np.array(v)
    print('pas de solutions')
