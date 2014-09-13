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

#include <PostRequestHandler.hpp>
#include <Poco/Net/HTTPServerRequest.h> 
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>
#include <iostream>

server::PostRequestHandler::PostRequestHandler() : Poco::Net::HTTPRequestHandler() {}

server::PostRequestHandler::~PostRequestHandler() {}

void server::PostRequestHandler::handleRequest( Poco::Net::HTTPServerRequest & request,
					  Poco::Net::HTTPServerResponse & response) {
  std::cout << "Post Request Received!" << std::endl;

  std::istream& in = request.stream();
  int size = request.getContentLength();
  char buffer[size + 1];
  in.read(buffer, size);
  buffer[size] = '\0';
  if (in)
    std::cout << "Size " << size << " " << buffer << std::endl;
  
  response.setContentType("text/txt");
  response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
  std::ostream& os = response.send();
  os << buffer << std::endl;
}
