#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>

using namespace std;

struct node {
  int data = 0;
  node *next = nullptr;
};

void insert(node *&head, int data) {
  node *new_node = new node();

  new_node->data = data;
  new_node->next = head;

  head = new_node;
}

void print_node(node *head) {

  while (head) {
    cout << head->data << "->" << flush;
    head = head->next;
  }

  cout << "nullptr" << endl;
}

int get_rand(int max) {
  int data = rand() % max;
  cout << data << "->" << flush;
  return data;
}

void remove_duplicates(node *head) {
  if ((head == nullptr) || ((head) && (head->next == nullptr)))
    return;
  node *curr = head;
  while (curr) {
    node *runner = curr;
    while (runner->next != nullptr) {
      if (curr->data == runner->next->data) {
        delete runner->next;
        runner->next = runner->next->next;
      } else {
        runner = runner->next;
      }
    }
    curr = curr->next;
  }
}

void remove_duplicates_opt(node *head) {
  if (head == nullptr || (head && (head->next == nullptr))) {
    return;
  }
  std::unordered_map<int, int> node_map;
  node *prev = head;
  node *curr = head->next;
  node_map[head->data] = 1;
  while (curr != nullptr) {
    while (curr && node_map.find(curr->data) != node_map.end()) {
      curr = curr->next;
    }
    prev->next = curr;
    prev = curr;
    if (curr) {
      node_map[curr->data] = 1;
      curr = curr->next;
    }
  }
}

int main(int argc, const char *argv[]) {
  srand(time(NULL));

  node *head = nullptr;

  for (int i = 0; i < 20; ++i) {
    insert(head, get_rand(10));
  }
  cout << endl;
  print_node(head);
  remove_duplicates(head);
  print_node(head);

  return 0;
}