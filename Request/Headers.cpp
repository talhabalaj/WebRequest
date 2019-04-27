#include <iostream>
#include "Headers.h"

using namespace std;

Headers::Headers() : heads(nullptr)
{
    add("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    add("Accept-Language", "en-US,enq=0.5");
    add("Connection", "keep-alive");
    add("User-Agent", "Mozilla/5.0 (X11; Linux x86_64; rv:66.0) Gecko/20100101 Firefox/66.0");
}

Headers::Headers(const Headers & h) {
    struct curl_slist * tmp = h.heads;
    this->heads = nullptr;

    do
    {
        this->heads = curl_slist_append(this->heads, tmp->data);
    } while (tmp = tmp->next);
}

void Headers::add(string key, string value)
{
    heads = curl_slist_append(heads, (char *)(key + ":" + value).c_str());
}

void Headers::remove(string key)
{
    heads = curl_slist_append(heads, (char *)(key + ":").c_str());
}

Headers::~Headers() {
    curl_slist_free_all(heads);
}

void Headers::print() {
    struct curl_slist * tmp = heads;
    
    while(tmp = tmp->next) {
        cout << tmp->data << endl;
    }
} 

struct curl_slist * Headers::getCurlChunk() {
    return heads;
}
