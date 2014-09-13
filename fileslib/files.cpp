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

#include <files.hpp>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

namespace files {

  void printFile(std::string filePath) {
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return;

    char c = is.get();
    while(is.good()) {
      std::cout << c;
      c = is.get();
    }

    is.close();
  }

  int countLines(std::string filePath) {
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return 0;

    int linesCounter = 0;
    char c = is.get();
    while(is.good()) {
      linesCounter += (c == '\n') ? 1 : 0; 
      c = is.get();
    }

    is.close();
    
    return linesCounter + 1;
    
  }

  int countWords(std::string filePath) {
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return 0;

    int wordsCounter = 0;
    bool inWord = false;
    char c = is.get();
    while(is.good()) {
      if ((c == ' ' ||  c == '\t' || c =='\n')) {
	if(inWord) {
	  inWord = false;
	  ++wordsCounter;
	}
      } else {
	inWord = true;
      }
      c = is.get();
    }

    if(inWord)
      wordsCounter++;

    is.close();
    return wordsCounter;
  }

  void printUniqueWords(std::string filePath){
    std::ifstream is(filePath.c_str());
    if(!is.good())
      return;

    std::set<std::string> words;
    std::stringstream ss;
    bool inWord = false;
    char c = is.get();
    while(is.good()) {
      if ((c == ' ' ||  c == '\t' || c =='\n')) {
	if (inWord) {
	  words.insert(ss.str());
	  ss.clear();
	  ss.str(std::string());
	  inWord = false;
	}
      } else {
	ss << c;
	inWord = true;
      }
      c = is.get();
    }

    if(inWord) {
      words.insert(ss.str());
    }

    is.close();
    
    for(std::set<std::string>::iterator it = words.begin() ; it != words.end() ; ++it) {
      std::cout << *it << std::endl;
    }
  }

} 
