#include <iostream>
#include "InventoryManager.cpp"

int main() {
    InventoryManager im;
    int choice;

    while (true) {
        std::cout << "\n1 Add\n2 View\n3 Update\n4 Delete\n5 List\n6 Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: im.add(); break;
            case 2: im.view(); break;
            case 3: im.update(); break;
            case 4: im.remove(); break;
            case 5: im.list(); break;
            case 6: return 0;
            default: std::cout << "Invalid choice\n";
        }
    }
}