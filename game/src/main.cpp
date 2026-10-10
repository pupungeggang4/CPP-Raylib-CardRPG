#include "includes.hpp"
#include "game.hpp"

#ifdef __EMSCRIPTEN__
void emLoop () {
    game.loop();
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
void emRun () {
    game.init();
    emscripten_set_main_loop(emLoop, 0, 0);
}
}
#endif

int main(int argc, char** argv) {
    #ifdef __EMSCRIPTEN__
    EM_ASM({
        try { FS.mkdir('/save'); } catch(e) {}
        FS.mount(FS.filesystems.IDBFS, {}, '/save');
        Module.print("IDBFS 마운트 완료");
        FS.syncfs(true, function(err) {
            if (err) Module.print(err);
            else Module.print("Load complete!");
            _emRun();
        });
    });
    #else
    game.init();
    while (game.running) {
        game.loop();
    }
    #endif
    return 0;
}
