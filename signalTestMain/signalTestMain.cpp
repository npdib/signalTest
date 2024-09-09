// signalTestMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Signal.h"
#include "SignalMain.h"

int main()
{
    npdib::Signal<int, std::string> test;

    test.connect([](int foo, std::string bar) { std::cout << "int:\t" << foo << "\t\tstring:\t" << bar << "\n"; });
    test.connect([](int foo, std::string bar) { std::cout << "this is a second function which took " << foo * 2 << " / 2 and " << bar << "\n"; });

    test.emit(6, "giraffe");
    test.run(4, "potato");


    npdib::SignalMain::get().run();
}