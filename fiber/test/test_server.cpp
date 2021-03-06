
#include "fiber.hpp"
#include "socketstream.hpp"

void test_socketstream() {
    fiber::tcpacceptor ta(8888);
    std::cout << "listen fd:" << ta.socket()->native_handle() << std::endl;

    while (true) {
        fiber::socketaddr addr;
        fiber::tcpstream ts = ta.accept(addr);

        std::cout << addr << std::endl;

        std::cout << "accept fd:" << ts.socket()->native_handle() << std::endl;

        while (ts.good()) {
            std::string str = "hello";
            ts.write(str.c_str(), str.length());

            std::cout << "send: " << str << std::endl; 

            //ss << "hello\n" << std::flush;
            //std::string msg;
            //ss >> msg;
            
            char msg[1024];
            ts.read(msg, sizeof(msg));
            ts.clear();

            std::cout << "recv: " << msg << std::endl;

        }
    }
}

int main(int /*argc*/, char* /*argv*/[]) {
    test_socketstream();

    return 0;
}
