#include <iostream>
#include "CSVReader/I_CSVReader.h"
#include "CSVReader/CSVReader.h"
#include "StockOrder/StockOrder.h"
#include <map>
#include <memory>



int main(){

    std::queue<StockOrder> orderRequest;
    std::shared_ptr<I_CSVReader> reader (new CSVReader);
    orderRequest = reader->getDataFromFile();

    std::map <std::string, std::queue<StockOrder>> buyOrders;
    std::map <std::string, std::queue<StockOrder>> sellOrders;

    // while(!orderRequest.empty())
    // {
    //     auto it = buyOrders.find(orderRequest.front().getCompanyName());
    //     if(it == buyOrders.end())
    //     {
    //         //The company is in with first transaction
    //         buyOrders.insert(std::pair<std::string, std::queue<StockOrder>>(orderRequest.front().getCompanyName(), std::queue<StockOrder>));
    //     }
    // }

    return 0;
}