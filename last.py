'''
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
consisting of non-space characters only.
'''
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        max = 0
        max = len(a[len(a)-1])
        return max