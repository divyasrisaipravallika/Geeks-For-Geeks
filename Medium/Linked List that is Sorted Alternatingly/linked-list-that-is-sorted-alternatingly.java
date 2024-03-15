//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null;
    }
}

class GFG {
    static void printList(Node node) 
	{ 
		while (node != null) 
		{ 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
		System.out.println(); 
	}
	public static void main (String[] args) {
		Scanner sc  = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    
		    Node head = new Node(sc.nextInt());
		    Node tail = head;
		    
		    for(int i=1; i<n; i++){
		        tail.next = new Node(sc.nextInt());
		        tail = tail.next;
		    }
		    Solution obj = new Solution();
		    head = obj.sort(head);
		    printList(head);
		}
	}
}

// } Driver Code Ends



/*
class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null; 
    }
}
*/

class Solution {
    
   public Node sort(Node head){
        //your code here, return the head of the sorted list
        ArrayList<Integer>a = new ArrayList<>();
        while(head!=null){
            a.add(head.data);
            head = head.next;
        }
        Collections.sort(a);
        Node h = null;
        Node t = null;
        for(Integer i : a){
            Node n = new Node(i);
            if(h == null && t==null){
                h = n;
                t = n;
            }
            else{
                t.next = n;
                t = n;
            }
        }
        return h;
   }


}