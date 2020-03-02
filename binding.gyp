{
    "targets": [
        {
            "target_name": "hello",
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "sources": [
                "./src/node_sdl.cpp",
                "./src/window.cpp",
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                '/usr/include/SDL2'
            ],
            'libraries': [
                '/usr/lib/libSDL2-2.0.so',
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' 
			'_THREAD_SAFE',
			'ENABLE_ARG_CHECKING',
			'ENABLE_IMAGE',
			'ENABLE_TTF'
		],
        }
    ]
}