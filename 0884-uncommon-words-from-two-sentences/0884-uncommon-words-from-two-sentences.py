class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s1 += " " + s2;
        li = s1.split(' ')
        return [x for x in li if li.count(x) == 1]