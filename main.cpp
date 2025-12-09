#include <iostream>

// --- DEFINIȚII STRUCTURĂ ---

// Nodul: Unitate de bază a listei
struct Node {
    int data;       // Informația stocată
    Node* next;     // Pointer către următorul nod
};

// Clasa LinkedList: Gestionează lista
class LinkedList {
private:
    Node* head; // Capul listei

public:
    // Constructor: Inițializează lista goală
    LinkedList() : head(nullptr) {}

    // DESTRUCTOR: Partea Critică pentru Portofoliu
    // Eliberează memoria manual când obiectul este distrus
    ~LinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        std::cout << "\n[MEMORIE] Rularea Destructorului... Curatenie in curs...\n";
        
        while (current != nullptr) {
            nextNode = current->next;
            // Aici demonstrăm că știm să prevenim Memory Leaks
            std::cout << "  -> Stergere nod cu valoarea: " << current->data << "\n";
            delete current; 
            current = nextNode;
        }
        std::cout << "[MEMORIE] Toata memoria a fost eliberata corect.\n";
    }

    // Funcție de adăugare la final (Insert)
    void insertNode(int data) {
        Node* newNode = new Node; // Alocare dinamică
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Funcție de ȘTERGERE (Demonstrează manipularea pointerilor)
    void deleteNode(int value) {
        if (head == nullptr) return;

        // Cazul 1: Ștergem capul listei
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "[OP] Sters valoarea " << value << " (Capul listei).\n";
            return;
        }

        // Cazul 2: Căutăm în restul listei
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // Dacă nu am găsit valoarea
        if (current->next == nullptr) {
            std::cout << "[INFO] Valoarea " << value << " nu a fost gasita.\n";
            return;
        }

        // Am găsit nodul, refacem legăturile și ștergem
        Node* nodeToDelete = current->next;
        current->next = current->next->next; // Săritura peste nod
        delete nodeToDelete;
        std::cout << "[OP] Sters valoarea " << value << ".\n";
    }

    // Afișare
    void displayList() const {
        Node* current = head;
        std::cout << "Lista Actuala: ";
        while (current != nullptr) {
            std::cout << "[" << current->data << "]";
            if (current->next != nullptr) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// --- MAIN (TESTAREA) ---

int main() {
    std::cout << "=== PORTOFOLIU: C++ MEMORY MANAGEMENT DEMO ===\n";
    std::cout << "=== Project: Singly Linked List with Manual Cleanup ===\n\n";
    
    // Bloc de cod pentru a forța rularea destructorului la finalul lui
    {
        LinkedList myList;

        // 1. Adăugăm date
        std::cout << "> Adaugam elemente...\n";
        myList.insertNode(10);
        myList.insertNode(20);
        myList.insertNode(30);
        myList.insertNode(40);
        myList.displayList();

        // 2. Testăm ștergerea (fix-ul pentru Segmentation Fault)
        std::cout << "\n> Stergem nodul din mijloc (20)...\n";
        myList.deleteNode(20);
        myList.displayList();

        std::cout << "\n> Iesim din scope. Destructorul trebuie sa ruleze automat acum.\n";
    } 

    std::cout << "\n=== Program Finalizat cu Succes ===\n";
    // Aici punem o citire ca sa nu se inchida fereastra imediat daca rulezi din exe
    int x; std::cin >> x; 
    return 0;
}