#include "Response.h"


Response::Response(string resp, int code) {
    this->responseString = resp;
    this->statusCode = code;
}

string Response::content() {
    return responseString;
}

int Response::code() {
    return statusCode;
}