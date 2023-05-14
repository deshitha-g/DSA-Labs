#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *findMinimum(struct node *node) {
    if (node->left == NULL) {
        return node;
    }
    return findMinimum(node->left);
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        traverseInOrder(root->left);
        cout << root->key << ' ';
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node1, int key) {
    if (node1 == NULL) {
        struct node *newNode = new node();
        newNode->key = key;
        node1 = newNode;
    } else if (key < node1->key) {
        node1->left = insertNode(node1->left, key);
    } else {
        node1->right = insertNode(node1->right, key);
    }
    return node1;
}

// Deleting a node5
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root == NULL;
            return root;
        } else if (root->left == NULL) {
            root = root->right;
            return root;
        } else if (root->right == NULL) {
            root = root->left;
            return root;
        } else {
            struct node *temp = findMinimum(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
            return root;
        }
    }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
