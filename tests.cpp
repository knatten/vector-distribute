#include "distribute.h"
#include "catch.hpp"

#include <exception>

using namespace std;
using knatten::distribute;

TEST_CASE("distribute in one") {
    vector<int> v{1,2,3};
    auto vs = distribute(v, 1);
    REQUIRE(vs.size() == 1);
    REQUIRE(vs[0] == vector<int> {1, 2, 3});
}

TEST_CASE("distribute equally") {
    vector<int> v{1,2,3,4};
    auto vs = distribute(v, 2);
    REQUIRE(vs.size() == 2);
    REQUIRE(vs[0] == vector<int> {1, 2});
    REQUIRE(vs[1] == vector<int> {3, 4});
}

TEST_CASE("distribute unequally") {
    vector<int> v{1,2,3,4,5};
    auto vs = distribute(v, 2);
    REQUIRE(vs.size() == 2);
    REQUIRE(vs[0] == vector<int> {1, 2, 3});
    REQUIRE(vs[1] == vector<int> {4, 5});
}

TEST_CASE("distribute N elements into >N vectors") {
    vector<int> v{1,2};
    auto vs = distribute(v, 4);
    REQUIRE(vs.size() == 4);
    REQUIRE(vs[0] == vector<int>{1});
    REQUIRE(vs[1] == vector<int>{2});
    REQUIRE(vs[2] == vector<int>());
    REQUIRE(vs[3] == vector<int>());
}

TEST_CASE("distribute 0 elements") {
    vector<int> v;
    auto vs = distribute(v, 2);
    REQUIRE(vs.size() == 2);
    REQUIRE(vs[0] == vector<int>());
    REQUIRE(vs[1] == vector<int>());
}

TEST_CASE("distribute into 0 vectors") {
    REQUIRE_THROWS_AS(distribute(vector<int>(), 0), std::invalid_argument);
}
