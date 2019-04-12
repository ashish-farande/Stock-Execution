#include <iostream>
#include "ReadInputData/I_ReadInputData.h"
#include "ReadInputData/ReadInputData.h"



int main(){

    std::vector<StockOrder> orderRequest;
    I_ReadInputData* reader = new ReadInputData();
    orderRequest = reader->getDataFromFile();

    for(StockOrder order: orderRequest)
        reader->printOrder(order);

    return 0;
}