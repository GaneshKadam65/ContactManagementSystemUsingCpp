#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string email;
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& email) {
        Contact newContact;
        newContact.name = name;
        newContact.email = email;
        contacts.push_back(newContact);
        std::cout << "Contact added successfully!\n";
    }

    void deleteContact(const std::string& name) {
        bool found = false;
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                found = true;
                std::cout << "Contact deleted successfully!\n";
                break;
            }
        }
        if (!found) {
            std::cout << "Contact not found!\n";
        }
    }

    void displayAllContacts() {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }
        std::cout << "Contacts:\n";
        for (const auto& contact : contacts) {
            std::cout << "Name: " << contact.name << ", Email: " << contact.email << "\n";
        }
    }
};

int main() {
    ContactManager contactManager;
    int choice;
    std::string name, email;

    do {
        std::cout << "Contact Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Delete Contact\n";
        std::cout << "3. Display All Contacts\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                contactManager.addContact(name, email);
                break;
            case 2:
                std::cout << "Enter name to delete: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                contactManager.deleteContact(name);
                break;
            case 3:
                contactManager.displayAllContacts();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }

        std::cout << "\n";

    } while (choice != 4);

    return 0;
}
