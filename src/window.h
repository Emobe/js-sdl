#include <napi.h>
#include <SDL2/SDL.h>

class SDLWindow : public Napi::ObjectWrap<SDLWindow> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    SDLWindow(const Napi::CallbackInfo &Info);
    ~SDLWindow();
  private:
    static Napi::FunctionReference constructor;
    double _value;
    Napi::Value createWindow(const Napi::CallbackInfo &info);
    Napi::Value GetWindowBrightness(const Napi::CallbackInfo &info);
    Napi::Value GetBrightness(const Napi::CallbackInfo &info);
    Napi::Value GetDisplayIndex(const Napi::CallbackInfo &info);
    Napi::Value GetDisplayMode(const Napi::CallbackInfo &info);
    Napi::Value GetFlags(const Napi::CallbackInfo &info);
    Napi::Value GetGammaRamp(const Napi::CallbackInfo &info);
    Napi::Value GetGrab(const Napi::CallbackInfo &info);
    Napi::Value GetWindowID(const Napi::CallbackInfo &info);
    Napi::Value GetMaximumSize(const Napi::CallbackInfo &info);
    Napi::Value GetMinimumSize(const Napi::CallbackInfo &info);
    Napi::Value GetPixelFormat(const Napi::CallbackInfo &info);
    Napi::Value GetPosition(const Napi::CallbackInfo &info);
    Napi::Value GetSize(const Napi::CallbackInfo &info);
    Napi::Value GetSurface(const Napi::CallbackInfo &info);
    Napi::Value GetTitle(const Napi::CallbackInfo &info);

    SDL_Window* window_;

};