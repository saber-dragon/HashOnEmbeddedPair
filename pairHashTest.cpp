#include <iostream>
#include<gtest/gtest.h>

#include "pairHash.hpp"
using namespace std;

TEST(HashOnEmbeddedPairTest, SimplePair){
    auto p = make_pair(10, 20);
    unordered_map<pair<int, int>, bool, PairHash> mapOfSimplePair;
    mapOfSimplePair.insert({p, true});
    EXPECT_TRUE(mapOfSimplePair[p]);
}

TEST(HashOnEmbeddedPairTest, EmbeddedPairCase01){
    auto p = make_pair(make_pair(10, 20), "100");
    unordered_map<pair<pair<int, int>, string>, bool, PairHash> mapOfEmbeddedPair;
    mapOfEmbeddedPair.insert({p, false});
    EXPECT_FALSE(mapOfEmbeddedPair.at(p));
}

TEST(HashOnEmbeddedPairTest, EmbeddedPairCase02){
    auto p = make_pair("100", make_pair(10, 20));
    unordered_map<pair<string, pair<int, int>>, bool, PairHash> mapOfEmbeddedPair;
    mapOfEmbeddedPair.insert({p, false});
    EXPECT_FALSE(mapOfEmbeddedPair.at(p));
}

TEST(HashOnEmbeddedPairTest, EmbeddedPairCase03){
    auto p = make_pair(make_pair(10, "100"), make_pair(10, 20));
    unordered_map<pair<pair<int, string>, pair<int, int>>, bool, PairHash> mapOfEmbeddedPair;
    mapOfEmbeddedPair.insert({p, false});
    EXPECT_FALSE(mapOfEmbeddedPair.at(p));
}

TEST(HashOnEmbeddedPairTest, ComplexEmbedded){
    auto p = make_pair(make_pair(make_pair(10, "100"), make_pair(10, 20)), 10);
    unordered_map<pair<pair<pair<int, string>, pair<int, int>>, int>, bool, PairHash> mapOfEmbeddedPair;
    mapOfEmbeddedPair.insert({p, false});
    EXPECT_FALSE(mapOfEmbeddedPair.at(p));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
