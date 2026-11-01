#define main q6_public_main
#include "../src/main/A1_q6.cpp"
#undef main
int main() {
    const std::vector<Target> candidates = {
        {10,3,4,2,true}, {20,0,1,2,true}, {5,0,-1,2,true},
        {1,0,0,1,false}, {2,0,0,0,true}, {3,6,0,1,true}
    };
    std::vector<int> order = {0,1,2,3,4,5};
    int cases = 0;
    do {
        std::vector<Target> targets;
        for (int index : order) targets.push_back(candidates[index]);
        CHECK(select_target(targets,5)==5);
        CHECK(select_target(targets,6)==3);
        CHECK(select_target(targets,0)==-1);
        for (std::size_t i=0;i<order.size();++i) CHECK(targets[i].id==candidates[order[i]].id);
        cases += 3;
    } while (std::next_permutation(order.begin(),order.end()));
    std::cout << "Q6 permutation cases: " << cases << '\n';
}
