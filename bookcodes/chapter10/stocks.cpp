// stocks.cpp -- the whole program
#include <iostream>
#include "stocks00.h"

int main()
{
    Stock stock1;
    stock1.acquire("NanoSmart", 20, 12.50);
    stock1.show();
    stock1.buy(15, 18.25);
    stock1.show();
    stock1.sell(400, 20.00);
    stock1.show();
    std::cin.get();
    return 0;
}
