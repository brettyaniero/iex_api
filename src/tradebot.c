
#include <stdbool.h>
#include <stdio.h>

#include "analyzer.h"
#include "https_handler.h"
#include "iex_api.h"
#include "json.h"
#include "portfolio.h"

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
    TradebotPortfolio tp;
    IEXParams params;

    /* Attempt to load API key from file */
    load_api_key(params.api_key);
    if (!params.api_key)
    {
        return TRADEBOT_FAIL;
    }

    status = analyze_gainers(&tp, &params);

    return status;
}
