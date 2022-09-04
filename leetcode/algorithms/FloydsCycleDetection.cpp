
/*
Output: CyclePresent, 
*/

struct Output{
    bool CyclePresent = false;
    Node* EntryPoint = NULL;
    int lengthOfCycle = -1;
    int lengthOutOfCycle;
}

Output FloydsCycle(Node* head){

    Node* slow = head;
    Node* fast = head;

    int x = 0;
    Output output;


    bool met = false;

    while( fast && fast.next ){
        x+=2;
        slow = slow.next;
        fast = fast.next.next;
        if(fast == slow){
            met = true;
            break;
        }
    }
    if(!met){
        output.lengthOutOfCycle = x;
        return output;
    }
    
    slow = head;
    int y = 0;
    while(slow != fast){
        slow = slow.next;
        fast = fast.next;
        y++;
    }
    output.CyclePresent = true;
    output.EntryPoint = slow;
    output.lengthOutOfCycle = y;

    int z = 1;
    fast = fast.next;
    while(slow != fast){
        fast = fast.next;
        z++;
    }

    output.lengthOfCycle = z;

    return output;
}
