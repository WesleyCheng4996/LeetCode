class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        return [x for x in (s1 + " " + s2).split(' ') if (s1 + " " + s2).split(' ').count(x) == 1]