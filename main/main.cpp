#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Welcome to the Adventure Game!\n";
    cout << "You wake up in a dark room. What do you do?\n";
    cout << "1. Look around\n2. Go back to sleep\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You find a door. The adventure begins!\n";
    } else {
        cout << "You fall back asleep... Game Over.\n";
    }

    return 0;
}
