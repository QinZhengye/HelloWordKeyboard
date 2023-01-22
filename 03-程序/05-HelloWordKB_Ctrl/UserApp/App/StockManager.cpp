//
// Created by QZY on 2022/12/11.
//

#include "StockManager.h"

CStockManager stockManager;

void StockMgr_Init()
{
    StockMgr_AddFakeData();
}

inline void StockMgr_AddFakeData()
{
    uint8_t idx;
    idx = stockManager.Stock_Add("1A0001", "上证指数");
                                            // 当前价, 开盘价, 涨跌幅, 昨日收盘价
    stockManager.ListStock[idx].UpdateData(3089.26f, 3084.52f, 0.51f, 3073.70f);
    idx = stockManager.Stock_Add("399001", "深证成指");
    stockManager.ListStock[idx].UpdateData(11015.99f, 11046.07f, 0.18f, 10996.41f);
    idx = stockManager.Stock_Add("399006", "创业板指");
    stockManager.ListStock[idx].UpdateData(2346.77f, 2361.97f, -0.11f, 2349.38f);
    idx = stockManager.Stock_Add("600519", "贵州茅台");
    stockManager.ListStock[idx].UpdateData(1727.00f, 1736.00f, 0.47f, 1719.00f);
    idx = stockManager.Stock_Add("300750", "宁德时代");
    stockManager.ListStock[idx].UpdateData(393.42f, 398.50f, -0.14f, 393.96f);
    idx = stockManager.Stock_Add("HK0700", "腾讯控股");
    stockManager.ListStock[idx].UpdateData(334.00f, 339.00f, -0.36f, 335.2f);
}
