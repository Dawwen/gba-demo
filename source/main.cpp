#include "log.h"
#include "video.h"
#include "input.h"
#include "font.h"
#include "comm.h"


#include "Demo.h"


extern void*  __start_animation_resource[];
extern void*  __stop_animation_resource[];

const u32 SUBARU_ID = 1;

int main(int argc, char const *argv[])
{
    video::createResourceManager(__start_animation_resource, __stop_animation_resource);
    Demo demo;
    demo.init();
    
    u32 i = 0;
    while (true)
    {
        demo.process(i);
        video::waitVBlank();
        i++;
    }
    LOG_WARNING("Program finished");

    mgba_close();
    return 0;
}
