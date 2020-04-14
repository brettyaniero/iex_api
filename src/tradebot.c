
#include "analyzer.h"
#include "https_handler.h"
#include "iex_api.h"
#include "json.h"

#include <stdbool.h>
#include <stdio.h>


TradebotStatus tradebot_loop();

int main(int argc, char *argv[])
{
    /* Initialize the libcurl HTTPS library */
    init_libcurl();

    /* Run through fetch/analyze/trade loop constantly */
    tradebot_loop();

    /* Cleanup the libcurl HTTPS library */
    deinit_libcurl();
}

TradebotStatus tradebot_loop()
{
    TradebotStatus status = TRADEBOT_SUCCESS;

    /* Attempt to load API key from file */
    char *api_key = load_api_key();
    if (!api_key)
    {
        return TRADEBOT_FAIL;
    }

    status = analyze_gainers(api_key, 1);

    free(api_key);

    return status;
}
