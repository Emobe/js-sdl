#include <napi.h>
#include <SDL2/SDL.h>
#include "node_sdl.h"
#include "window.h"

Napi::FunctionReference sdl::Node_SDL::constructor;

Napi::Object sdl::Node_SDL::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env,
                  "init",
                  {InstanceMethod("init", &sdl::Node_SDL::init),
                  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Node_SDL", func);
  return exports;
};

sdl::Node_SDL::Node_SDL(const Napi::CallbackInfo &info) : Napi::ObjectWrap<sdl::Node_SDL>(info) {
    Napi::Env env = info.Env();
};

sdl::Node_SDL::~Node_SDL(){
    SDL_Quit();
}

Napi::Value sdl::Node_SDL::init(const Napi::CallbackInfo &info){
    Napi::Env env = info.Env();
    return Napi::Number::New(env, SDL_Init(SDL_INIT_VIDEO));
};

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    sdl::Node_SDL::Init(env, exports);
    sdl::WindowWrap::Init(env, exports);


    exports.Set("SDL_WINDOW_FULLSCREEN", Napi::Number::New(env, SDL_WINDOW_FULLSCREEN));
    exports.Set("SDL_WINDOW_OPENGL", Napi::Number::New(env, SDL_WINDOW_OPENGL));
    exports.Set("SDL_WINDOW_SHOWN", Napi::Number::New(env, SDL_WINDOW_SHOWN));
    exports.Set("SDL_WINDOW_HIDDEN", Napi::Number::New(env, SDL_WINDOW_HIDDEN));
    exports.Set("SDL_WINDOW_BORDERLESS", Napi::Number::New(env, SDL_WINDOW_BORDERLESS));
    exports.Set("SDL_WINDOW_RESIZABLE", Napi::Number::New(env, SDL_WINDOW_RESIZABLE));
    exports.Set("SDL_WINDOW_MAXIMIZED", Napi::Number::New(env, SDL_WINDOW_MAXIMIZED));
    exports.Set("SDL_WINDOW_INPUT_GRABBED", Napi::Number::New(env, SDL_WINDOW_INPUT_GRABBED));
    exports.Set("SDL_WINDOW_INPUT_FOCUS", Napi::Number::New(env, SDL_WINDOW_INPUT_FOCUS));
    exports.Set("SDL_WINDOW_MOUSE_FOCUS", Napi::Number::New(env, SDL_WINDOW_MOUSE_FOCUS));
    exports.Set("SDL_WINDOW_FULLSCREEN_DESKTOP", Napi::Number::New(env, SDL_WINDOW_FULLSCREEN_DESKTOP));
    exports.Set("SDL_WINDOW_FOREIGN", Napi::Number::New(env, SDL_WINDOW_FOREIGN));
    exports.Set("SDL_WINDOW_ALLOW_HIGHDPI", Napi::Number::New(env, SDL_WINDOW_ALLOW_HIGHDPI));
    exports.Set("SDL_WINDOW_MOUSE_CAPTURE", Napi::Number::New(env, SDL_WINDOW_MOUSE_CAPTURE));
    exports.Set("SDL_WINDOW_ALWAYS_ON_TOP", Napi::Number::New(env, SDL_WINDOW_ALWAYS_ON_TOP));
    exports.Set("SDL_WINDOW_SKIP_TASKBAR", Napi::Number::New(env, SDL_WINDOW_SKIP_TASKBAR));
    exports.Set("SDL_WINDOW_UTILITY", Napi::Number::New(env, SDL_WINDOW_UTILITY));
    exports.Set("SDL_WINDOW_TOOLTIP", Napi::Number::New(env, SDL_WINDOW_TOOLTIP));
    exports.Set("SDL_WINDOW_POPUP_MENU", Napi::Number::New(env, SDL_WINDOW_POPUP_MENU));
    exports.Set("SDL_WINDOW_VULKAN", Napi::Number::New(env, SDL_WINDOW_VULKAN));

    exports.Set("SDL_WINDOWPOS_UNDEFINED_MASK", Napi::Number::New(env, SDL_WINDOWPOS_UNDEFINED_MASK));
    exports.Set("SDL_WINDOWPOS_CENTERED", Napi::Number::New(env, SDL_WINDOWPOS_CENTERED));



    return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)