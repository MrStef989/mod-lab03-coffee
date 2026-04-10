// Copyright 2026 MrStef989
#include <iostream>
#include "Automata.h"

int main() {
    Automata a;
    a.on();
    a.getMenu();
    a.coin(30);
    a.coin(30);
    a.choice(0);
    if (a.check()) {
        a.cook();
        a.finish();
    }
    a.coin(50);
    a.choice(1);
    if (a.check()) {
        a.cook();
        a.finish();
    }
    a.coin(10);
    a.choice(1);
    a.check();
    a.cancel();
    a.off();
    return 0;
}
