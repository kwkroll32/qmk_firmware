#ifndef CONFIG_SJB_H
#define CONFIG_SJB_H

#include "../../config.h"

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 3

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 10

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 20

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1000

#undef TAPPING_TERM
#define TAPPING_TERM 200

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#ifdef DEBUG_ENABLE 
#undef NO_PRINT
#undef NO_DEBUG
#endif

// #define USING_QK_FUNCTION

#endif
