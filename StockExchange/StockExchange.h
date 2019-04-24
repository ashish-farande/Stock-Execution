#ifndef STOCKEXCHANGE_H_
#define STOCKEXCHANGE_H_
#include <StockOrder/StockOrder.h>
#include <map>
#include <queue>
#include <vector>

class StockExchange{

public:
    StockExchange();
    ~StockExchange();
    
    bool processAllTheOrders(std::queue<StockOrder> orders);

private:
    bool processOrder(StockOrder& order);
    bool checkCompanyInMap(const std::string& companyName);
    bool addComapnyToMap(const std::string& companyName);
    bool buyOrder(StockOrder& order);
    bool sellOrder(StockOrder& order);

    void printSellOrderMap();
    void printBuyOrderMap();


private:
    std::map <std::string, std::queue<StockOrder*>> _buyOrders;
    std::map <std::string, std::queue<StockOrder*>> _sellOrders;
    std::vector <StockOrder> _listOfOrders;
};

#endif