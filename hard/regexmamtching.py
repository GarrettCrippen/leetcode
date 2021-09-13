# Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        f = re.compile(p)
        return f.fullmatch(s)
        
