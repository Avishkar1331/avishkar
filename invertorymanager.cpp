#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/inventory.h"

class InventoryManager {
public:
    void add() {
        Item item;

        std::cout << "Enter ID: ";
        std::cin >> item.id;

        std::cout << "Enter Name: ";
        std::cin >> item.name;

        std::cout << "Enter Quantity: ";
        std::cin >> item.quantity;

        std::cout << "Enter Price: ";
        std::cin >> item.price;

        item.is_deleted = 0;

        if (add_item(&item))
            std::cout << "Added successfully\n";
        else
            std::cout << "Failed (Duplicate ID?)\n";
    }

    void view() {
        int id;
        std::cout << "Enter ID: ";
        std::cin >> id;

        Item item;
        if (get_item(id, &item)) {
            std::cout << item.id << " "
                      << item.name << " "
                      << item.quantity << " "
                      << item.price << "\n";
        } else {
            std::cout << "Not found\n";
        }
    }

    void update() {
        int id;
        std::cout << "Enter ID: ";
        std::cin >> id;

        Item item;
        item.id = id;

        std::cout << "Enter new name: ";
        std::cin >> item.name;

        std::cout << "Enter quantity: ";
        std::cin >> item.quantity;

        std::cout << "Enter price: ";
        std::cin >> item.price;

        item.is_deleted = 0;

        if (update_item(id, &item))
            std::cout << "Updated\n";
        else
            std::cout << "Failed\n";
    }

    void remove() {
        int id;
        std::cout << "Enter ID: ";
        std::cin >> id;

        if (delete_item(id))
            std::cout << "Deleted\n";
        else
            std::cout << "Not found\n";
    }

    void list() {
        std::vector<Item> items(100);

        int count = list_items(items.data(), 100);
        items.resize(count);

        std::sort(items.begin(), items.end(),
                  [](Item a, Item b) { return a.id < b.id; });

        for (auto &i : items) {
            std::cout << i.id << " "
                      << i.name << " "
                      << i.quantity << " "
                      << i.price << "\n";
        }
    }
};