#define main q8_public_main
#include "../src/main/A1_q8.cpp"
#undef main
void verify(const std::vector<Telemetry>& frames,int valid,int duplicate,int invalid,long long hp,const std::vector<int>& ids) {
 auto r=summarize(frames);
 CHECK(r.valid==valid && r.duplicate==duplicate && r.invalid==invalid && r.total_hp==hp && r.ids==ids);
 CHECK(r.valid+r.duplicate+r.invalid==static_cast<int>(frames.size()));
 CHECK(r.valid==static_cast<int>(r.ids.size()));
}
int main() {
 verify({},0,0,0,0,{});
 verify({{1,-1001},{1,30},{1,1001}},1,0,2,30,{1});
 verify({{0,-1000},{9999,1000},{0,100}},2,1,0,100,{0,9999});
 verify({{-1,0},{10000,0},{std::numeric_limits<int>::min(),0},{std::numeric_limits<int>::max(),0},{1,std::numeric_limits<int>::min()},{1,std::numeric_limits<int>::max()}},0,0,6,0,{});
 verify({{2,5},{1,9}},2,0,0,14,{1,2});
 verify({{1,20},{1,-1001},{1,99}},1,1,1,20,{1});
 verify({{1,30}},1,0,0,30,{1});
 std::vector<Telemetry> frames; std::vector<int> ids;
 for(int i=0;i<10000;++i) {frames.push_back({i,100}); ids.push_back(i);}
 frames.insert(frames.end(),10000,Telemetry{0,100});
 verify(frames,10000,10000,0,1000000,ids);
 std::cout << "Q8 boundaries 8/8\n";
}
