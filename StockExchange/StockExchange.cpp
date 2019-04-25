#include "StockExchange.h"
#include <iostream>

StockExchange::StockExchange()
{
}

StockExchange::~StockExchange()
{
}

bool StockExchange::processAllTheOrders(std::list<StockOrder>& orders)
{
    std::list<StockOrder>::iterator it1 = orders.begin();
    for(;it1!=orders.end();)
    {
        processOrder(*it1);
        if((*it1).getStatus())
             it1 = orders.erase(it1);  
        
        else if(it1!=orders.end())
        {
            it1++;
        }
    }

    // for (auto &order : _listOfOrders)

    while(!_listOfOrdersTodestroy.empty())
    {
        // orders.remove(*_listOfOrdersTodestroy.front());
        _listOfOrdersTodestroy.front()->printOrder();
        _listOfOrdersTodestroy.pop();
    }
    return true;
}

bool StockExchange::processOrder(StockOrder &order)
{
    if (!checkCompanyInMap(order.getCompanyName()))
    {
        addComapnyToMap(order.getCompanyName());
        if (order.getSide())
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
        if (order.getSide())
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

void StockExchange::printSellOrderMap()
{
    std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "Sell Order Map" << std::endl;
    for (auto it = _sellOrders.begin(); it != _sellOrders.end(); ++it)
    {
        std::cout << it->first << std::endl;
        if (!it->second.empty())
            it->second.front()->printOrder();
        std::cout << std::endl;
    }
    std::cout << "////////////////////////////////////////////////////////////////////////////\n"
              << std::endl;
}

void StockExchange::printBuyOrderMap()
{
    std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "Buy Order Map" << std::endl;
    for (auto it = _buyOrders.begin(); it != _buyOrders.end(); it++)
    {
        std::cout << it->first << std::endl;
        if (!it->second.empty())
        {
            it->second.front()->printOrder();
            std::cout << "The Address is: " << &it->second.front() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "////////////////////////////////////////////////////////////////////////////\n"
              << std::endl;
}