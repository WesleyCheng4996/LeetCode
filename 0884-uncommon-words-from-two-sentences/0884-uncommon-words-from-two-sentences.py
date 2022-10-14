class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        li = (s1 + " " + s2).split(' ')
        return [x for x in (s1 + " " + s2).split(' ') if li.count(x) == 1]