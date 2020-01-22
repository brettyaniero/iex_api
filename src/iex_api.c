/*
 * iex_api.c
 *
 * API functions to retrieve stock data from the IEX API.
 *
 * A complete API reference can be found here: https://iexcloud.io/docs/api/
 *
 * Author:          Brett Yaniero
 * Last modified:   1/17/20 01:26:00
 * Last updated:    1/17/20 01:26:00
 */

#include "https_handler.h"
#include "iex_api.h"
#include "json.h"

TradebotStatus process_gainers(json_value *json);

TradebotStatus retrieve_gainers(uint16_t list_limit, bool display_percent)
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

    json_char *json = (json_char*) buf;

    json_value *value = json_parse(json, 100000);

    if (status != TRADEBOT_SUCCESS) {
        printf("ERROR\n");
        exit(1);
    }

    process_gainers(value);

    return status;
}

TradebotStatus process_gainers(json_value *json)
{
    if (json == NULL)
    {
        return TRADEBOT_FAIL;
    }

    /* Process array */
    uint32_t array_len, x;
    array_len = json->u.array.length;
    GainersData data[array_len];

    for (x = 0; x < array_len; x++)
    {
        /* Process each object in array */
        strncpy(data[x].symbol,
                json->u.array.values[x]->u.object.values[GAINERS_SYMBOL].value->u.string.ptr,
                IEX_MAX_SYMBOL_SIZE - 1);
        strncpy(data[x].company_name,
                        json->u.array.values[x]->u.object.values[GAINERS_COMPANY_NAME].value->u.string.ptr,
                        IEX_MAX_COMPANY_NAME - 1);
        data[x].latest_price = json->u.array.values[x]->u.object.values[GAINERS_LATEST_PRICE].value->u.dbl;

        printf("symbol: %s\n", data[x].symbol);
        printf("company name: %s\n", data[x].company_name);
        printf("latest price: %f\n", data[x].latest_price);
    }

    return TRADEBOT_SUCCESS;
}


