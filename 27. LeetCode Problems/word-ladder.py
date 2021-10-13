#Accepted Solution for Word ladder problem in Leetcode

from collections import defaultdict,deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        d = defaultdict(list)
        for i in wordList:
            for j in range(len(i)):
                d[i[:j]+"*"+i[j+1:]].append(i)
        st = deque()
        st.append([beginWord,1])
        v = set()
        v.add(beginWord)
        while len(st) > 0:
            a = st.popleft()
            b = a[1]
            a = a[0]
            if a == endWord:
                return b
            for i in range(len(a)):
                p = d[a[:i]+"*"+a[i+1:]]
                for j in p:
                    if j not in v:
                        v.add(j)
                        st.append([j,b+1])
        return 0