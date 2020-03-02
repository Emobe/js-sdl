#include <napi.h>
#include <SDL2/SDL.h>
#include "node_sdl.h"
#include "window.h"

Napi::FunctionReference Node_SDL::constructor;

Napi::Object Node_SDL::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env,
                  "init",
                  {InstanceMethod("init", &Node_SDL::init),
                  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Node_SDL", func);
  return exports;
};

Node_SDL::Node_SDL(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Node_SDL>(info) {
    Napi::Env env = info.Env();
};

Napi::Value Node_SDL::init(const Napi::CallbackInfo &info){
    Napi::Env env = info.Env();
    return Napi::Number::New(env, SDL_Init(SDL_INIT_VIDEO));
};

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    Node_SDL::Init(env, exports);
    SDLWindow::Init(env, exports);
    return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)