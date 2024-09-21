#include "OrderBook.h"
#include <iostream>

int main()
{
    OrderBook orderBook;

    int choice = 0;
    int orderId = 1;

    while (choice != 4)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Buy Order\n";
        std::cout << "2. Add Sell Order\n";
        std::cout << "3. Display Order Book\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";

        std::cin >> choice;

        if (choice == 1 || choice == 2)
        {
            double price;
            int quantity;
            std::cout << "Enter price: ";
            std::cin >> price;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            OrderType type = (choice == 1) ? OrderType::BUY : OrderType::SELL;
            Order order(orderId++, type, price, quantity);
            orderBook.addOrder(order);
        }
        else if (choice == 3)
        {
            orderBook.displayOrderBook();
        }
        else if (choice == 4)
        {
            std::cout << "Exiting.\n";
        }
        else
        {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
