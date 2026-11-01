#define main q6_public_main
#include "../src/main/A1_q6.cpp"
#undef main
int main() {
 CHECK(select_target({},5)==-1);
 CHECK(select_target({{1,0,0,1,true}},-1)==-1);
 CHECK(select_target({{1,0,0,0,true},{2,0,0,-1,true},{3,0,0,1,false}},1)==-1);
 CHECK(select_target({{7,3,4,1,true},{2,0,0,2,true}},5)==7);
 CHECK(select_target({{7,3,4,1,true},{9,0,0,1,true}},5)==9);
 CHECK(select_target({{9,0,0,3,true},{1,0,0,3,true}},0)==1);
 CHECK(select_target({{1,0,0,3,true},{9,0,0,3,true}},0)==1);
 CHECK(select_target({{77,3,4,1,true}},5)==77);
 CHECK(select_target({{77,3,4,1,true}},4)==-1);
 CHECK(select_target({{1,1000000,1000000,1,true},{2,-1000000,0,2,true}},1000000)==2);
 const std::vector<Target> original={{4,0,0,1,true},{2,0,0,1,true}};
 CHECK(select_target(original,0)==2 && original[0].id==4);
 std::cout << "Q6 boundaries 11/11\n";
}
