var addon = require('bindings')('hello');

const ey = new addon.Node_SDL()
const sdlwin = new addon.SDLWindow()

console.log(ey, addon)
console.log(ey.init())
console.log(sdlwin.createWindow("test", 0, 0))
