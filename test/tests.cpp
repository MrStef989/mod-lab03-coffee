// Copyright 2026 MrStef989
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, TurnOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TurnOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinChangesState) {
    Automata a;
    a.on();
    a.coin(10);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, CoinAccumulatesCash) {
    Automata a;
    a.on();
    a.coin(20);
    a.coin(30);
    EXPECT_EQ(a.cash, 50);
}

TEST(AutomataTest, ChoiceValid) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_TRUE(a.choice(0));
}

TEST(AutomataTest, ChoiceInvalid) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_FALSE(a.choice(99));
}

TEST(AutomataTest, CheckSuccess) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    EXPECT_TRUE(a.check());
    EXPECT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, CheckFail) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1);
    EXPECT_FALSE(a.check());
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, CookChangesState) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), STATES::DONE);
}

TEST(AutomataTest, FinishResetsState) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.check();
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, CancelReturnsToWait) {
    Automata a;
    a.on();
    a.coin(20);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    EXPECT_EQ(a.cash, 0);
}
