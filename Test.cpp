#include "doctest.h"
#include "mat.hpp"

#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;

string nospaces(string input) {
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}

TEST_CASE("Good Input")
{
CHECK(nospaces(mat(10, 7, '@', '-')) == nospaces("@@@@@@@@@@\n@--------@\n@-@@@@@@-@\n@-@----@-@\n@-@@@@@@-@\n@--------@\n@@@@@@@@@@"));


 CHECK(nospaces(mat(10, 7, '@', ')')) == nospaces("@@@@@@@@@@\n@))))))))@\n@)@@@@@@)@\n@)@))))@)@\n@)@@@@@@)@\n@))))))))@\n@@@@@@@@@@"));

 
 CHECK(nospaces(mat(12, 5, '@', '-')) == nospaces("@@@@@@@@@@@@\n@----------@\n@-@@@@@@@@-@\n@----------@\n@@@@@@@@@@@@"));


 CHECK(nospaces(mat(15, 5, '@', '^')) == nospaces("@@@@@@@@@@@@@@@\n@^^^^^^^^^^^^^@\n@^@@@@@@@@@@@^@\n@^^^^^^^^^^^^^@\n@@@@@@@@@@@@@@@"));


 CHECK(nospaces(mat(3, 5, '5', '%')) == nospaces("555\n5%5\n5%5\n5%5\n5%5"));

    
    CHECK(nospaces(mat(3, 5, '#', ')')) == nospaces("###\n#)#\n#)#\n#)#\n###"));


    CHECK(nospaces(mat(1, 0, '*', '(')) == nospaces("*"));

    CHECK(nospaces(mat(1, 0, '&', '-')) == nospaces("&"));

    CHECK(nospaces(mat(1, 0, '%', ' ')) == nospaces("%"));	
}

TEST_CASE("Bad Input")
{
    CHECK_THROWS(mat(1, 5, '$', '%'));
    CHECK_THROWS(mat(2, 5, '$', '-'));
    CHECK_THROWS(mat(3, 5, '@', '+'));
    CHECK_THROWS(mat(4, 5, '#', '^'));
    CHECK_THROWS(mat(5 , 4, '$', '%'));
    CHECK_THROWS(mat(6, 0, '$', '%'));
    CHECK_THROWS(mat(7, 0, '$', '%'));
    CHECK_THROWS(mat(8, -2, '$', '%'));
    CHECK_THROWS(mat(-1, -3, '$', '%'));
    CHECK_THROWS(mat(-3, -5, '$', '%'));
    CHECK_THROWS(mat(-0, -4, '$', '%'));
}