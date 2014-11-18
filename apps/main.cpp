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

#include <Poco/Net/HTTPServer.h>
#include <HandlerFactory.hpp>
#include <BasicHandler.hpp>

#include <Poco/ThreadPool.h>

#include <iostream>
#include <string>

using namespace Poco::Net;

int main(int argc, char** argv) {
  // Need Handler Factory
  HTTPRequestHandlerFactory::Ptr factory(new server::HandlerFactory());

  // Net ServerSocket
  ServerSocket ss(8080);

  // Need a ThreadPool
  Poco::ThreadPool pool;

  // Need HTTPServerParams::Ptr
  HTTPServerParams::Ptr pParams(new HTTPServerParams());
  HTTPServer server(factory, pool,  ss, pParams);
  server.start();

  std::string s;
  std::cin >> s;
  
  server.stop();
}
