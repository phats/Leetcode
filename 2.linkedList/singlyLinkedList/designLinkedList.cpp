class MyLinkedList {
public:
    struct DoublyListNode {
        int val;
        DoublyListNode *next, *prev;
    };
    struct List{
        DoublyListNode* head, *tail;
        int size;
    };
    List l;
    MyLinkedList() {
        l.head=l.tail=NULL;
        l.size=0;
    }
    DoublyListNode* createNode(int val){
        DoublyListNode* node = new DoublyListNode;
        node->val=val;
        node->next=node->prev=NULL;
        return node;
    }
    int get(int index) {
        if (index <0 || index >= l.size) return -1;
        DoublyListNode* temp=l.head;
        while(temp && index >0){
            --index;
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        DoublyListNode* node=createNode(val);
        if (l.head == NULL){
            l.head=l.tail=node;
        }
        else{
            l.head->prev=node;
            node->next=l.head;
            l.head=node;
        }
        ++l.size;
    }
    
    void addAtTail(int val) {
        DoublyListNode* node=createNode(val);
        if (l.head ==NULL){
            l.head=l.tail=node;
        }
        else {
            l.tail->next=node;
            node->prev=l.tail;
            l.tail=node;
        }
        ++l.size;
    }
    
    void addAtIndex(int index, int val) {
        if (index <0 || index>l.size) return;
        else if (index==l.size) {
            addAtTail(val);
            return;
        }
        else if (index ==0){
            addAtHead(val);
            return;
        }
        DoublyListNode* temp=l.head;
        DoublyListNode* node=createNode(val);
        if (index>0 && temp){
            --index;
            temp=temp->next;
        }
        node->prev=temp->prev;
        node->next=temp;
        temp->prev->next=node;
        temp->prev=node;
        ++l.size;
    }
    void deleteAtHead(){
        if (l.head==NULL || l.head->next==NULL){
            l.head=NULL;
            return;
        }
        DoublyListNode* temp=l.head;
        l.head=l.head->next;
        l.head->prev=NULL;
        delete temp;
    }
    void deleteAtTail(){
        DoublyListNode* temp=l.tail;
        l.tail=l.tail->prev;
        l.tail->next=NULL;
        delete temp;
    }
    void deleteAtIndex(int index) {
        if (index <0 || index >= l.size) return;
        else if (index==0){
            deleteAtHead();
        }
        else if (index==l.size-1){
            deleteAtTail();
        }
        else{
            DoublyListNode* temp=l.head;
            while(index >0 && temp){
                --index;
                temp=temp->next;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        --l.size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */