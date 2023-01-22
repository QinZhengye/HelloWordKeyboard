//
// Created by QZY on 2022/12/11.
//

#ifndef HELLOWORDKB_CTRL_STOCKMANAGER_H
#define HELLOWORDKB_CTRL_STOCKMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Stock.h"


void StockMgr_Init();
void StockMgr_AddFakeData();


class CStockManager
{
public:
    static const uint16_t STOCK_NUM_MAX = 8;

    uint8_t Stock_Add(const char* code, const char* name)
    {
        if (StockNum >= STOCK_NUM_MAX)
            return StockNum;

        ListStock[StockNum++].SetBaseInfo(code, name);
        return StockNum - 1;
    }

    uint8_t StockNum = 0;       // 股票数量
    CStock ListStock[STOCK_NUM_MAX];        // TODO 改List<STOCK_NUM_MAX>
};


extern CStockManager stockManager;


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_STOCKMANAGER_H
