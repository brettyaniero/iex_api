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
    for (x = 0; x < array_len; x++)
    {
        /* Process each object in array */
        uint32_t object_len, y;
        object_len = json->u.array.values[x]->u.object.length;
        for (y = 0; y < object_len; y++)
        {
            if (y == 0)
            {
                printf("string: %s\n", json->u.array.values[x]->u.object.values[y].value->u.string.ptr);
            }
        }
    }

    return TRADEBOT_SUCCESS;
}


