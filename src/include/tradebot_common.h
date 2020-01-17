/*
 * tradebot_common.h
 *
 * Data structures and status codes for the tradebot platform.
 *
 * Author:          Brett Yaniero
 * Last modified:   10/25/19 15:00:00
 * Last updated: 	1/16/20 12:01:00
 */

#ifndef TRADEBOT_COMMON_H_
#define TRADEBOT_COMMON_H_

#include <stdint.h>

#define MAX_ALLOWED_STOCKS 10

 typedef enum 
 {
     TRADEBOT_SUCCESS = 0,
     TRADEBOT_FAIL = 1,
     TRADEBOT_UNKNOWN = 2,
 } TradebotStatus;

 typedef struct
 {
	 char symbol[20];
	 char company_name[100];
	 char primary_exchange[50];
	 double latest_price;
	 uint32_t latest_volume;
	 double buy_price;
	 double sell_price;
 } Stock;

 typedef struct
 {
	 char name[50];
	 Stock stocks[MAX_ALLOWED_STOCKS];
 } TradebotPortfolio;

#endif
