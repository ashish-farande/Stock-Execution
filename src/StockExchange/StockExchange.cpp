#include "StockExchange.h"

#include <iostream>
#include <algorithm>

StockExchange::StockExchange()
{
}

StockExchange::~StockExchange()
{
}

bool StockExchange::processAllTheOrders(std::list<StockOrder> &orders)
{
    std::list<StockOrder>::iterator listIterator = orders.begin();
    while (listIterator != orders.end())
    {
        processOrder(*listIterator, orders);
        if (static_cast<int>((*listIterator).getStatus()))
            listIterator = orders.erase(listIterator);

        else if (listIterator != orders.end())
        {
            listIterator++;
        }
    }
    
    return true;
}

bool StockExchange::processOrder(StockOrder &order, std::list<StockOrder> &orders)
{
    if (!checkCompanyInMap(order.getCompanyName()))
    {
        addComapnyToMap(order.getCompanyName());
        if (static_cast<int>(order.getSide()))
        {
            _sellOrders.find(order.getCompanyName())->second.push(&order);
        }
        else
        {
            _buyOrders.find(order.getCompanyName())->second.push(&order);
        }
    }

    else
    {
        if (static_cast<int>(order.getSide()))
        {
            sellOrder(order, orders);
        }
        else
        {
            buyOrder(order, orders);
        }
    }
    return true;
}

bool StockExchange::checkCompanyInMap(const std::string &companyName)
{
    if (_buyOrders.find(companyName) == _buyOrders.end())
        return false;
    return true;
}

bool StockExchange::addComapnyToMap(const std::string &companyName)
{
    // _buyOrders[companyName];
    // _sellOrders[companyName];
    _buyOrders.insert(std::pair<std::string, std::queue<StockOrder *>>(companyName, std::queue<StockOrder *>()));
    _sellOrders.insert(std::pair<std::string, std::queue<StockOrder *>>(companyName, std::queue<StockOrder *>()));

    return true;
}

bool StockExchange::sellOrder(StockOrder &order, std::list<StockOrder> &orders)
{
     
    while (order.getRemainingQuantity() > 0 && !_buyOrders.find(order.getCompanyName())->second.empty())
    {
        StockOrder *firstOrderInQueue = _buyOrders.find(order.getCompanyName())->second.front();

        if (firstOrderInQueue->getRemainingQuantity() >= order.getRemainingQuantity())
        {
            firstOrderInQueue->reduceRemainingQuantity(order.getRemainingQuantity());

            order.reduceRemainingQuantity(order.getRemainingQuantity());
        }
        else
        {
            order.reduceRemainingQuantity(firstOrderInQueue->getRemainingQuantity());

            firstOrderInQueue->reduceRemainingQuantity(firstOrderInQueue->getRemainingQuantity());
            orders.remove(*firstOrderInQueue);
            _buyOrders.find(order.getCompanyName())->second.pop();
        }
    }
    if (_buyOrders.find(order.getCompanyName())->second.empty())
    {
        _sellOrders.find(order.getCompanyName())->second.push(&order);
    }

    return true;
}

bool StockExchange::buyOrder(StockOrder &order, std::list<StockOrder> &orders)
{
    while (order.getRemainingQuantity() > 0 && !_sellOrders.find(order.getCompanyName())->second.empty())
    {
        StockOrder *firstOrderInQueue = _sellOrders.find(order.getCompanyName())->second.front();

        if (firstOrderInQueue->getRemainingQuantity() >= order.getRemainingQuantity())
        {
            firstOrderInQueue->reduceRemainingQuantity(order.getRemainingQuantity());

            order.reduceRemainingQuantity(order.getRemainingQuantity());
        }
        else
        {
            order.reduceRemainingQuantity(firstOrderInQueue->getRemainingQuantity());

            firstOrderInQueue->reduceRemainingQuantity(firstOrderInQueue->getRemainingQuantity());
            orders.remove(*firstOrderInQueue);
            _sellOrders.find(order.getCompanyName())->second.pop();
        }
    }

    if (_sellOrders.find(order.getCompanyName())->second.empty())
    {
        _buyOrders.find(order.getCompanyName())->second.push(&order);
    }

    return true;
}
