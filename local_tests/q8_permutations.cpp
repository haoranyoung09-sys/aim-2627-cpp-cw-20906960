#define main q8_public_main
#include "../src/main/A1_q8.cpp"
#undef main
#include <map>

int main() {
    const std::vector<Telemetry> source = {
        {1,-1001}, {1,20}, {1,80}, {1,1001}, {2,-5}, {-1,30}, {9999,1000}
    };
    std::vector<int> order={0,1,2,3,4,5,6};
    int cases=0;
    do {
        std::vector<Telemetry> frames;
        std::map<int,int> first;
        int invalid=0, duplicate=0;
        for (int index:order) {
            const auto frame=source[index];
            frames.push_back(frame);
            if (frame.id<0 || frame.id>9999 || frame.hp < -1000 || frame.hp>1000) ++invalid;
            else if (!first.emplace(frame.id,frame.hp).second) ++duplicate;
        }
        long long total=0;
        std::vector<int> ids;
        for (const auto& item:first) {
            ids.push_back(item.first);
            total+=item.second<0 ? 0 : item.second>100 ? 100 : item.second;
        }
        const auto result=summarize(frames);
        CHECK(result.ids==ids && result.total_hp==total);
        CHECK(result.invalid==invalid && result.duplicate==duplicate);
        CHECK(result.valid==static_cast<int>(first.size()));
        CHECK(result.valid+result.duplicate+result.invalid==static_cast<int>(frames.size()));
        for(std::size_t i=0;i<frames.size();++i) {
            CHECK(frames[i].id==source[order[i]].id && frames[i].hp==source[order[i]].hp);
        }
        CHECK(summarize({}).ids.empty());
        ++cases;
    } while(std::next_permutation(order.begin(),order.end()));
    std::cout << "Q8 classification permutations: " << cases << '\n';
}
