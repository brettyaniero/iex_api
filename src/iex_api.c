/*
 * iex_api.c
 *
 * API functions to retreive stock data from the IEX API.
 *
 * A complete API reference can be found here: https://iexcloud.io/docs/api/
 *
 * Author:          Brett Yaniero
 * Last modified:   1/17/20 01:26:00
 * Last updated: 	1/17/20 01:26:00
 */

#include "https_handler.h"
#include "iex_api.h"

TradebotStatus retrieve_gainers()
{
	TradebotStatus status = TRADEBOT_SUCCESS;

	/* Build API URL string */
	char target_url[IEX_MAX_URL_LEN];
	snprintf(target_url, sizeof(target_url), "%s%s%s%s", IEX_BASE_URL,
			IEX_GAINERS_ENDPOINT, "?token=", IEX_ACCESS_TOKEN);

	char buf[100000] = {0};

	status = https_request(buf, target_url);

	if (status != TRADEBOT_SUCCESS) {
		printf("ERROR\n");
		return status;
	}

	// json_char *json = (json_char*) buf;

	// json_value *value = json_parse(json, 100000);

	// if (status != TRADEBOT_SUCCESS) {
		// printf("ERROR\n");
		// exit(1);
	// }

	// process_value(value, 0);


	return status;
}
