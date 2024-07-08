#include <limits>   // Needed for std::numeric_limits

int main(){
    for(unsigned long long i = 0; i < std::numeric_limits<unsigned long long>::max(); ++i){
        // loop body
    }
}
