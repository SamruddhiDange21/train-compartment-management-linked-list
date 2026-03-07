#include<iostream>
using namespace std;

class Node {
public:
    int number;
    string type;
    Node* next;

    Node(int num, string t) {
        number = num;
        type = t;
        next = NULL;
    }
};

class Train {
public:
    Node* head;

    Train() {
        head = NULL;
    }

    void insert_end(int num, string type) {
        Node* newNode = new Node(num, type);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insert_beg(int num, string type) {
        Node* newNode = new Node(num, type);
        newNode->next = head;
        head = newNode;
    }

    void insert_pos(int num, string type, int pos) {

        if (pos == 1) {
            insert_beg(num, type);
            return;
        }

        Node* newNode = new Node(num, type);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of bounds\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_beg() {

        if (head == NULL) {
            cout << "No compartments\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    void delete_end() {

        if (head == NULL) {
            cout << "No compartments\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void delete_pos(int pos) {

        if (head == NULL) {
            cout << "No compartments\n";
            return;
        }

        if (pos == 1) {
            delete_beg();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    void reverse() {

        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {

            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;

        cout << "Compartments reversed successfully\n";
    }

    void display() {

        if (head == NULL) {
            cout << "No compartments in the train\n";
            return;
        }

        Node* temp = head;

        cout << "\nTrain Compartments:\n";

        while (temp != NULL) {
            cout << "[" << temp->number << " | " << temp->type << "] -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {

    Train obj;

    int choice, number, pos;
    string type;

    do {

        cout << "\n--- Train Compartment Management ---\n";
        cout << "1. Add compartment at end\n";
        cout << "2. Add compartment at beginning\n";
        cout << "3. Add compartment at position\n";
        cout << "4. Remove compartment from end\n";
        cout << "5. Remove compartment from beginning\n";
        cout << "6. Remove compartment from position\n";
        cout << "7. Display compartments\n";
        cout << "8. Reverse compartments\n";
        cout << "9. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter compartment number: ";
            cin >> number;

            cout << "Enter compartment type (AC/Sleeper/General): ";
            cin >> type;

            obj.insert_end(number, type);
            break;

        case 2:

            cout << "Enter compartment number: ";
            cin >> number;

            cout << "Enter compartment type (AC/Sleeper/General): ";
            cin >> type;

            obj.insert_beg(number, type);
            break;

        case 3:

            cout << "Enter compartment number: ";
            cin >> number;

            cout << "Enter compartment type (AC/Sleeper/General): ";
            cin >> type;

            cout << "Enter position: ";
            cin >> pos;

            obj.insert_pos(number, type, pos);
            break;

        case 4:

            obj.delete_end();
            break;

        case 5:

            obj.delete_beg();
            break;

        case 6:

            cout << "Enter position to delete: ";
            cin >> pos;

            obj.delete_pos(pos);
            break;

        case 7:

            obj.display();
            break;

        case 8:

            obj.reverse();
            break;

        case 9:

            cout << "Exiting program\n";
            break;

        default:

            cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}