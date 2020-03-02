#include <napi.h>
#include <string>
#include <SDL2/SDL.h>

int create(Napi::Env env){
SDL_Window *window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    SDL_Delay(3000);

    return 0;

}

//Wrapper for calling c++ function
Napi::Number initSDL(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    // calls
    int result = SDL_Init(SDL_INIT_VIDEO);
    return Napi::Number::New(env, result);
}

Napi::Value createWindow(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
     int result = create(env);

    return Napi::Number::New(env, result);

}

// callback for when registered
Napi::Object Init(Napi::Env env, Napi::Object exports){

    exports.Set(
        Napi::String::New(env, "initSDL"), //key
        Napi::Function::New(env, initSDL) //value
    );
    exports.Set(
        Napi::String::New(env, "createWindow"), //key
        Napi::Function::New(env, createWindow) //value
    );

    return exports;
}

//register
NODE_API_MODULE(sdl, Init)