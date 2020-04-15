/*
 * portfolio.c
 *
 * Functions and data structures related to managing a porfolio
 * of stocks.
 *
 * Author:          Brett Yaniero
 * Last modified:   4/14/20 17:41:00
 */

#include <string.h>
#include <stdio.h>

#include "portfolio.h"

TradebotStatus buy(TradebotPortfolio *tp, Stock *stock)
{
    printf("Num stocks: %" PRIu32 "\n", tp->num_stocks);

    /* Check if the specified portfolio has space for any more stocks */
    if (tp->num_stocks >= MAX_ALLOWED_STOCKS)
        return TRADEBOT_FAIL;

    if (!stock)
        return TRADEBOT_FAIL;

    /* Add stock to portfolio */
    memcpy(&(tp->stocks[tp->num_stocks]), stock, sizeof(Stock));
    tp->num_stocks++;

    return TRADEBOT_SUCCESS;
}
