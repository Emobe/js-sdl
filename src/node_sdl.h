#ifndef NODE_SDL_H
#define NODE_SDL_H

#include <napi.h>
#include <SDL2/SDL.h>

    class Node_SDL : public Napi::ObjectWrap<Node_SDL> {
        public:
            static Napi::Object Init(Napi::Env env, Napi::Object exports);
            Node_SDL(const Napi::CallbackInfo &info);
        private:
            static Napi::FunctionReference constructor;
            Napi::Value init(const Napi::CallbackInfo &info);
    };
#endif
