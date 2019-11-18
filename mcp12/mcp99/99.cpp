/*
 * 99.cpp
 *
 *  Created on: 2019/11/18
 *      Author: hhhhh
 */


#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

pplx::task<void> Get(std::string text, std::string language)
{
  return pplx::create_task([]
  {
    http_client client(L"https://api.cognitive.microsofttranslator.com");
    uri_builder builder(U("/translate"));

    builder.append_query(U("to"), U("api-version%3D3.0"));
    builder.append_query(U("ocp-apim-subscription-key"), U("8ff75fc7-ff8b-4abb-8b09-c2dca0a8418d"));
    builder.append_query(U("Text"), text);

    return client.request(methods::GET);
  }).then([](http_response response)
  {
    if (response.status_code() == status_codes::OK)
    {
      return response.extract_json();
    }
  }).then([](json::value json)
  {
    std::wcout << json[L"translations"].as_string() << std::endl;
  });
}

int main(int argc, char **argv) {
	Get("start","fr");
	Get("hellow world","fr");
	Get("end","fr");

	Get("start","jp");
	Get("hellow world","jp");
	Get("end","jp");
}

