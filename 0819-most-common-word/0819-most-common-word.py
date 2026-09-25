import re
from collections import Counter

class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:

        word=re.findall(r'\w+',paragraph.lower())

        counts={}
        for w in word:
            if w not in banned:
                counts[w]=counts.get(w,0)+1
        
        max_word=""
        max_count=0
        for word,count in counts.items():
            if(count > max_count):
                max_count=count
                max_word=word
        return max_word