#define main b2_public_main
#include "../src/main/A1_b2.cpp"
#undef main
void verify(std::vector<int> data,int low,int high,const std::vector<int>& expected) {
 const auto original=data;
 const auto k=compact(data.data(),data.size(),low,high);
 CHECK(k==expected.size() && std::equal(expected.begin(),expected.end(),data.begin()));
 if(low>high) CHECK(data==original);
}
int main() {
 CHECK(compact(nullptr,0,0,1)==0);
 verify({3,1,3,2,3},2,3,{3,3,2,3});
 verify({1,2},5,3,{});
 verify({1,1,1},1,1,{1,1,1});
 verify({-1,2,0,9},0,2,{2,0});
 verify({1,2},3,4,{});
 verify({2,1},0,3,{2,1});
 verify({std::numeric_limits<int>::min(),0,std::numeric_limits<int>::max()},std::numeric_limits<int>::min(),std::numeric_limits<int>::max(),{std::numeric_limits<int>::min(),0,std::numeric_limits<int>::max()});
 verify(std::vector<int>(200000,7),7,7,std::vector<int>(200000,7));
 std::cout << "B2 boundaries 9/9\n";
}
