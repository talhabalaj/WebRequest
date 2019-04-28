# WebRequest
A C++ libCurl Wrapper for performing web request efficiently

```cpp
#include <iostream>
#include "Request/Request.h"
using namespace std;

int main() {
  Request req("httpbin.org/get");
  Response res = req.getResponse();
  cout << res.content();
  cout << res.code();
  return 0;
}
```
