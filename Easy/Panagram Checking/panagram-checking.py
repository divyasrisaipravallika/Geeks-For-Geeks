#User function Template for python3

class Solution:
    
    #Function to check if a string is Pangram or not.
    def checkPangram(self,s):
        #code here
        if len(s)<26:
            return 0
        s = s.upper()
        d = {}
        c = 0
        for i in s:
            if  i.isalpha() and i not in d:
                d[i] = 1
                c+=1
            # else:
            #     d[i]+=1
        if c==26:
            return 1
        return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        obj = Solution()
        if(obj.checkPangram(s)):
            print(1)
        else:
            print(0)
# } Driver Code Ends