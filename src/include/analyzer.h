/*
 * analyzer.h
 *
 * Functions and data structures related to analysis of stocks.
 *
 * Author:          Brett Yaniero
 * Last modified:   4/14/20 14:11:00
 */

#ifndef _ANALYZER_H
#define _ANALYZER_H

#include "iex_api.h"

/***************************************************************************//**
 * Perform analysis on a gainers list of stocks
 *
 * @param   api_key             Pointer to API key string.
 * @param   list_limit          Number of items to return.
 *
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus analyze_gainers(char *api_key, uint16_t list_limit);

#endif /* _ANALYZER_H */
