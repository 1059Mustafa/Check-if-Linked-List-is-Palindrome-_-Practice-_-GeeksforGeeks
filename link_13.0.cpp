Node* reverse_list(Node* head)
{
    Node* prev = NULL;     // previous node
    Node* curr = head;     // current node
    Node* next;            // next node
    
    while(curr)
    {
        next = curr->next;    // storing address of next node
        curr->next = prev;    // connecting current node to prev
        prev = curr;          // updating address of prev
        curr = next;          // updating address of curr
    }
    
    return prev;
}

bool is_identical(Node* n1, Node* n2)
{
    for(  ; n1 && n2 ; n1=n1->next, n2=n2->next )
    // we only have to match data of the 2 lists
    // till NULL element is met (in any list)
        if( n1->data != n2->data )
            return 0;
    
    return 1;
}

bool isPalindrome(Node *head)
{
    int size=0;
    Node* ptr;
    for( ptr=head ; ptr ; ptr=ptr->next )
        size++;
        // finding number of nodes
    
    if(size<2) return 1;
    
    // now, we have to split list into 2 halves
    // in case of odd elements, first half will have
    // the middle element
    
    ptr = head;
    int mid_pt = (size-1)/2;
    while(mid_pt--)
        ptr = ptr->next;
    // ptr now holds address of last element of first half
    
    Node* head2 = ptr->next;  // head node of second half
    ptr->next = NULL;         // disconnecting the 2 halves
    
    head2 = reverse_list(head2);   // reversing second half
    bool ret = is_identical(head, head2);
    head2 = reverse_list(head2);   // reversing back
    
    ptr->next = head2;             // reconnecting the 2 parts
    return ret;
}
