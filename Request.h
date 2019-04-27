#include "Headers.h"
#include "Response.h"

class Request {
    private:
      Headers headers;
      string url;
    public:
      Request();
      Request(string);
      Request(string, Headers);
      string getUrl();
      Headers getHeaders();
      void setUrl(string);
      void setHeader(Headers);
      void print();
      Response getResponse();
};