/*
 * iex_api.h
 *
 * API functions to retreive stock data from the IEX API.
 *
 * A complete API reference can be found here: https://iexcloud.io/docs/api/
 *
 * Author:          Brett Yaniero
 * Last modified:   1/17/20 01:26:00
 * Last updated: 	1/17/20 01:26:00
 */

#ifndef IEX_API_H_
#define IEX_API_H_

#include "tradebot_common.h"

#define IEX_MAX_URL_LEN 		150

#define IEX_BASE_URL 			"https://cloud.iexapis.com/v1/"
#define IEX_ACCESS_TOKEN 		"sk_8f479ee9b22b4ed2ad369bb53ae66a66"

#define IEX_GAINERS_ENDPOINT 	"stock/market/list/gainers"

TradebotStatus retrieve_gainers();

#endif /* IEX_API_H_ */
