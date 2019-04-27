#include <iostream>
#include "Request/Request.h"
using namespace std;

int main() {
  Request req("google.com");
  Response res = req.getResponse();
  cout << res.content();
  cout << res.code();
  return 0;
}