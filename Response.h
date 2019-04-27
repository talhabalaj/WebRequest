#include <iostream>

using namespace std;

class Response {
    private:
      string responseString;
      int statusCode;

    public:
      Response(string, int);
      string content();
      int code();
};