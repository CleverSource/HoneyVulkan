#include <core/logger.h>
#include <core/asserts.h>

// TODO: Test
#include <platform/platform.h>

int main(void) {
    HFATAL("A test message: %f", 3.14f);
    HERROR("A test message: %f", 3.14f);
    HWARN("A test message: %f", 3.14f);
    HINFO("A test message: %f", 3.14f);
    HDEBUG("A test message: %f", 3.14f);
    HTRACE("A test message: %f", 3.14f);

    platform_state state;
    if (platform_startup(&state, "Honey Engine Testbed", 100, 100, 1280, 720)) {
        while (TRUE) {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}