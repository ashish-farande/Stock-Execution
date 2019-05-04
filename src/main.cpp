#include <iostream>
#include <list>
#include <memory>
#include <chrono>

#include "CSVReader/I_CSVReader.h"
#include "CSVReader/CSVReader.h"
#include "StockOrder/StockOrder.h"
#include "StockExchange/StockExchange.h"

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();

    std::list<StockOrder> orderRequestList;

    //Read the orders from the file.
    std::shared_ptr<I_CSVReader> reader = std::make_shared<CSVReader>();
    reader->init();

    // Reading and processing the order, one by one
    while (true)
    {
        try
        {
            orderRequestList.push_back(std::move(reader->getNextOrder()));
        }
        catch (std::string &e)
        {
            std::cout << e << std::endl;
            break;
        }
        // Process the order as soom as we read it.
        StockExchange::getInstance().processCurrentOrder(orderRequestList);
    }

    // Process the orders in the list.
    // StockExchange::getInstance().processAllTheOrders(orderRequestList);

    // The process will be printed and edited as soon as they are entered and modified.
    // Only the open orders will be remaining in the list
    std::cout << "\nRemaining orders in the list are: " << std::endl;
    for (const auto &order : orderRequestList)
        order.printOrder();

    auto t2 = std::chrono::high_resolution_clock::now();

    std::cout << "The software took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds" << std::endl;
    return 0;
}