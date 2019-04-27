#include <iostream>
#include "Request.h"
using namespace std;

int main() {
  Request req(".com");
  Response res = req.getResponse();
  cout << res.content();
  cout << res.code();
  return 0;
}