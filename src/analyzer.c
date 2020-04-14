/*
 * analyzer.c
 *
 * Functions related to analysis of stocks.
 *
 * Author:          Brett Yaniero
 * Last modified:   4/14/20 14:11:00
 */

#include "analyzer.h"
#include "iex_api.h"

#include <stdlib.h>

TradebotStatus analyze_gainers(char *api_key, uint16_t list_limit)
{
    TradebotStatus status = TRADEBOT_SUCCESS;
    GainersData *data = malloc(sizeof(GainersData) * list_limit);

    status = retrieve_gainers(api_key, list_limit, false, data);

    return status;
}
