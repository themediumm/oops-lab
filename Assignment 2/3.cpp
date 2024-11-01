#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
};
Node* createNode(int data) {
 Node* newNode = new Node();
 if (!newNode) {
 cout << "Memory error\n";
 return NULL;
 }
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}
Node* insert(Node* root, int data) {
 if (root == NULL) {
 root = createNode(data);
 return root;
 }
 if (data <= root->data) {
 root->left = insert(root->left, data);
 }
 else {
 root->right = insert(root->right, data);
 }
 return root;
}
Node* search(Node* root, int data) {
 if (root == NULL || root->data == data)
 return root;
 if (root->data < data)
 return search(root->right, data);
 return search(root->left, data);
}
int findHeight(Node* root) {
 if (root == NULL)
 return -1;
 return max(findHeight(root->left), findHeight(root->right)) + 1;
}
void dfs(Node* root) {
 if (root == NULL)
 return;
 cout << root->data << " ";
 dfs(root->left);
 dfs(root->right);
}
void bfs(Node* root) {
 if (root == NULL)
 return;
 Node* queue[100];
 int front = 0, rear = 0;
 queue[rear++] = root;
 while (front < rear) {
 Node* temp = queue[front++];
 cout << temp->data << " ";
 if (temp->left)
 queue[rear++] = temp->left;
 if (temp->right)
 queue[rear++] = temp->right;
 }
}
Node* deleteNode(Node* root, int data) {
 if (root == NULL)
 return root;
 if (data < root->data)
 root->left = deleteNode(root->left, data);
 else if (data > root->data)
 root->right = deleteNode(root->right, data);
 else {
 if (root->left == NULL && root->right == NULL) {
 delete root;
 root = NULL;
 }
 else if (root->left == NULL) {
 Node* temp = root;
 root = root->right;
 delete temp;
 }
 else if (root->right == NULL) {
 Node* temp = root;
 root = root->left;
 delete temp;
 }
 else {
 Node* temp = root->right;
 while (temp->left != NULL)
 temp = temp->left;
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 }
 return root;
}
void display(Node* root) {
 if (root == NULL)
 return;
 cout << "Root: " << root->data << endl;
 if (root->left)
 cout << "Left child: " << root->left->data << endl;
 if (root->right)
 cout << "Right child: " << root->right->data << endl;
 display(root->left);
 display(root->right);
}
int main() {
 Node* root = NULL;
 root = insert(root, 50);
 root = insert(root, 30);
 root = insert(root, 20);
 root = insert(root, 40);
 root = insert(root, 70);
 root = insert(root, 60);
 root = insert(root, 80);
 display(root);
 Node* found = search(root, 40);
 if (found)
 cout << "Node found: ";