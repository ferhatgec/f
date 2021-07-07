// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include "../include/f.hpp"

extern "C" {
    #include <unistd.h>
}

void F::run() noexcept {
    __time init; init.init();
    std::string data = std::string(std::getenv("USER"));
    std::string lang = std::string(std::getenv("LANG"));
    std::string disp = std::string(std::getenv("DISPLAY"));
    std::string term = std::string(std::getenv("TERM"));
    std::string desk = std::string(std::getenv("DESKTOP_SESSION"));
    std::string tty  = std::string(ttyname(STDIN_FILENO));

    if(data.length() != 0) {
        std::cout << "\x1b[1;94m" + data + "\x1b[0m";
    }

    if(tty.length() != 0) {
        std::cout << "\x1b[0;97m -> \x1b[1;91m:" << tty.back() << ' ';
    }

    if(disp.length() != 0) {
        std::cout << "\x1b[0;97md(\x1b[0;95m" + disp + "\x1b[0;97m)" << ' ';
    }


    if(lang.length() == 0) {
        lang = std::string(std::getenv("LANGUAGE"));
    } std::cout << "l(\x1b[1;97m" + lang + "\x1b[0;97m)" << ' ';

    std::cout << "u(" +
                 ((init.days   != 0) ? "\x1b[1;93m" + std::to_string(init.days   ) + "\x1b[0;97md\x1b[0;97m, " : "")
              << ((init.hours  != 0) ? "\x1b[1;94m" + std::to_string(init.hours  ) + "\x1b[0;97mh\x1b[0;97m, " : "")
              << ((init.minutes!= 0) ? "\x1b[1;95m" + std::to_string(init.minutes) + "\x1b[0;97mm"  : "")
              << "\x1b[0;97m)";

    if(term.length() != 0) {
        std::cout << ' ' << "\x1b[1;93m" + term + "\x1b[0;97m" << ' ';
    }

    if(desk.length() != 0) {
        std::cout << ' ' << "d(\x1b[1;90m" + desk + "\x1b[0;97m)" << '\n';
    }
}

int main() noexcept {
    F init;
    init.run();
}