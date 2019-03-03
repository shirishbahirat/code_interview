#include <iostream>

struct node {
  char data;
  node *next;
  node(char c) : data{c}, next{nullptr} {}
};

void print_list(node *head) {
  while (head) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

void delete_node(node *n) {
  if (n == nullptr || n->next == nullptr) {
    return;
  }
  node *nextnode = n->next;
  n->data = nextnode->data;
  n->next = nextnode->next;
  delete nextnode;
}

int main() {
  node *head = new node('a');
  head->next = new node('b');
  head->next->next = new node('c');
  head->next->next->next = new node('d');
  head->next->next->next->next = new node('e');
  std::cout << "List before deletion:\n";
  print_list(head);
  std::cout << "Deleting node containing data as 'c'\n";
  delete_node(head->next->next);
  std::cout << "List after deletion:\n";
  print_list(head);
  return 0;
}