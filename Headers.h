#include <string>
#include "curl/curl.h"

using namespace std;

class Headers {
    private:
      struct curl_slist * heads;
    public:
      Headers();
      Headers(string);
      Headers(const Headers &);
      void add(string, string);
      void remove(string);
      void print();
      struct curl_slist *getCurlChunk();
      ~Headers();
};