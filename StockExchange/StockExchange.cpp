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
        processOrder(*listIterator);
        if (static_cast<int>((*listIterator).getStatus()))
            listIterator = orders.erase(listIterator);

        else if (listIterator != orders.end())
        {
            listIterator++;
        }

        while (!_listOfOrdersTodestroy.empty())
        {
            orders.remove(*_listOfOrdersTodestroy.front());
            _listOfOrdersTodestroy.pop();
        }
    }


    std::cout<<"Remaining orders in the list are: "<<std::endl;
    for (auto it= orders.begin();it!= orders.end(); ++it)
        (*it).printOrder();



    return true;
}

bool StockExchange::processOrder(StockOrder &order)
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
            sellOrder(order);
        }
        else
        {
            buyOrder(order);
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

bool StockExchange::sellOrder(StockOrder &order)
{

    while (order.getRemainingQuantity() > 0 && !_buyOrders.find(order.getCompanyName())->second.empty())
    {
        if (_buyOrders.find(order.getCompanyName())->second.front()->getRemainingQuantity() >= order.getRemainingQuantity())
        {
            _buyOrders.find(order.getCompanyName())->second.front()->reduceRemainingQuantity(order.getRemainingQuantity());

            order.reduceRemainingQuantity(order.getRemainingQuantity());
        }
        else
        {
            order.reduceRemainingQuantity(_buyOrders.find(order.getCompanyName())->second.front()->getRemainingQuantity());

            _buyOrders.find(order.getCompanyName())->second.front()->reduceRemainingQuantity(_buyOrders.find(order.getCompanyName())->second.front()->getRemainingQuantity());
            _listOfOrdersTodestroy.push(_buyOrders.find(order.getCompanyName())->second.front());
            _buyOrders.find(order.getCompanyName())->second.pop();
        }
    }
    if (_buyOrders.find(order.getCompanyName())->second.empty())
    {
        _sellOrders.find(order.getCompanyName())->second.push(&order);
    }

    return true;
}

bool StockExchange::buyOrder(StockOrder &order)
{
    while (order.getRemainingQuantity() > 0 && !_sellOrders.find(order.getCompanyName())->second.empty())
    {
        if (_sellOrders.find(order.getCompanyName())->second.front()->getRemainingQuantity() >= order.getRemainingQuantity())
        {
            _sellOrders.find(order.getCompanyName())->second.front()->reduceRemainingQuantity(order.getRemainingQuantity());

            order.reduceRemainingQuantity(order.getRemainingQuantity());
        }
        else
        {
            order.reduceRemainingQuantity(_sellOrders.find(order.getCompanyName())->second.front()->getRemainingQuantity());

            _sellOrders.find(order.getCompanyName())->second.front()->reduceRemainingQuantity(_sellOrders.find(order.getCompanyName())->second.front()->getRemainingQuantity());
            _listOfOrdersTodestroy.push(_sellOrders.find(order.getCompanyName())->second.front());
            _sellOrders.find(order.getCompanyName())->second.pop();
        }
    }

    if (_sellOrders.find(order.getCompanyName())->second.empty())
    {
        _buyOrders.find(order.getCompanyName())->second.push(&order);
    }

    return true;
}
