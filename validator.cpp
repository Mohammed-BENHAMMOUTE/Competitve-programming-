#include "testlib.h"
#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    
    std::string s = inf.readToken("[a-z]{" + std::to_string(n) + "}", "s");
    inf.readEoln();
    
    inf.readEof();
    return 0;
}