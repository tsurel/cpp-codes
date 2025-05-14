#include <iostream>

class LinkedList {
private:
    struct node {
        int data;
        node* next;
        node(int val) : data(val), next(nullptr) {}
    };
    node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        node* current = head;
        while (current) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Insert a new value at the end of the list
    void insert(int value) {
        node* new_node = new node(value);
        if (!head) {
            head = new_node;
        } else {
            node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    // Remove a value from the list
    bool remove(int value) {
        if (!head) return false;

        if (head->data == value) {
            node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        return false;
    }

    // Search for a value in the list
    bool search(int value) const {
        node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Find the middle element
    int findmiddle() const {
        if (!head) throw std::runtime_error("List is empty");
        node* slow = head;
        node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    // Print the list
    void print() const {
        node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;

    // Insert values
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    // Print the list
    std::cout << "List: ";
    list.print();

    // Find the middle element
    try {
        std::cout << "Middle: " << list.findmiddle() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Remove a value
    list.remove(3);
    std::cout << "After removing 3: ";
    list.print();

    // Search for a value
    list.search(2) ? std::cout << "Found 2\n" : std::cout << "Not Found 2\n";

    return 0;
}