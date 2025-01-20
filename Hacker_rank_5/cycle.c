// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {

    
    if(head==NULL) return false;
    
    struct SinglyLinkedListNode* first = head;
    struct SinglyLinkedListNode* second = head;
    while(second!=NULL && second->next!=NULL)
    {
        first = first->next;
        second = second->next->next;
        if(first==second){
            return true;
        }
    }
    return false;
    

}