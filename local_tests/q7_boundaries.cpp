#define main q7_public_main
#include "../src/main/A1_q7.cpp"
#undef main
void verify(int ammo,int heat,int cool,int shotHeat,const std::vector<int>& requests,FireResult e) {
 auto r=simulate(ammo,heat,cool,shotHeat,requests);
 CHECK(r.shots==e.shots && r.rejected==e.rejected && r.ammo==e.ammo && r.heat==e.heat);
 CHECK(r.shots+r.rejected==std::count(requests.begin(),requests.end(),1));
}
int main() {
 verify(4,80,10,30,{}, {0,0,4,80});
 verify(0,50,10,20,{1}, {0,1,0,40});
 verify(1,100,0,0,{1}, {1,0,0,100});
 verify(1,100,0,1,{1}, {0,1,1,100});
 verify(2,90,10,20,{1,1,1}, {2,1,0,100});
 verify(3,100,20,10,{0}, {0,0,3,80});
 verify(1,1,100,100,{1,0}, {1,0,0,0});
 verify(1,0,0,0,{1,1,0}, {1,1,0,0});
 verify(100,0,0,0,std::vector<int>(10000,1), {100,9900,0,0});
 std::cout << "Q7 boundaries 9/9\n";
}
