#User function Template for python3
class Solution:
	def binaryNextNumber(self, s):
		# code here
		n = int(s,2)
		n = n+1
		a = ""
		while n!=0:
		    a+=str(n&1)
		    n>>=1
		return a[::-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        ans = ob.binaryNextNumber(S)
        print(ans)

# } Driver Code Ends