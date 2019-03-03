#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
  node(int d) : data{d}, next{nullptr} {}
};

void insert(node *&head, int data) {
  node *newnode = new node(data);
  newnode->next = head;
  head = newnode;
}

void deleteList(node *&head) {
  node *nextnode;
  while (head) {
    nextnode = head->next;
    delete (head);
    head = nextnode;
  }
}

void printList(node *head) {
  while (head) {
    cout << head->data << "-->";
    head = head->next;
  }
  cout << "null" << endl;
}

node *kthToLastHelper(node *head, int k, int &i) {
  if (head == nullptr) {
    return nullptr;
  }
  cout << "before " << i << " " << k << endl;
  node *node = kthToLastHelper(head->next, k, i);
  i = i + 1;

  if (i == k) {
    cout << "head after " << i << " " << k << " " << head << endl;
    return head;
  }
  cout << "node after " << i << " " << k << " " << node << endl;

  return node;
}

node *kthToLastRecursive(node *head, int k) {
  int i = 0;
  return kthToLastHelper(head, k, i);
}

node *kthToLastIterative(node *head, int k) {
  if (head == nullptr) {
    return head;
  }

  node *ptr1 = head;
  node *ptr2 = head;

  int i = 0;
  while (i < k && ptr1) {
    ptr1 = ptr1->next;
    ++i;
  }

  if (i < k) {
    return nullptr;
  }

  while (ptr1 != nullptr) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return ptr2;
}

int main() {
  node *head = nullptr;
  for (int i = 7; i > 0; i--) {
    insert(head, i);
  }
  cout << "List: ";
  printList(head);

  cout << "4th node from last (Recursive) : ";
  node *node4 = kthToLastRecursive(head, 4);
  if (node4 != nullptr) {
    cout << node4->data << endl;
  } else {
    cout << "NULL node\n";
  }

  cout << "4th node from last (Iterative) : ";
  node4 = kthToLastIterative(head, 4);
  if (node4 != nullptr) {
    cout << node4->data << endl;
  } else {
    cout << "NULL node\n";
  }

  deleteList(head);

  return 0;
}