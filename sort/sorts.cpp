#include "sorts.h"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex cout_mutex;

void merge(vector& v, size_t left, size_t mid, size_t right)
{
    size_t i = 0, j = 0, k = left;
    vector lv(v.begin() + left, v.begin() + mid + 1);
    vector rv(v.begin() + mid + 1, v.begin() + right + 1);

    while (i < lv.size() && j < rv.size())
    {
        if (lv[i] <= rv[j])
            v[k++] = lv[i++];
        else
            v[k++] = rv[j++];
    }
    while (i < lv.size())
        v[k++] = lv[i++];
    while (j < rv.size())
        v[k++] = rv[j++];
}

void merge_sort(vector& v, size_t left, size_t right, size_t depth)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (depth < 3) 
        {
            std::thread t1(merge_sort, std::ref(v), left, mid, depth + 1);
            std::thread t2(merge_sort, std::ref(v), mid + 1, right, depth + 1);
            t1.join();
            t2.join();
        }
        else
        {
            merge_sort(v, left, mid, depth + 1);
            merge_sort(v, mid + 1, right, depth + 1);
        }
        merge(v, left, mid, right);
    }
}

vector fast_sort(const vector &v)
{
    if(v.size() <= 1)
        return v;

    vector lv, rv; // left vector, right vector
    size_t pivot = (v.size() - 1) / 2;
    
    for(size_t i = 0; i < v.size(); ++i)
    {
        if (i == pivot)
            continue;
        
        if (v[i] >= v[pivot])
            rv.push_back(v[i]);
        else
            lv.push_back(v[i]);
    }   

    lv = fast_sort(lv);
    rv = fast_sort(rv);

    lv.push_back(v[pivot]);
    lv.insert(lv.end(), rv.begin(), rv.end());
    
    return lv;
}

vector bubble_sort(const vector& v)
{
    vector res = v;
    for (size_t i = 0; i < res.size(); ++i)
    {
        for (size_t j = 0; j < res.size() - i - 1; ++j)
        {
            if (res[j] > res[j + 1])
                std::swap(res[j], res[j + 1]);	
        }
    }
    return res;
}

void print_result(const std::string& sort_name, const vector& vec)
{
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << sort_name << " result: ";
    for (const auto& num : vec)
        std::cout << num << " ";
    std::cout << std::endl;
}
