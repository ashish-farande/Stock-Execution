#include <iostream>
#include "CSVReader/I_CSVReader.h"
#include "CSVReader/CSVReader.h"
#include "StockOrder/StockOrder.h"
#include "StockExchange/StockExchange.h"
#include <map>
#include <memory>



int main(){

    std::queue<StockOrder> orderRequest;
    std::shared_ptr<I_CSVReader> reader (new CSVReader);
    orderRequest = reader->getDataFromFile();

    StockExchange obj;
    obj.processAllTheOrders(orderRequest);

    return 0;
}