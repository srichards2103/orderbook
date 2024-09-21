#include "Order.h"

Order::Order(int id, OrderType type, double price, int quantity)
    : id(id), type(type), price(price), quantity(quantity) {}

int Order::getId() const
{
    return id;
}

OrderType Order::getType() const
{
    return type;
}

double Order::getPrice() const
{
    return price;
}

int Order::getQuantity() const
{
    return quantity;
}

void Order::setQuantity(int quantity)
{
    this->quantity = quantity;
}
