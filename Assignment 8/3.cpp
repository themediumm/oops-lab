#include <iostream>
#include <vector>
#include <limits>
template <typename T>
class Node {
public:
T data;
Node* next;
Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
Node<T>* head;
public:
LinkedList() : head(nullptr) {}
void append(T value) {
Node<T>* newNode = new Node<T>(value);
if (!head) {
head = newNode;
return;
}
Node<T>* temp = head;
while (temp->next) {
temp = temp->next;
}
temp->next = newNode;
}
Node<T>* getHead() const {
return head;
}
~LinkedList() {
Node<T>* current = head;
while (current) {
Node<T>* nextNode = current->next;
delete current;
current = nextNode;
}
}
};
template <typename T>
class Stack {
private:
struct StackNode {
T data;
StackNode* next;
StackNode(T value) : data(value), next(nullptr) {}
};
StackNode* top;
public:
Stack() : top(nullptr) {}
void push(T value) {
StackNode* newNode = new StackNode(value);
newNode->next = top;
top = newNode;
}
T pop() {
if (isEmpty()) {
throw std::runtime_error("Stack is empty");
}
T value = top->data;
StackNode* temp = top;
top = top->next;
delete temp;
return value;
}
bool isEmpty() {
return top == nullptr;
}
~Stack() {
while (!isEmpty()) {
pop();
}
}
};
template <typename T>
class Graph {
private:
int vertices;
std::vector<LinkedList<T>> adjacencyList;
public:
Graph(int v) : vertices(v), adjacencyList(v) {}
void addEdge(int src, int dest) {
adjacencyList[src].append(dest);
adjacencyList[dest].append(src); // Undirected graph
}
void dfs(int start) {
std::vector<bool> visited(vertices, false);
Stack<int> stack;
stack.push(start);
std::cout << "DFS Traversal: ";
while (!stack.isEmpty()) {
int vertex = stack.pop();
if (!visited[vertex]) {
visited[vertex] = true;
std::cout << vertex << " ";
}
Node<T>* temp = adjacencyList[vertex].getHead();
while (temp) {
if (!visited[temp->data]) {
stack.push(temp->data);
}
temp = temp->next;
}
}
std::cout << std::endl;
}
void dijkstra(int start) {
std::vector<int> distances(vertices, std::numeric_limits<int>::max());
distances[start] = 0;
std::vector<bool> visited(vertices, false);
for (int i = 0; i < vertices - 1; ++i) {
int u = minDistance(distances, visited);
visited[u] = true;
Node<T>* temp = adjacencyList[u].getHead();
while (temp) {
int v = temp->data;
if (!visited[v] && distances[u] != std::numeric_limits<int>::max() && distances[u] + 1 <
distances[v]) {
distances[v] = distances[u] + 1; // Assuming unit weight
}
temp = temp->next;
}
}
std::cout << "Vertex Distance from Source (" << start << "):\n";
for (int i = 0; i < vertices; ++i) {
std::cout << "Vertex " << i << " : " << distances[i] << std::endl;
}
}
private:
int minDistance(const std::vector<int>& distances, const std::vector<bool>& visited) {
int min = std::numeric_limits<int>::max(), min_index;
for (int v = 0; v < vertices; ++v) {
if (!visited[v] && distances[v] <= min) {
min = distances[v];
min_index = v;
}
}
return min_index;
}
};
using namespace std;
int main() {
Graph<int> graph(5);
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 3);
graph.addEdge(2, 4);
graph.addEdge(3, 4);
graph.dfs(0);
graph.dijkstra(0);
return 0;
}