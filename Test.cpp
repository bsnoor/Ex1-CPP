//
// Created by abdms on 08/03/2021.
//

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE("Good snowman code") {
            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); // straw hat
            CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )")); // mexican hat
            CHECK(nospaces(snowman(31114411)) == nospaces("___\n(_*_)\n(.,.)\n( : )\n( : )")); // Russian hat
            CHECK(nospaces(snowman(41114411)) == nospaces("_\n/_\\\n(.,.)\n( : )\n( : )")); // fez hat

            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); // normal
            CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )")); //dot
            CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )")); // line
            CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(..)\n( : )\n( : )")); // none

            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); // normal
            CHECK(nospaces(snowman(12214411)) == nospaces("_===_\n(o..)\n( : )\n( : )")); //bigger dot
            CHECK(nospaces(snowman(13314411)) == nospaces("_===_\n(O_.)\n( : )\n( : )")); // biggest dot
            CHECK(nospaces(snowman(14414411)) == nospaces("_===_\n(-.)\n( : )\n( : )")); // closed

            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); // normal
            CHECK(nospaces(snowman(12214411)) == nospaces("_===_\n(o.o)\n( : )\n( : )")); //bigger dot
            CHECK(nospaces(snowman(13314411)) == nospaces("_===_\n(O_O)\n( : )\n( : )")); // biggest dot
            CHECK(nospaces(snowman(14414411)) == nospaces("_===_\n(--)\n( : )\n( : )")); // closed

            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); // torso 1
            CHECK(nospaces(snowman(21114421)) == nospaces("___\n.....\n(.,.)\n(] [)\n( : )")); // torso 2 (vest)
            CHECK(nospaces(snowman(31114431)) == nospaces("___\n(_*_)\n(.,.)\n(> <)\n( : )")); // torso 3   (inward arms)
            CHECK(nospaces(snowman(41114441)) == nospaces("_\n/_\\\n(.,.)\n(  )\n( : )")); // torso 4   (none)

            CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )")); // buttons
            CHECK(nospaces(snowman(21114422)) == nospaces("___\n.....\n(.,.)\n(] [)\n(" ")")); // feet
            CHECK(nospaces(snowman(31114433)) == nospaces("___\n(_*_)\n(.,.)\n(> <)\n(___)")); // flat
            CHECK(nospaces(snowman(41114444)) == nospaces("_\n/_\\\n(.,.)\n(  )\n(  )")); // base 4   (none)
}
TEST_CASE("Bad snowman code regarding size of code") {
            CHECK_THROWS(snowman(555));
            CHECK_THROWS(snowman(55));
            CHECK_THROWS(snowman(5));
            CHECK_THROWS(snowman(5555));
            CHECK_THROWS(snowman(55555));
            CHECK_THROWS(snowman(5555555));
}
TEST_CASE("Bad snowman code regarding bad inappropriate digits") {
            CHECK_THROWS(snowman(11111115));
            CHECK_THROWS(snowman(11111151));
            CHECK_THROWS(snowman(11111511));
            CHECK_THROWS(snowman(11115111));
            CHECK_THROWS(snowman(11151111));
            CHECK_THROWS(snowman(11511111));
            CHECK_THROWS(snowman(15111111));
            CHECK_THROWS(snowman(51111111));
}
TEST_CASE("bad expected result") {
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( : )\n( : "));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( : )\n( :"));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( : )\n( "));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( : )\n("));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( : )"));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( : "));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( :"));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n( "));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n("));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,.)\n"));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,."));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n(.,"));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n("));
            CHECK(nospaces(snowman(11114411)) != nospaces("_===_\n"));
            CHECK(nospaces(snowman(11114411)) != nospaces("_==="));
            CHECK(nospaces(snowman(11114411)) != nospaces("_=="));
            CHECK(nospaces(snowman(11114411)) != nospaces("_="));
            CHECK(nospaces(snowman(11114411)) != nospaces("_"));
            CHECK(nospaces(snowman(11114411)) != nospaces(""));
}
