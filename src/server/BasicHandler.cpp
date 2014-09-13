// The MIT License (MIT)
//
// Copyright (c) 2013-2014 Julio Delgado Mangas, julio.delgadomangas@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <BasicHandler.hpp>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>
#include <iostream>

server::BasicHandler::BasicHandler() : Poco::Net::HTTPRequestHandler() {}

server::BasicHandler::~BasicHandler() {}

void server::BasicHandler::handleRequest( Poco::Net::HTTPServerRequest & request,
					  Poco::Net::HTTPServerResponse & response) {
  std::cout << "Received Request!" << std::endl;

  response.setContentType("text/txt");
  response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
  std::ostream& os = response.send();
  os << "12345 this is all pretty weird" << std::endl;
}
