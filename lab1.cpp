#include<iostream>
using namespace std;// Lab 1: Singly Linked List for Username/Password storage

// Goal: Implement a simple credential store using a singly linked list

// Instructions:
// 1) Search for "TODO" and implement each function.
// 2) Build & run:   g++ -std=c++17 -O2 -Wall linked_lists.cpp -o lab && ./lab
// 3) Do not change function signatures

// NOTE: In the real world, NEVER store plaintext passwords.


// ADD HEADER FILES HERE

// -----------------------------
// Data Model
// -----------------------------
struct User {
    string username;
    string password; 
    User* next;
    
    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};


int main() {
  
    // Write code here to test your implementation
    
    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {

    User * newUser = new User(username, password);
    if (head == nullptr) { 
        head = newUser; 
        return true; 
    } 
     User * temp = head;
        while(temp->next!= nullptr) {
            if(username != temp->username && password != temp->password) { 
            temp = temp->next;
        }
        temp->next = newUser;
        return true;  

    }
    return false;
    // TODO: implement
}

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) {
    User * temp = head;
    while(temp != nullptr) {
        if(temp->username == username) {
            return temp;
        }
        temp = temp->next;
    }
    // TODO: implement
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
    User * temp = head;
    while(temp != nullptr) {
        if(temp->password == password && temp->username == username) {
            return true;
        }
        temp = temp->next;
    }
    return false;
    // TODO: implement
   

}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    if(head == nullptr) {
        return;
    } 
    User * temp = head;
    head = head->next;
    delete temp;
    return true;  
    // TODO: implement
    // redo do 
    
    return false;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
    User * temp = head;
    while(temp != nullptr) {
        if(temp->username == username) {
            delete temp;
            return true;
        }
    }
    // TODO: implement

    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    User * temp = head;
    User * next;
    while(temp!= nullptr) {
        next = temp->next;
        delete temp;
        temp = next;
    }
    // TODO: implement
    head = nullptr;
    
}

// Returns number of nodes.
size_t size(User* head) {
    User * temp = head;
    size_t count = 0;
    while(temp != nullptr) {
        count = count + 1;
        temp = temp->next;

    }
    // TODO: implement
    

    return count;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    User * temp = head;
    while(temp!= nullptr) {
        cout << temp ->username << "->";
        temp = temp ->next;
    }
    cout << "NULL" << endl;
    // TODO: implement
   
}

