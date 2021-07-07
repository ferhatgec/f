// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef F_F_HPP
#define F_F_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

class __time {
public:
    unsigned days, hours, minutes;
public:
    __time() = default;
    ~__time()= default;

    void init() noexcept {
        if(std::filesystem::exists("/proc/uptime")) {
            std::ifstream file("/proc/uptime");
            unsigned s = 0;

            for(std::string line; std::getline(file, line); s = std::stoi(line))
                ; file.close();

            this->days   = ((s / 60 / 60 / 24) ^ 0) ? (s / 60 / 60 / 24) : 0;
            this->hours  = ((s / 60 / 60 % 24) ^ 0) ? (s / 60 / 60 % 24) : 0;
            this->minutes= ((s / 60      % 60) ^ 0) ? (s / 60      % 24) : 0;
        }
    }
};

class F {
public:
    F() = default;
    ~F()= default;

    void run() noexcept;
};

#endif // F_F_HPP
