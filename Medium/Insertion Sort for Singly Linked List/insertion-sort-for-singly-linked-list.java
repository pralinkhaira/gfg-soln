//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
class insertion
{
    Node head;  
    Node tail;
	public void addToTheLast(Node node) 
	{
	  if (head == null) 
	  {
	   head = node;
	   tail = node;
	  } 
	  else 
	  {
	   tail.next = node;
	   tail = node;
	  }
	}
      void printList(Node head)
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }  
        System.out.println();
    }
	/* Drier program to test above functions */
	public static void main(String args[])
    {
         Scanner sc = new Scanner(System.in);
		 int t=sc.nextInt();
		 while(t>0)
         {
			int n = sc.nextInt();
			insertion llist = new insertion(); 
			int a1=sc.nextInt();
			Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++) 
			{
				int a = sc.nextInt(); 
				llist.addToTheLast(new Node(a));
			}
			
        Solution ob = new Solution();
		head = ob.insertionSort(llist.head);
		llist.printList(head);
		
        t--;		
        }
    }}
// } Driver Code Ends
class Solution
{
    public static Node insertionSort(Node head)
    {
        if (head == null || head.next == null) return head;

        Node dummy = new Node(0); // Dummy node to mark the beginning of the sorted list
        Node prevSorted = dummy; // Pointer to the last node of the sorted list

        while (head != null) {
            Node nextNode = head.next; // Store the next node to avoid losing it

            // Find the position to insert the current node in the sorted list
            while (prevSorted.next != null && prevSorted.next.data < head.data) {
                prevSorted = prevSorted.next;
            }

            // Insert the current node in the sorted list
            head.next = prevSorted.next;
            prevSorted.next = head;

            // Reset pointers for the next iteration
            head = nextNode;
            prevSorted = dummy; // Reset prevSorted to the beginning of the sorted list
        }

        return dummy.next; // Return the sorted list starting from the next of the dummy node
    }
}