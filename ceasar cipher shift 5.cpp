#include <iostream>
#include <string>
using namespace std;

// Function to encrypt a string using Caesar Cipher
string caesarEncrypt(string text, int key) {
    string result = "";

    // Classic for loop iterating through string by index
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];  // current character

        if (ch >= 'A' && ch <= 'Z') {
            // Encrypt uppercase letters
            result += char((ch - 'A' + key) % 26 + 'A');
        } 
        else if (ch >= 'a' && ch <= 'z') {
            // Encrypt lowercase letters
            result += char((ch - 'a' + key) % 26 + 'a');
        } 
        else {
            // Keep spaces and punctuation unchanged
            result += ch;
        }
    }
    return result;
}

// Function to decrypt a string using Caesar Cipher
string caesarDecrypt(string text, int key) {
    // Decryption is the same as encryption with (26 - key)
    return caesarEncrypt(text, 26 - key);
}

int main() {
    string text;  // user input
    int key;      // shift value
    int choice;   // 1 = encrypt, 2 = decrypt

    cout << "=== Caesar Cipher Program ===\n";

    cout << "Enter your sentence: ";
    getline(cin, text);  // input entire line

    cout << "Enter shift key (1-25): ";
    cin >> key;

    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        string encrypted = caesarEncrypt(text, key);
        cout << "\nEncrypted Text: " << encrypted << endl;
    } 
    else if (choice == 2) {
        string decrypted = caesarDecrypt(text, key);
        cout << "\nDecrypted Text: " << decrypted << endl;
    } 
    else {
        cout << "\nInvalid choice!" << endl;
    }

    return 0;
}
