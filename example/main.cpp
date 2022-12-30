#include <Windows.h>
#include <iostream>
#include <jsapi.h>
#include <jsfriendapi.h>

#if 0
BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
  switch (dwReason) {
    case DLL_PROCESS_ATTACH: {
      auto rt = JS_NewRuntime(50 * (1024 * 1024), JS_USE_HELPER_THREADS);
      auto cx = JS_NewContext(rt, static_cast<size_t>(50 * 1024));

      JS_DestroyContext(cx);
      JS_DestroyRuntime(rt);
      JS_ShutDown();
    } break;
  }
  return TRUE;
}
#endif

int main() {
  auto rt = JS_NewRuntime(50 * (1024 * 1024), JS_USE_HELPER_THREADS);
  auto cx = JS_NewContext(rt, static_cast<size_t>(50 * 1024));

  JS_DestroyContext(cx);
  JS_DestroyRuntime(rt);
  JS_ShutDown();
  return 0;
}
