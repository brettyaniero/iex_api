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

#include <stdint.h>

#include "iex_api.h"
#include "portfolio.h"

/***************************************************************************//**
 * Perform analysis on a gainers list of stocks
 *
 * @param   tp                  Pointer to portfolio data structure.
 * @param   params              IEX query parameters data structure.
 *
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus analyze_gainers(TradebotPortfolio *portfolio, IEXParams *params);

#endif /* _ANALYZER_H */
