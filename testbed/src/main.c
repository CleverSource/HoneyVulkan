#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    HFATAL("A test message: %f", 3.14f);
    HERROR("A test message: %f", 3.14f);
    HWARN("A test message: %f", 3.14f);
    HINFO("A test message: %f", 3.14f);
    HDEBUG("A test message: %f", 3.14f);
    HTRACE("A test message: %f", 3.14f);

    HASSERT(1 == 0);

    return 0;
}