#include "sorts.h"
#include <thread>

int main()
{
    vector v = {11, 12, 1, 4, 5, 6, 3};

    std::thread t1([v]()
    { 
        vector fast_v = fast_sort(v);
        print_result("fast sort", fast_v);
    });

    std::thread t2([v]()
    {
        vector bub_v = bubble_sort(v);
        print_result("bubble sort", bub_v);
    });

    std::thread t3([v]()
    {
        vector merge_v = v;  
        merge_sort(merge_v, 0, merge_v.size() - 1);
        print_result("merge sort", merge_v);
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
