#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value, Node* nextPtr = nullptr) {
        data = value;
        next = nextPtr;
    }
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void addATFront(T value) {
        Node<T>* newNode = new Node<T>(value, head);
        head = newNode;
    }

    void addAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    T removeFirst() {
        if (head == nullptr) {
            throw std::underflow_error("List is empty");
        }
        T temp = head->data;
        Node<T>* oldHead = head;
        head = head->next;
        delete oldHead;
        return temp;
    }

    T removeLast() {
        if (head == nullptr) {
            throw std::underflow_error("List is empty");
        }
        if (head->next == nullptr) {
            return removeFirst();
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T lastValue = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return lastValue;
    }

    int size() {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node<T>* find(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void displayList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << "->";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};
