/*
 * iex_api.h
 *
 * API functions to retreive stock data from the IEX API.
 *
 * A complete API reference can be found here: https://iexcloud.io/docs/api/
 *
 * Author:          Brett Yaniero
 * Last modified:   1/17/20 01:26:00
 * Last updated:    1/17/20 01:26:00
 */

#ifndef _IEX_API_H
#define _IEX_API_H

#include <stdbool.h>
#include <stdint.h>

#include "tradebot_common.h"

#ifdef IEX_SANDBOX_MODE
#define IEX_BASE_URL                        "https://sandbox.iexapis.com/v1/"
#else
#define IEX_BASE_URL                        "https://cloud.iexapis.com/v1/"
#endif

#define IEX_ACCESS_TOKEN_FILE_PATH          "/srv/iex_access_token"

#define IEX_ACCESS_TOKEN_SIZE       35
#define IEX_MAX_URL_LEN             150
#define IEX_MAX_SYMBOL_SIZE         50
#define IEX_MAX_COMPANY_NAME        100
#define IEX_MAX_EXCHANGE_NAME       50
#define IEX_MAX_TIME_OF_RETRIEVAL   20
#define IEX_MAX_SOURCE_SIZE         100
#define IEX_MAX_DATE_SIZE           100

typedef struct {
    char api_key[IEX_ACCESS_TOKEN_SIZE + 1];
    uint16_t list_limit;
    bool display_percent;
    uint16_t rx_list_size;
    char symbol[IEX_MAX_SYMBOL_SIZE];
} IEXParams;

/**
 * IEX Gainers data structure.
 * Data structure containing member variables for the IEX Gainers endpoint.
 */
typedef struct {
    char symbol[IEX_MAX_SYMBOL_SIZE];
    char company_name[IEX_MAX_COMPANY_NAME];
    char primary_exchange[IEX_MAX_EXCHANGE_NAME];
    char calculation_price[IEX_MAX_TIME_OF_RETRIEVAL];
    double open;
    uint32_t open_time;
    char open_source[IEX_MAX_SOURCE_SIZE];
    double close;
    uint32_t close_time;
    char close_source[IEX_MAX_SOURCE_SIZE];
    double high;
    uint32_t high_time;
    char high_source[IEX_MAX_SOURCE_SIZE];
    double low;
    uint32_t low_time;
    char low_source[IEX_MAX_SOURCE_SIZE];
    double latest_price;
    char latest_source[IEX_MAX_TIME_OF_RETRIEVAL];
    char latest_time[IEX_MAX_DATE_SIZE];
    uint32_t latest_update;
    uint32_t latest_volume;
    double iex_realtime_price;
    uint32_t iex_realtime_size;
    uint32_t iex_last_updated;
    double delayed_price;
    uint32_t delayed_price_time;
    double extended_price;
    double extended_change;
    double extended_change_percent;
    uint32_t extended_price_time;
    double previous_close;
    uint32_t previous_volume;
    double change;
    double change_percent;
    uint32_t volume;
    double iex_market_percent;
    uint32_t iex_volume;
    uint32_t avg_total_volume;
    double iex_bid_price;
    double iex_bid_size;
    double iex_ask_price;
    double iex_ask_size;
    uint32_t market_cap;
    double pe_ratio;
    double week_52_high;
    double week_52_low;
    double ytd_change;
    uint32_t last_trade_time;
    bool is_US_market_open;
} QuoteData;

/**
 * IEX Gainers index map enum.
 * Enumeration containing the index positions of each item in the Gainers JSON message.
 */
typedef enum
{
   QUOTE_SYMBOL                      = 0,
   QUOTE_COMPANY_NAME                = 1,
   QUOTE_PRIMARY_EXCHANGE            = 2,
   QUOTE_CALCULATION_PRICE           = 3,
   QUOTE_OPEN                        = 4,
   QUOTE_OPEN_TIME                   = 5,
   QUOTE_OPEN_SOURCE                 = 6,
   QUOTE_CLOSE                       = 7,
   QUOTE_CLOSE_TIME                  = 8,
   QUOTE_CLOSE_SOURCE                = 9,
   QUOTE_HIGH                        = 10,
   QUOTE_HIGH_TIME                   = 11,
   QUOTE_HIGH_SOURCE                 = 12,
   QUOTE_LOW                         = 13,
   QUOTE_LOW_TIME                    = 14,
   QUOTE_LOW_SOURCE                  = 15,
   QUOTE_LATEST_PRICE                = 16,
   QUOTE_LATEST_SOURCE               = 17,
   QUOTE_LATEST_TIME                 = 18,
   QUOTE_LATEST_UPDATE               = 19,
   QUOTE_LATEST_VOLUME               = 20,
   QUOTE_IEX_REALTIME_PRICE          = 21,
   QUOTE_IEX_REALTIME_SIZE           = 22,
   QUOTE_IEX_LAST_UPDATED            = 23,
   QUOTE_DELAYED_PRICE               = 24,
   QUOTE_DELAYED_PRICE_TIME          = 25,
   QUOTE_ODD_LOT_DELAYED_PRICE       = 26,
   QUOTE_ODD_LOT_DELAYED_PRICE_TIME  = 27,
   QUOTE_EXTENDED_PRICE              = 28,
   QUOTE_EXTENDED_CHANGE             = 29,
   QUOTE_EXTENDED_CHANGE_PERCENT     = 30,
   QUOTE_EXTENDED_PRICE_TIME         = 31,
   QUOTE_PREVIOUS_CLOSE              = 32,
   QUOTE_PREVIOUS_VOLUME             = 33,
   QUOTE_CHANGE                      = 34,
   QUOTE_CHANGE_PERCENT              = 35,
   QUOTE_VOLUME                      = 36,
   QUOTE_IEX_MARKET_PERCENT          = 37,
   QUOTE_IEX_VOLUME                  = 38,
   QUOTE_AVG_TOTAL_VOLUME            = 39,
   QUOTE_IEX_BID_PRICE               = 40,
   QUOTE_IEX_BID_SIZE                = 41,
   QUOTE_IEX_ASK_PRICE               = 42,
   QUOTE_IEX_ASK_SIZE                = 43,
   QUOTE_IEX_OPEN                    = 44,
   QUOTE_IEX_OPEN_TIME               = 45,
   QUOTE_IEX_CLOSE                   = 46,
   QUOTE_IEX_CLOSE_TIME              = 47,
   QUOTE_MARKET_CAP                  = 48,
   QUOTE_PE_RATIO                    = 49,
   QUOTE_WEEK_52_HIGH                = 50,
   QUOTE_WEEK_52_LOW                 = 51,
   QUOTE_YTD_CHANGE                  = 52,
   QUOTE_LAST_TRADE_TIME             = 53,
   QUOTE_IS_US_MARKET_OPEN           = 54,
} QuoteMap;

/***************************************************************************//**
 * Loads API key from file.
 *
 * @param   api_key             Pointer to API key string.
 *
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus load_api_key(char *api_key);

/***************************************************************************//**
 * Retrieves a list of top gaining stocks for the day.
 *
 * @param   params              IEX query parameters data structure.
 * @param   data                Pointer to GainersData data structure to
 *                              populate.
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus retrieve_gainers(IEXParams *params, QuoteData *data);

TradebotStatus retrieve_quote(IEXParams *params, QuoteData *data);

#endif /* _IEX_API_H */
