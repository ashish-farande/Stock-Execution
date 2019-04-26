#include "CSVReader/I_CSVReader.h"
#include "CSVReader/CSVReader.h"
#include "StockOrder/StockOrder.h"
#include "StockExchange/StockExchange.h"
#include <list>
#include <memory>

int main()
{
    std::list<StockOrder> orderRequestList;

    //Read the orders from the file.
    std::shared_ptr<I_CSVReader> reader(new CSVReader);
    reader->getDataFromFile(orderRequestList);

    // Process the orders in the list.
    StockExchange stockOrderProcessor;
    stockOrderProcessor.processAllTheOrders(orderRequestList);

    // The process will be printed and edited as soon as they are entered and modified.
    
    return 0;
}