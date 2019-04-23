#ifndef STOCKEXCHANGE_H_
#define STOCKEXCHANGE_H_
#include <StockOrder/StockOrder.h>
#include <map>
#include <queue>

class StockExchange{
public:

private:
    std::map <std::string, std::queue<StockOrder>> buyOrders;
    std::map <std::string, std::queue<StockOrder>> sellOrders;
};

#endif