#include <iostream>
#include <string>
#include "window.h"

Napi::FunctionReference SDLWindow::constructor;

Napi::Object SDLWindow::Init(Napi::Env env, Napi::Object exports){
    Napi::Function func = DefineClass(env, "SDLWindow", {
        InstanceMethod("createWindow", &SDLWindow::createWindow),
        InstanceMethod("GetWindowBrightness", &SDLWindow::GetWindowBrightness)
    });

    constructor = Napi::Persistent(func);

    constructor.SuppressDestruct();
    exports.Set("SDLWindow", func);
    return exports;
};
SDLWindow::SDLWindow(const Napi::CallbackInfo &info) : Napi::ObjectWrap<SDLWindow>(info) {
}

SDLWindow::~SDLWindow(){
    	std::cout << "WindowWrapper destructor running." << std::endl;
	if(NULL != window_) {
		std::cout << "Destroying contained window." << std::endl;
		SDL_DestroyWindow(window_);
        SDL_Quit();
	}
}

Napi::Value SDLWindow::createWindow(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();

    std::string title = info[0].IsUndefined() ? Napi::String::New(env, "") : info[0].As<Napi::String>();
    int x = info[1].IsUndefined() ? SDL_WINDOWPOS_UNDEFINED : info[1].As<Napi::Number>();
    int y = info[2].IsUndefined() ? SDL_WINDOWPOS_UNDEFINED : info[2].As<Napi::Number>();
    int w = info[3].IsUndefined() ? 640 : info[3].As<Napi::Number>();
    int h = info[4].IsUndefined() ? 480 : info[4].As<Napi::Number>();
    Uint32 flags = SDL_WINDOW_OPENGL;//info[5].As<Napi::Number>();
    window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

    SDL_Delay(3000);

    if(window_ == NULL) {
        return Napi::Number::New(env, 1);
	}

    return Napi::Number::New(env, 0);
}

Napi::Value SDLWindow::GetWindowBrightness(const Napi::CallbackInfo &args){

}


//Napi::String title = info[0].IsUndefined() ? "" : info[0].As<Napi::String>();
//int x = info[1].IsUndefined() ? SDL_WINDOWPOS_UNDEFINED : info[1].Int32Value();
//int y = info[2].IsUndefined() ? SDL_WINDOWPOS_UNDEFINED : info[2].Int32Value();
//int w = info[3].IsUndefined() ? 640 : info[3].Int32Value();
//int h = info[4].IsUndefined() ? 480 : info[4].Int32Value();
//uint32_t flags = info[5]>IsUndefined() ? 0 : info[5]->Int32Value();
//this->window_ = SDL_CreateWindow(title, x, y, w, h, flags);