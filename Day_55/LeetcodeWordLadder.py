import collections
from collections import defaultdict

def ladderLength(beg, end, listOfWord):
    if end not in listOfWord or not end or not beg or not listOfWord:
        return 0
    L = len(beg)

    allCombinations = defaultdict(list)
    for w in listOfWord:
        for i in range(L):
            allCombinations[w[:i] + "*" + w[i+1:]].append(w)
    queue = collections.deque([(beg,1)])
    visited = {beg: True}
    while queue:
        currWord, step = queue.popleft()
        for i in range(L):
            inWord = currWord[:i] + "*" +currWord[i+1:]
            for w in allCombinations[inWord]:
                if w == end:
                    return step + 1
                if w not in visited:
                    visited[w] = True
                    queue.append((w,step+1))
            allCombinations[inWord] = []
    return 0

beg = input()
end = input()
n = int(input())
wList =  list()
for i in range(n):
    s = input()
    wList.append(s)
wList.append(beg)
wList.append(end)
print(ladderLength(beg,end,wList)-1)
