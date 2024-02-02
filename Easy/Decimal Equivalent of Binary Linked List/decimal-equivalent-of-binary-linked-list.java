//{ Driver Code Starts
import java.util.*;
class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data = d;
        next = null;
    }
}

class LinkedList1
{
    Node head;  // head of lisl
    /* Inserts a new Node at front of the list. */
    public void addToTheLast(Node node)
    {
        if (head == null)
        {
            head = node;
        }
        else
        {
            Node temp = head;
            while (temp.next != null)
                temp = temp.next;

            temp.next = node;
        }
    }
    /* Function to print linked list */
    void printList()
    {
        Node temp = head;
        while (temp != null)
        {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        String s = sc.nextLine();
        while(t>0)
        {
            int n = sc.nextInt();
            String s1 = sc.nextLine();
            LinkedList1 llist = new LinkedList1();

            if (n > 0)
            {
                int a1=sc.nextInt();
                Node head= new Node(a1);
                llist.addToTheLast(head);
            }
            for (int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }
            System.out.println(new Solution().DecimalValue(llist.head));
            t--;
        }
    }
}


// } Driver Code Ends

class Pair {
    
    long ans=0;
    long pow=0;
    
    public Pair(long pow) {
        this.pow=pow;
    }
}
class Solution
{
   long MOD = (long)1e9+7;
   long DecimalValue(Node head)
   {
 	   Pair pair = recursion(head);
 	   return pair.ans;
   }
   
   public Pair recursion(Node node) {
       if(node == null) {
           return new Pair(0);
       } else if(node.next == null) {
           Pair pair = new Pair(1);
           pair.ans += node.data;
           return pair;
       }
       
       Pair pair = recursion(node.next);
       pair.pow = (pair.pow * 2)%MOD;
       
       long ans = (long)((node.data * pair.pow)%MOD);
       pair.ans = (pair.ans + ans)%MOD;
       
       return pair;
   }
}