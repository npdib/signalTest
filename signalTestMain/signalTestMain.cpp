// signalTestMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Signal.h"
#include "SignalMain.h"

int main()
{
    npdib::Signal<int, std::string> test;
    npdib::Signal<bool, int> test2;

    test.connect([](int foo, std::string bar) { std::cout << "int:\t" << foo << "\t\tstring:\t" << bar << "\n"; });
    test.connect([](int foo, std::string bar) { std::cout << "this is a second function which took " << foo * 2 << " / 2 and " << bar << "\n"; });

    test2.connect([](bool even, int num)
        {
            if ((even && num % 2 == 0) || (!even && num % 2 == 1))
                std::cout << std::boolalpha << true << "\n";
            else
                std::cout << std::boolalpha << false << "\n";
        });

    test2.emit(true, 4);

    test2.run(false, 3);

    test2.emit(true, 3);
    test.emit(6, "giraffe");

    test.run(4, "potato");
    test2.run(false, 2);


    npdib::SignalMain::get().run();
}