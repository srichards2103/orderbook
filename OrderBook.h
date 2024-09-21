#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <vector>
#include <map>

class OrderBook
{
public:
    void addOrder(const Order &order);
    void matchOrders();
    void displayOrderBook() const;

private:
    std::multimap<double, Order> buyOrders;  // Key: Price (negative for descending order), Value: Order
    std::multimap<double, Order> sellOrders; // Key: Price, Value: Order
};

#endif // ORDERBOOK_H
