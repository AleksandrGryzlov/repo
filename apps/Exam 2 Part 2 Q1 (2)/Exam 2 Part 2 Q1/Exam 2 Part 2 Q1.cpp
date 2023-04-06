#pragma once
template <typename T>
class List
{
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void setupList() {
        Node* newNode = new Node();
        newnode->data = nullptr;
        newnode->next = head;
        if (head != NULL) {
            while (ptr->next != head)
                ptr = ptr->next;
            ptr->next = newnode;
        }
        else
            newnode->next = newnode;
        head = newnode;
    }
    void deleteListContents() {
        Node* current = head;
        while (current != nullptr) {
            temp = current.next;
            delete current;
            current = temp;
        }
    }
public:
    List() {
        setupList();
    }
    List(T newData) {
        setupList();
        head->data = newData;
    }
    List(List& rhs) { // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~List() {// And a destructor
        deleteListContents();
    }
    bool  empty() {
        return (head == nullptr);
    }
    void push_front(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }
    void push_back(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail = newNode;
    }
    T front() {
        return (head->data);
    }
    T back() {
        return (tail->data);
    }
    void pop_back() {
        Node* lastNode = tail;
        tail = tail.prev;
        tail.next = nullptr;
        delete lastNode;
    }
    void pop_front() {
        Node* firstNode = head;
        head = head.next;
        head.prev = nullptr;
        delete firstNode;
    }
    void traverse(void (*doIt)(T data)) {
        Node* current = head;
        while (current != tail) {
            doIt(current.data);
        }
    }
};