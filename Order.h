#ifndef ORDER_H
#define ORDER_H

#include <string>

enum class OrderType
{
    BUY,
    SELL
};

class Order
{
public:
    Order(int id, OrderType type, double price, int quantity);

    int getId() const;
    OrderType getType() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int quantity);

private:
    int id;
    OrderType type;
    double price;
    int quantity;
};

#endif // ORDER_H
