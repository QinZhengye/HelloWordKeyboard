//
// Created by QZY on 2022/12/11.
//

#ifndef HELLOWORDKB_CTRL_STOCK_H
#define HELLOWORDKB_CTRL_STOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cstring>
#include "UserApp.h"

class CStock
{
public:
    static const uint8_t STOCK_CODE_LEN_MAX = 7;    // "600519"
    static const uint8_t STOCK_NAME_LEN_MAX = 16;   // "贵州茅台"

    char Name[STOCK_NAME_LEN_MAX]{};      // 名称
    char Code[STOCK_CODE_LEN_MAX]{};      // 代码

    float Price;                // 当前股价
    float OpenPrice;            // 开盘价
    float pc;                   // 涨跌幅
    float YesterdayPrice;       // 昨日收盘价

    void SetBaseInfo(char const *code, const char *name){
        strcpy(Name, name);
        strcpy(Code, code);
    }

    // 当前价, 开盘价, 涨跌幅, 昨日收盘价
    void UpdateData(float _p, float _op, float _pc, float _ytdp) {
        Price = _p;                // 当前股价
        OpenPrice = _op;            // 开盘价
        pc = _pc;                   // 涨跌幅
        YesterdayPrice = _ytdp;       // 昨日收盘价
    }

private:

};


#ifdef __cplusplus
}
#endif

#endif //HELLOWORDKB_CTRL_STOCK_H
