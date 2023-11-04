#include <vector>
#include <iostream>
#include <numeric>

int main() {
    using namespace std;

    auto output = [](int item) { std::cout << item << ", "; };
    vector<int> v ={1, 2, 3,1,1,1,1,1,1,1,1,1,1,1,1,1};

    auto v2 = v;
    for(auto i=0; i<v2.size(); ++i){
        if(v2[i] ==1){
            v2.erase(v2.begin() +i);
        }
    }
    for_each(begin(v2), end(v2), output);



    return 0;

}