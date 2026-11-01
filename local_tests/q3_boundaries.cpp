#define main q3_public_main
#include "../src/main/A1_q3.cpp"
#undef main
int main() {
 CHECK(alarms({2,2},2,4).empty());
 CHECK((alarms({-4,-3,-2},2,-6)==std::vector<int>{2}));
 CHECK(alarms({1},0,0).empty());
 CHECK(alarms({1},-1,0).empty());
 CHECK(alarms({1},2,0).empty());
 CHECK(alarms({},1,0).empty());
 CHECK((alarms({1,2},1,1)==std::vector<int>{1}));
 CHECK((alarms({1000000000,1000000000,1000000000},3,2999999999LL)==std::vector<int>{2}));
 CHECK((alarms({5,-10,6},2,-5)==std::vector<int>{2}));
 std::vector<int> large(200000,1000000000);
 CHECK((alarms(large,200000,199999999999999LL)==std::vector<int>{199999}));
 CHECK(large.front()==1000000000);
 std::cout << "Q3 boundaries 11/11\n";
}
