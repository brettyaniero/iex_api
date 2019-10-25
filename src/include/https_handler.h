/*
 * https_handler.h
 *
 * Setup-related functions for working with the libcurl multiprotocol
 * file transfer library.
 *
 * Author:          Brett Yaniero
 * Last modified:   10/25/19 14:29:00 
 */

#include <stdint.h>
#include <curl/curl.h>
#include "tradebot_common.h"

struct libcurl_string
{
    char *ptr;
    size_t len;
};

/***************************************************************************//**
 * Initializes the libcurl library. This function must be called before the
 * program calls any other function in libcurl. The environment it
 * sets up is constant for the life of the program.
 *
 * @return  TradebotStatus    Result of operation.  
 ******************************************************************************/
 TradebotStatus init_libcurl(void);

/***************************************************************************//**
 * Initiate an HTTPS request to the target URL. 
 *
 * @param   res_buf             The response buffer of the HTTPS transaction.
 * @param   url                 The target URL of the HTTPS request.
 * @return  TradebotStatus      Result of operation.  
 ******************************************************************************/
 TradebotStatus https_request(char *res_buf, char *url);
