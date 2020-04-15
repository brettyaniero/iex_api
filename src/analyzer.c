/*
 * analyzer.c
 *
 * Functions related to analysis of stocks.
 *
 * Author:          Brett Yaniero
 * Last modified:   4/14/20 14:11:00
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "analyzer.h"
#include "iex_api.h"
#include "portfolio.h"

TradebotStatus analyze_gainers(TradebotPortfolio *tp, IEXParams *params)
{
    TradebotStatus status = TRADEBOT_SUCCESS;
    GainersData *data = malloc(sizeof(GainersData) * params->list_limit);

    status = retrieve_gainers(params, data);

    /* Loop through each stock in the gainers list */


    return status;
}
