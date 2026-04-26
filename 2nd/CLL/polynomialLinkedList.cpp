#include <iostream>
using namespace std;

// Node (record type)
struct Node {
    int coeff, power;
    Node* next;
};

Node* head = NULL;

// Insert term at end
void insert(int c, int p) {
    Node* newNode = new Node{c, p, NULL};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Display polynomial
void display() {
    Node* temp = head;

    cout << "\nPolynomial: ";
    while (temp) {
        cout << temp->coeff << "x^" << temp->power;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
}

int main() {
    int terms, coeff, power;

    cout << "Enter number of terms: ";
    cin >> terms;

    for (int i = 1; i <= terms; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> power;
        insert(coeff, power);
    }

    display();

    return 0;
}