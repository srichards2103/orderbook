#include "OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order &order)
{
    if (order.getType() == OrderType::BUY)
    {
        buyOrders.insert({-order.getPrice(), order}); // Negative price for descending order
    }
    else
    {
        sellOrders.insert({order.getPrice(), order});
    }
    matchOrders();
}

void OrderBook::matchOrders()
{
    while (!buyOrders.empty() && !sellOrders.empty())
    {
        auto highestBuy = buyOrders.begin();
        auto lowestSell = sellOrders.begin();

        double buyPrice = -highestBuy->first;
        double sellPrice = lowestSell->first;

        if (buyPrice >= sellPrice)
        {
            int buyQuantity = highestBuy->second.getQuantity();
            int sellQuantity = lowestSell->second.getQuantity();
            int tradedQuantity = std::min(buyQuantity, sellQuantity);

            std::cout << "Trade executed: "
                      << "Buy Order ID " << highestBuy->second.getId()
                      << " and Sell Order ID " << lowestSell->second.getId()
                      << " at Price " << sellPrice
                      << " for Quantity " << tradedQuantity << "\n";

            // Update quantities
            if (buyQuantity > sellQuantity)
            {
                highestBuy->second.setQuantity(buyQuantity - tradedQuantity);
                sellOrders.erase(lowestSell);
            }
            else if (buyQuantity < sellQuantity)
            {
                lowestSell->second.setQuantity(sellQuantity - tradedQuantity);
                buyOrders.erase(highestBuy);
            }
            else
            {
                buyOrders.erase(highestBuy);
                sellOrders.erase(lowestSell);
            }
        }
        else
        {
            break;
        }
    }
}

void OrderBook::displayOrderBook() const
{
    std::cout << "\nCurrent Order Book:\n";
    std::cout << "Buy Orders:\n";
    for (const auto &[price, order] : buyOrders)
    {
        std::cout << "ID: " << order.getId()
                  << ", Price: " << -price
                  << ", Quantity: " << order.getQuantity() << "\n";
    }
    std::cout << "Sell Orders:\n";
    for (const auto &[price, order] : sellOrders)
    {
        std::cout << "ID: " << order.getId()
                  << ", Price: " << price
                  << ", Quantity: " << order.getQuantity() << "\n";
    }
}
