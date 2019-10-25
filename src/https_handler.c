/*
 * https_handler.c
 *
 * Setup-related functions for working with the libcurl multiprotocol
 * file transfer library.
 *
 * Author:          Brett Yaniero
 * Last modified:   10/25/19 14:29:00 
 */

size_t libcurl_writefunc(void *ptr, size_t size, size_t nmemb, struct libcurl_string *data);

TradebotStatus init_libcurl(void)
{
    TradebotStatus status = TRADEBOT_SUCCESS;

    CURLcode result = curl_global_init(CURL_GLOBAL_DEFAULT);

    if (result != CURLE_OK)
    {
        status = TRADEBOT_FAIL;
    }

    return status;
}

// TODO: Copy libcurl_string into user buffer
TradebotStatus https_request(char *res_buf, char *url)
{
    TradebotStatus status = TRADEBOT_SUCCESS;
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if (curl)
    {
        struct libcurl_string s;
        s.len = 0;
        s.ptr = malloc(s.len + 1);
        s.ptr[0] = '\0';

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, libcurl_writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s); 
    }
    else
    {
        status = TRADEBOT_FAIL;
    }

#ifdef SKIP_PEER_VERIFICATION
    /*
     * If you want to connect to a site who isn't using a certificate that is
     * signed by one of the certs in the CA bundle you have, you can skip the
     * verification of the server's certificate. This makes the connection
     * A LOT LESS SECURE.
     *
     * If you have a CA cert for the server stored someplace else than in the
     * default bundle, then the CURLOPT_CAPATH option might come handy for
     * you.
     */ 
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif
 
#ifdef SKIP_HOSTNAME_VERIFICATION
    /*
     * If the site you're connecting to uses a different host name that what
     * they have mentioned in their server certificate's commonName (or
     * subjectAltName) fields, libcurl will refuse to connect. You can skip
     * this check, but this will make the connection less secure.
     */ 
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    /* Check for errors */
    if (res != CURLE_OK)
    {
        status = TRADEBOT_FAIL; 
    }

    curl_easy_cleanup(curl);

    return status;
}

size_t libcurl_writefunc(void *ptr, size_t size, size_t nmemb, struct string *data)
{
    size_t new_len = s->len + (size * nmemb);
    s->ptr = realloc(s->ptr, new_len + 1);

    if (s->ptr == NULL) 
    {
        fprintf(stderr, "libcurl realloc() failed\n");
    }

    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return (size * nmemb);
}
