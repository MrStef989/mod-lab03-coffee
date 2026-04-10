// Copyright 2026 MrStef989
#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    chosen = -1;
    state = STATES::OFF;
    menu = {"Tea", "Coffee", "Milk", "Cocoa", "Latte"};
    prices = {20, 50, 30, 40, 60};
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Automata is ON\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "Automata is OFF\n";
    }
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "Cash: " << cash << "\n";
    } else if (state == STATES::ACCEPT) {
        cash += amount;
        std::cout << "Cash: " << cash << "\n";
    }
}

void Automata::getMenu() {
    for (int i = 0; i < static_cast<int>(menu.size()); i++) {
        std::cout << i + 1 << ". "
                  << menu[i] << " - " << prices[i] << "\n";
    }
}

STATES Automata::getState() {
    return state;
}

bool Automata::choice(int item) {
    if (state != STATES::ACCEPT) return false;
    if (item < 0 || item >= static_cast<int>(menu.size())) return false;
    chosen = item;
    state = STATES::CHECK;
    return true;
}

bool Automata::check() {
    if (state != STATES::CHECK) return false;
    if (cash >= prices[chosen]) {
        state = STATES::COOK;
        return true;
    }
    std::cout << "Not enough cash\n";
    state = STATES::ACCEPT;
    return false;
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        std::cout << "Returning " << cash << "\n";
        cash = 0;
        chosen = -1;
        state = STATES::WAIT;
    }
}

void Automata::cook() {
    if (state == STATES::COOK) {
        std::cout << "Cooking " << menu[chosen] << "...\n";
        state = STATES::DONE;
    }
}

void Automata::finish() {
    if (state == STATES::DONE) {
        cash -= prices[chosen];
        if (cash > 0) {
            std::cout << "Change: " << cash << "\n";
        }
        cash = 0;
        chosen = -1;
        state = STATES::WAIT;
    }
}
