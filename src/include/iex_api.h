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

#include "tradebot_common.h"

#define IEX_BASE_URL                "https://cloud.iexapis.com/v1/"
#define IEX_ACCESS_TOKEN_FILE_PATH  "/srv/iex_access_token"

#define IEX_GAINERS_ENDPOINT        "stock/market/list/gainers"

#define IEX_ACCESS_TOKEN_SIZE       35
#define IEX_MAX_URL_LEN             150
#define IEX_MAX_SYMBOL_SIZE         50
#define IEX_MAX_COMPANY_NAME        100
#define IEX_MAX_EXCHANGE_NAME       50
#define IEX_MAX_TIME_OF_RETRIEVAL   20
#define IEX_MAX_SOURCE_SIZE         100
#define IEX_MAX_DATE_SIZE           100

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
} GainersData;

/**
 * IEX Gainers index map enum.
 * Enumeration containing the index positions of each item in the Gainers JSON message.
 */
typedef enum
{
    GAINERS_SYMBOL                      = 0,
    GAINERS_COMPANY_NAME                = 1,
    GAINERS_PRIMARY_EXCHANGE            = 2,
    GAINERS_CALCULATION_PRICE           = 3,
    GAINERS_OPEN                        = 4,
    GAINERS_OPEN_TIME                   = 5,
    GAINERS_OPEN_SOURCE                 = 6,
    GAINERS_CLOSE                       = 7,
    GAINERS_CLOSE_TIME                  = 8,
    GAINERS_CLOSE_SOURCE                = 9,
    GAINERS_HIGH                        = 10,
    GAINERS_HIGH_TIME                   = 11,
    GAINERS_HIGH_SOURCE                 = 12,
    GAINERS_LOW                         = 13,
    GAINERS_LOW_TIME                    = 14,
    GAINERS_LOW_SOURCE                  = 15,
    GAINERS_LATEST_PRICE                = 16,
    GAINERS_LATEST_SOURCE               = 17,
    GAINERS_LATEST_TIME                 = 18,
    GAINERS_LATEST_UPDATE               = 19,
    GAINERS_LATEST_VOLUME               = 20,
    GAINERS_IEX_REALTIME_PRICE          = 21,
    GAINERS_IEX_REALTIME_SIZE           = 22,
    GAINERS_IEX_LAST_UPDATED            = 23,
    GAINERS_DELAYED_PRICE               = 24,
    GAINERS_DELAYED_PRICE_TIME          = 25,
    GAINERS_ODD_LOT_DELAYED_PRICE       = 26,
    GAINERS_ODD_LOT_DELAYED_PRICE_TIME  = 27,
    GAINERS_EXTENDED_PRICE              = 28,
    GAINERS_EXTENDED_CHANGE             = 29,
    GAINERS_EXTENDED_CHANGE_PERCENT     = 30,
    GAINERS_EXTENDED_PRICE_TIME         = 31,
    GAINERS_PREVIOUS_CLOSE              = 32,
    GAINERS_PREVIOUS_VOLUME             = 33,
    GAINERS_CHANGE                      = 34,
    GAINERS_CHANGE_PERCENT              = 35,
    GAINERS_VOLUME                      = 36,
    GAINERS_IEX_MARKET_PERCENT          = 37,
    GAINERS_IEX_VOLUME                  = 38,
    GAINERS_AVG_TOTAL_VOLUME            = 39,
    GAINERS_IEX_BID_PRICE               = 40,
    GAINERS_IEX_BID_SIZE                = 41,
    GAINERS_IEX_ASK_PRICE               = 42,
    GAINERS_IEX_ASK_SIZE                = 43,
    GAINERS_IEX_OPEN                    = 44,
    GAINERS_IEX_OPEN_TIME               = 45,
    GAINERS_IEX_CLOSE                   = 46,
    GAINERS_IEX_CLOSE_TIME              = 47,
    GAINERS_MARKET_CAP                  = 48,
    GAINERS_PE_RATIO                    = 49,
    GAINERS_WEEK_52_HIGH                = 50,
    GAINERS_WEEK_52_LOW                 = 51,
    GAINERS_YTD_CHANGE                  = 52,
    GAINERS_LAST_TRADE_TIME             = 53,
    GAINERS_IS_US_MARKET_OPEN           = 54,
} GainersMap;

/***************************************************************************//**
 * Loads API key from file.
 *
 * @return  char *              Pointer to API key string, if one is found.
 *                              NULL if error occurred.
 ******************************************************************************/
char *load_api_key();

/***************************************************************************//**
 * Retrieves a list of top gaining stocks for the day.
 *
 * @param   api_key             Pointer to API key string.
 * @param   list_limit          Number of items to return.
 * @param   display_percent     If set to true, all percentage values will be
 *                              multiplied by a factor of 100.
 * @param   data                Pointer to GainersData data structure to
 *                              populate.
 * @return  TradebotStatus      Result of operation.
 ******************************************************************************/
TradebotStatus retrieve_gainers(char *api_key, uint16_t list_limit,
        bool display_percent, GainersData *data);

#endif /* _IEX_API_H */
