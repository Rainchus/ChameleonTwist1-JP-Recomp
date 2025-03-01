#include "patches.h"
#include "PR/gbi.h"
#include "PR/os.h"
#include "common_structs.h"
#include "macros.h"
#include "os_message.h"

extern Gfx static0_UnkStatic0_Gfx[];
extern PlayerActor gPlayerActors[4];
extern Mtx *D_800FF8D4;

Gfx *func_8002C4E8(Gfx *gfxPos, s32 arg1, s32 arg2);
Gfx *func_8002C280(GraphicStruct *arg0, Gfx *gfxPos);
void func_80025EF0(PlayerActor *player, Tongue *tongue, s32 arg2);
void func_80027694(GraphicStruct *arg0);
void func_80084A04(void);
void func_8005CA38(void);
Gfx *func_8007A2D8(Gfx *, Camera *);
void func_8008C1C8(Gfx **);
Gfx *func_8005CA44(Gfx *gfxPos);
void func_8007AC60(Camera *, PlayerActor *);
void func_8008C35C(Gfx **);

RECOMP_PATCH Gfx* func_8002C900(GraphicStruct* arg0, s32 arg1) {
    Gfx* gfxPos = arg0->UnkGroup.dlist;
    s32 i;

    gfxPos = func_8002C4E8(arg0->UnkGroup.dlist, arg1, 0);
    gEXEnable(gfxPos++); // @recomp
    gEXSetRefreshRate(gfxPos++, 60 / 2);
    gSPDisplayList(gfxPos++, static0_UnkStatic0_Gfx);
    gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(&gFrameBuffers[arg1]));
    gfxPos = func_8002C280(arg0, gfxPos);
    D_800FF8D4 = arg0->unk1e880;

    for (i = 0; i < ARRAY_COUNT(gPlayerActors); i++) {
        if (!gPlayerActors[i].exists) {
            continue;
        }
        func_80025EF0(&gPlayerActors[i], &gTongues[i], i);
    }

    func_80027694(arg0);
    func_80084A04();
    func_8005CA38();
    gfxPos = func_8007A2D8(gfxPos, gCamera);
    func_8008C1C8(&gfxPos);
    gfxPos = func_8005CA44(gfxPos);
    func_8007AC60(gCamera, gPlayerActors);
    func_8008C35C(&gfxPos);
    gDPFullSync(gfxPos++);
    gSPEndDisplayList(gfxPos++);
    return gfxPos;
}