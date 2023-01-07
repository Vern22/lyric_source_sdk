#ifndef _lyric_http_request_H
#define _lyric_http_request_H

//A helper for doing internet requests. This uses the internet settings the user has set in lyrics3 preferences.
class lyric_http_request : public service_base
{
	FB2K_MAKE_SERVICE_INTERFACE_ENTRYPOINT( lyric_http_request );
public:

	//data should take the form of: [0] = name, [1] = value, [2] = name2, [3] = value2 etc. Should be of even length.
	virtual bool do_post_request(pfc::string_base& output, const char* url, pfc::list_t<pfc::string8>& headers, pfc::list_t<pfc::string8>& data, http_reply::ptr* pReply = NULL) = 0;
	virtual bool do_post_request_legacy(pfc::string_base& output, const char* userAgent, const char* host, WORD port, const char* request, const char* headers, const char* postdata, unsigned int post_size) = 0;
	
	virtual bool do_get_request(pfc::string_base& output, const char* userAgent, const char* url, http_reply::ptr* pReply = NULL) = 0;

	virtual bool download_page( pfc::string_base& output, const char* userAgent, const char* url ) = 0;
};

#endif

