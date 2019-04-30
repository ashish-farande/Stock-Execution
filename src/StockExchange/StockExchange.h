#ifndef STOCKEXCHANGE_H_
#define STOCKEXCHANGE_H_

#include <map>
#include <list>
#include <queue>

#include <StockOrder/StockOrder.h>

class StockExchange
{

public:
  static StockExchange &getInstance();
  ~StockExchange();

  bool processAllTheOrders(std::list<StockOrder> &orders);
  bool processCurrentOrder(std::list<StockOrder> &orders);

private:
  StockExchange();
  bool processOrder(StockOrder &order, std::list<StockOrder> &orders);
  bool checkCompanyInMap(const CompanyName &companyName);
  bool addComapnyToMap(const CompanyName &companyName);
  bool buyOrder(StockOrder &order, std::list<StockOrder> &orders);
  bool sellOrder(StockOrder &order, std::list<StockOrder> &orders);

private:
  std::map<std::string, std::queue<StockOrder *>> _buyOrders;
  std::map<std::string, std::queue<StockOrder *>> _sellOrders;
};

#endif