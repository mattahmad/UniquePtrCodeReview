#include <iostream>
#include <vector>

template <typename T>
class Unique_Ptr
{
private:
    T *ptr;
    
public:
    explicit Unique_Ptr(T *p) noexcept : ptr{p} {}
    ~Unique_Ptr() { delete ptr; };
    T *operator->() const noexcept { return ptr; }
    inline T operator*() const { return *ptr; }
    inline T *get() const noexcept { return ptr; }
    T *release() noexcept
    {
        auto tmp = ptr;
        ptr = nullptr;
        return tmp;
    }
};

int main(int argc, const char * argv[]) {
    Unique_Ptr p{new int{2}};
    std::cout << *p << "\n";
    
    Unique_Ptr pp{new std::vector<int>{1, 2, 3}};
    std::cout << pp->size() << "\n";
    
    auto test_release = pp.release();
    std::cout << (pp.get() == nullptr) << "\n";
    std::cout << test_release->size() << "\n";
    
    return 0;
}



//Implement a simple unique_ptr supporting only a constructor, destructor,->, * and release(). In //particular, don't try to implement an assignment or a copy constructor
