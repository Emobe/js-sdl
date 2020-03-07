#include <iostream>
#include <string>
#include "window.h"

Napi::FunctionReference sdl::WindowWrap::constructor;

Napi::Object sdl::WindowWrap::Init(Napi::Env env, Napi::Object exports){
    Napi::Function func = DefineClass(env, "Window", {
        //InstanceMethod("GetWindowBrightness", &sdl::WindowWrap::GetWindowBrightness)
    });

    constructor = Napi::Persistent(func);

    constructor.SuppressDestruct();
    exports.Set("Window", func);
    return exports;
};

sdl::WindowWrap::~WindowWrap(){
    	std::cout << "WindowWrapper destructor running." << std::endl;
	if(NULL != window_) {
		std::cout << "Destroying contained window." << std::endl;
		SDL_DestroyWindow(window_);
	}
}
sdl::WindowWrap::WindowWrap(const Napi::CallbackInfo &info) : Napi::ObjectWrap<WindowWrap>(info){
    Napi::Env env = info.Env();
    //Napi::HandleScope scope(info.Env());

    std::string title = info[0].IsUndefined() ? Napi::String::New(env, "") : info[0].As<Napi::String>();
    int x = info[1].IsUndefined() ? SDL_WINDOWPOS_UNDEFINED : info[1].As<Napi::Number>();
    int y = info[2].IsUndefined() ? SDL_WINDOWPOS_UNDEFINED : info[2].As<Napi::Number>();
    int w = info[3].IsUndefined() ? 640 : info[3].As<Napi::Number>();
    int h = info[4].IsUndefined() ? 480 : info[4].As<Napi::Number>();
    Uint32 flags = info[5].As<Napi::Number>();
    window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

    if(NULL == window_){
        delete window_;
    }

    SDL_Delay(3000);
}