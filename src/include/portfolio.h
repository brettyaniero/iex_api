/*
 * portfolio.h
 *
 * Functions and data structures related to managing a porfolio
 * of stocks.
 *
 * Author:          Brett Yaniero
 * Last modified:   4/14/20 17:41:00
 */

#ifndef _PORTFOLIO_H
#define _PORTFOLIO_H

#include <stdint.h>
#include <inttypes.h>

#include "tradebot_common.h"

#define MAX_ALLOWED_STOCKS 10

typedef struct {
    char symbol[20];
    char company_name[100];
    char primary_exchange[50];
    double latest_price;
    uint32_t latest_volume;
    double buy_price;
    double sell_price;
} Stock;

typedef struct {
    char name[50];
    Stock stocks[MAX_ALLOWED_STOCKS];
    uint32_t num_stocks;
    double net_profit;
} TradebotPortfolio;

/***************************************************************************//**
 * Purchases a stock and adds it to the specified portfolio.
 *
 * @param   tp                  Pointer to a portfolio data structure to add
 *                              the stock to.
 * @param   stock               Pointer to the stock data structure to insert
 *                              into the portfolio.
 *
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus buy(TradebotPortfolio *tp, Stock *stock);

/***************************************************************************//**
 * Sells a stock and removes it from the specified portfolio.
 *
 * @param   tp                  Pointer to a portfolio data structure to remove
 *                              the stock from.
 * @param   stock               Pointer to the stock data structure to remove
 *                              from the portfolio.
 *
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus sell(TradebotPortfolio *tp, Stock *stock);

#endif /* _PORTFOLIO_H */
