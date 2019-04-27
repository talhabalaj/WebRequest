#include <iostream>
#include "Request.h"

using namespace std;

// Helpers
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

Request::Request() : headers(), url("") {}
Request::Request(string u) : headers(), url(u) {}
Request::Request(string u, Headers h) : headers(h), url(u) {}

string Request::getUrl() {
    return url;
}

Headers Request::getHeaders() {
    return headers;
}

void Request::setHeader(Headers h) {
    headers = h;
}

void Request::setUrl(string url) {
    this->url = url;
}

void Request::print() {
    cout << "Url: " << url;
    cout << "\nHeaders: " << endl;
    headers.print();
}

Response Request::getResponse() {
    // Init the CURL object
    CURL * curl = curl_easy_init();
    CURLcode curlCode;
    string response;

    // Setting options
    curl_easy_setopt(curl, CURLOPT_URL, (char*)url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers.getCurlChunk());

    // Performing the request
    curlCode = curl_easy_perform(curl);

    if (curlCode != 0) {
        return Response("", curlCode);
    }

    curl_easy_cleanup(curl);

    return Response(response, curlCode);
}

