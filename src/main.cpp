#include <iostream>
#include <list>
#include <memory>

#include "CSVReader/I_CSVReader.h"
#include "CSVReader/CSVReader.h"
#include "StockOrder/StockOrder.h"
// #include "StockExchange/StockExchange.h"

int main()
{
    std::list<StockOrder> orderRequestList;

    //Read the orders from the file.
    std::shared_ptr<I_CSVReader> reader = std::make_shared<CSVReader>();
    reader->init();

    // Reading and processing the order, one by one
    while (true)
    {
        try
        {
            orderRequestList.push_back(reader->getNextOrder());
        }
        catch (...)
        {
            break;
        }
        // Process the order as soom as we read it.
        StockExchange::getInstance().processCurrentOrder(orderRequestList);
    }

    // Process the orders in the list.
    // StockExchange::getInstance().processAllTheOrders(orderRequestList);

    // The process will be printed and edited as soon as they are entered and modified.
    // Only the open orders will be remaining in the list
    std::cout << "Remaining orders in the list are: " << std::endl;
    for (const auto &order : orderRequestList)
        order.printOrder();

    return 0;
}