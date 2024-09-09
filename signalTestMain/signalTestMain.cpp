// signalTestMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Signal.h"
#include "SignalMain.h"

int main()
{
    Signal<int> test;

    test.call();

    test.emit();

    SignalMain::get().run();
}