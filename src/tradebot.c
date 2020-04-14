
#include <https_handler.h>
#include <iex_api.h>
#include <json.h>
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
    char *api_key = load_api_key();

    status = retrieve_gainers(10, false, api_key);

    free(api_key);

    return status;
}
