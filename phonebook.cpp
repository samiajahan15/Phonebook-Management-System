#include <bits/stdc++.h>
#include <limits>
using namespace std;
struct Contact
{
    string name;
    string phone;
};

// Convert a string to lowercase for case-insensitive comparison
string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}


// Bubble sort contacts by name
void bubbleSortContacts(vector<Contact> &contacts)
{
    int n = contacts.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (toLowerCase(contacts[j].name) > toLowerCase(contacts[j + 1].name))
            {
                Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}
// Check if a contact name already exists
bool isDuplicateName(const vector<Contact> &contacts, string name)
{
    string lowerName = toLowerCase(name);

    for (int i = 0; i < contacts.size(); i++)
    {
        if (toLowerCase(contacts[i].name) == lowerName)
        {
            return true;
        }
    }
    return false;
}
// Binary search contact by name
int binarySearchContact(const vector<Contact> &contacts, string target)
{
    int left = 0;
    int right = contacts.size() - 1;
    string lowerTarget = toLowerCase(target);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        string midName = toLowerCase(contacts[mid].name);

        if (midName == lowerTarget)
        {
            return mid;
        }
        else if (midName < lowerTarget)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
// Add a new contact
void addContact(vector<Contact> &contacts)
{
    string name, phone;

    cout << "\nEnter contact name: ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    if (isDuplicateName(contacts, name))
    {
        cout << "Contact with this name already exists.\n";
        return;
    }

    cout << "Enter phone number: ";
    getline(cin, phone);

    if (phone.empty())
    {
        cout << "Phone number cannot be empty.\n";
        return;
    }

    Contact newContact;
    newContact.name = name;
    newContact.phone = phone;

    contacts.push_back(newContact);
    bubbleSortContacts(contacts);

    cout << "Contact added successfully.\n";
}
// Display all contacts
void displayContacts(const vector<Contact> &contacts)
{
    if (contacts.empty())
    {
        cout << "\nPhonebook is empty.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";
    for (int i = 0; i < contacts.size(); i++)
    {
        cout << i + 1 << ". Name: " << contacts[i].name
             << " | Phone: " << contacts[i].phone << "\n";
    }
}
// Search contact
void searchContact(const vector<Contact> &contacts)
{
    if (contacts.empty())
    {
        cout << "\nPhonebook is empty.\n";
        return;
    }

    string name;
    cout << "\nEnter contact name to search: ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    int index = binarySearchContact(contacts, name);

    if (index == -1)
    {
        cout << "Contact not found.\n";
    }
    else
    {
        cout << "\nContact found:\n";
        cout << "Name: " << contacts[index].name << "\n";
        cout << "Phone: " << contacts[index].phone << "\n";
    }
}
// Edit phone number
void editNumber(vector<Contact> &contacts)
{
    if (contacts.empty())
    {
        cout << "\nPhonebook is empty.\n";
        return;
    }

    string name;
    cout << "\nEnter contact name to edit: ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    int index = binarySearchContact(contacts, name);

    if (index == -1)
    {
        cout << "Contact not found.\n";
        return;
    }

    string newPhone;
    cout << "Enter new phone number: ";
    getline(cin, newPhone);

    if (newPhone.empty())
    {
        cout << "Phone number cannot be empty.\n";
        return;
    }

    contacts[index].phone = newPhone;
    cout << "Phone number updated successfully.\n";
}
// Delete contact
void deleteContact(vector<Contact> &contacts)
{
    if (contacts.empty())
    {
        cout << "\nPhonebook is empty.\n";
        return;
    }

    string name;
    cout << "\nEnter contact name to delete: ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    int index = binarySearchContact(contacts, name);

    if (index == -1)
    {
        cout << "Contact not found.\n";
        return;
    }

    contacts.erase(contacts.begin() + index);
    cout << "Contact deleted successfully.\n";
}

void showMenu()
{
    cout << "\n===== Phonebook Management System =====\n";
    cout << "1. Add Contact\n";
    cout << "2. Display Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Edit Number\n";
    cout << "5. Delete Contact\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    vector<Contact> contacts;
    int choice;

    do
    {
        showMenu();

        cin >> choice;
        // cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            editNumber(contacts);
            break;
        case 5:
            deleteContact(contacts);
            break;
        case 6:
            cout << "Exiting program!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}