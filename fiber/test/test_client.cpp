
#include "fiber.hpp"
#include "socketstream.hpp"

void test_socketstream() {
    //fiber::tcpstream ts(fiber::tcpstream::conn | fiber::tcpstream::block, "127.0.0.1", 8888);
    fiber::tcpstream ts(fiber::tcpstream::conn | fiber::tcpstream::block, fiber::socketaddr("127.0.0.1", 8000));

    std::cout << "connect 127.0.0.1" << std::endl;

    while (ts.good()) {
        char msg[1024];

        ts.read(msg, sizeof(msg));

        ts.clear();

        std::cout << "recv: " << msg << std::endl;

        std::string str;
        std::cin >> str;

        ts.write(str.c_str(), str.length());
    }

}

int main(int /*argc*/, char* /*argv*/[]) {
    test_socketstream();

    return 0;
}
