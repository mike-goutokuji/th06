#pragma once
#include "GameErrorContext.hpp"
#include "ZunMath.hpp"
#include "ZunResult.hpp"
#include "inttypes.hpp"
#include <cstdarg>
#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define ARRAY_SIZE_SIGNED(x) ((i32)sizeof(x) / (i32)sizeof(x[0]))

#define ZUN_BIT(a) (1 << (a))
#define ZUN_MASK(a) (ZUN_BIT(a) - 1)
#define ZUN_RANGE(a, count) (ZUN_MASK((a) + (count)) & ~ZUN_MASK(a))
#define ZUN_CLEAR_BITS(a, keep_mask) (a & ~keep_mask)

#define IS_PRESSED(key) (g_CurFrameInput & (key))
#define WAS_PRESSED(key) (((g_CurFrameInput & (key)) != 0) && (g_CurFrameInput & (key)) != (g_LastFrameInput & (key)))
#define WAS_PRESSED_WEIRD(key)                                                                                         \
    (WAS_PRESSED(key) || (((g_CurFrameInput & (key)) != 0) && (g_IsEigthFrameOfHeldInput != 0)))

namespace th06
{
namespace utils
{
ZunResult CheckForRunningGameInstance(void);
static void DebugPrint(const char *fmt, ...)
{
#ifdef DEBUG
    char tmpBuffer[512];
    std::va_list args;

    va_start(args, fmt);
    vsprintf(tmpBuffer, fmt, args);
    va_end(args);

    printf("DEBUG: %s\n", tmpBuffer);
#endif
}

static void DebugPrint2(const char *fmt, ...)
{
#ifdef DEBUG
    char tmpBuffer[512];
    std::va_list args;

    va_start(args, fmt);
    vsprintf(tmpBuffer, fmt, args);
    va_end(args);

    printf("DEBUG2: %s\n", tmpBuffer);
#endif
}

f32 AddNormalizeAngle(f32 a, f32 b);
void Rotate(D3DXVECTOR3 *outVector, D3DXVECTOR3 *point, f32 angle);
}; // namespace utils
}; // namespace th06
