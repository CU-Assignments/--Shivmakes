#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    
    ListNode* head = nullptr; // Pointer to the head of the merged list
    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    
    ListNode* current = head; // Pointer to track the current node
    
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Attach the remaining nodes of the non-empty list
    if (list1) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    return head;
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
    // Creating first sorted linked list: 1 -> 3 -> 5
    ListNode* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    
    // Creating second sorted linked list: 2 -> 4 -> 6
    ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    // Merging the lists
    ListNode* mergedList = mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(mergedList);
    
    return 0;
}
