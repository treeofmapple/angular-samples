#include "drogon/HttpAppFramework.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  drogon::app().addListener("0.0.0.0", 8000).run();
  std::cout << "API Server on http://localhost:8000" << std::endl;
  return 0;
}
