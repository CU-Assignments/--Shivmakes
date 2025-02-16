#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete all nodes that have duplicate numbers
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    
    while (head) {
        bool duplicate = false;
        while (head->next && head->val == head->next->val) {
            head = head->next;
            duplicate = true;
        }
        if (duplicate) {
            prev->next = head->next;
        } else {
            prev = prev->next;
        }
        head = head->next;
    }
    
    return dummy->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a new node
ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    // Creating sorted linked list with duplicates: 1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);
    
    cout << "Original List: ";
    printList(head);
    
    // Deleting duplicates
    ListNode* uniqueList = deleteDuplicates(head);
    
    cout << "List after removing duplicates: ";
    printList(uniqueList);
    
    return 0;
}
