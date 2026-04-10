// Copyright 2026 MrStef989
#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
    DONE
};

class Automata {
 public:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int chosen;

    Automata();
    void on();
    void off();
    void coin(int amount);
    void getMenu();
    STATES getState();
    bool choice(int item);
    bool check();
    void cancel();
    void cook();
    void finish();
};
