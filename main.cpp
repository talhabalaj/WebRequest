#include <iostream>
#include "Request/Request.h"
using namespace std;

int main(int argc, char **argv)
{
  string url;

  if (argc < 2)
    url = "google.com";
  else
    url = argv[1];

  Request req(url);
  Response res = req.getResponse();
  cout << res.content();
  cout << res.code();
  return 0;
}