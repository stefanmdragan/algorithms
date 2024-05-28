// see https://youtu.be/LrHNXoqQ_lI

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


// computes 2^x
size_t pow2x(size_t x) {
    return 1 << x;
}

int charToDigit(char c) {
    return c - '0';
}

string fromBase10ToBase20(string b10) {
    size_t len = b10.length();
    if (len == 0) {
        return {};
    }
    
    stringstream ss;
    size_t high = 0;
    for (const char &c : b10) {
        len--;
        
        const int d10 = charToDigit(c);
        if (d10 < 0) {
            break;
        }
        high = 10 * high + d10;
        const size_t p2 = pow2x(len);
        const size_t d20 = high / p2;
        high %= p2;
        
        // don't add '0' at the front of the number
        if (d20 != 0 || ss.tellp() > 0) {
            ss << d20 << ',';
        }
    }
    
    string result = ss.str();
    result.pop_back();  // remote last ',''
    return result;
}

int main() {
    const vector<pair<string, string>> arrTest{
        {"4896", "12,4,16"},
        {"9662", "1,4,3,2"},
        {"84185", "10,10,9,5"},
    };
    
    for (const auto &p : arrTest) {
        const auto result = fromBase10ToBase20(p.first);
        cout << "base10(" << p.first << ") = base20(" << result << ") "
             << (result == p.second ? "[OK]" : "[ERROR]") << endl;
    }
}
