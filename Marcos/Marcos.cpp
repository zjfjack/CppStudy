#include <iostream>

#define WAIT std::cin.get()
#define OPEN_CURLY {

#ifdef _DEBUG // project properties -> C/C++ -> preprocessor -> preprocesser definition
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#define PR_DEBUG 1
#define PR_RELEASE 2

#if 0
#ifdef PR_DEBUG == 2
#define LOG2(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG2(x)
#endif
#endif

// Multi-line marco
#define FUNCTION int function() \
{\
    return 1;\
}

int main()
OPEN_CURLY
    LOG("Hello");
    LOG2("Hello");
    WAIT; // WAIT will be replaced to std::cin.get() before compiling
}