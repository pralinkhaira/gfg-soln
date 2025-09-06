class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        int count=1;
        Node *fast=head;
        Node *slow=head;
        int loop=0;
        while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr ){
            slow=slow->next;fast=fast->next->next;
            if(fast==slow){
                loop=1;break;
            }
        }
    
        if(!loop){
            return 0;
        }
        else{slow=slow->next;
            while(fast!=slow){
                slow=slow->next;
                count++;
            }
        }
        return count;
    }
};