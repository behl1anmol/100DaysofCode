N = int(input())
b = input()
g  = input()
for i in range(0,N):
    k = g.find(b[0])
    if k < 0:
        break
    g = g[k+1:] + g[:k]
    b = b[1:]
print(len(b), end="")