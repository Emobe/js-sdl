const sdl = require('bindings')('hello');


console.log(sdl)
const instance = new sdl.Node_SDL();
instance.init()
const window = new sdl.Window('hello', 0, 0, 100, 100, sdl.SDL_WINDOW_OPENGL)