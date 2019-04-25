#include <iostream>
#include "CSVReader/I_CSVReader.h"
#include "CSVReader/CSVReader.h"
#include "StockOrder/StockOrder.h"
#include "StockExchange/StockExchange.h"
#include <map>
#include <list>
#include <memory>



int main(){

    std::list<StockOrder> orderRequest;
    std::shared_ptr<I_CSVReader> reader (new CSVReader);
    reader->getDataFromFile(orderRequest);
    
    StockExchange obj;
    obj.processAllTheOrders(orderRequest);

    return 0;
}