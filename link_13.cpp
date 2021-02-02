bool isPalindrome(Node *head)
{
        stack<int>s;
        Node *h1=head;
        while(h1!=NULL)
        {
            s.push(h1->data);
            h1=h1->next;
        }
        while(head!=NULL)
        {
            if(head->data!=s.top())
            {
                return 0;
            }
            s.pop();
            head=head->next;
        }
        return 1;
}
