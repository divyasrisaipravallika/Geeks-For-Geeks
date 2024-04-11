#User function Template for python3

class Solution:    
    ##Complete this function
    # function to convert a given Gray equivalent n to Binary equivalent.
    def grayToBinary(self,n):
        ##Your code here
        if n==0:return 0
        l = []
        while n!=0:
            l.append(n&1)
            n=n>>1
        s = ""
        l = l[::-1]
        s+=str(l[0])
        for i in range(0,len(l)-1):
            s+=str(int(s[i])^l[i+1])
        return int(s,2)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    
    T=int(input())
    
    while(T>0):
        
        
        n=int(input())
        ob=Solution()
        print(ob.grayToBinary(n))
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends