#include "Intellisense.h"
#include "gba_macros.h"
#include <gba_types.h>
#include "gba_gfx.h"
#include "gba_drawing.h"
#include "gba_mathUtil.h"
#include <gba_input.h>
#include <maxmod.h>
#include <gba.h>
#include <gba_sound.h>

#include <stdio.h>

#include <string.h>

#include "soundbank.h"
#include "soundbank_bin.h"

#include "out1.h"
#include "out2.h"
#include "out3.h"
#include "out4.h"
#include "out5.h"
#include "out6.h"
#include "out7.h"
#include "out8.h"
#include "out9.h"
#include "out10.h"
#include "out11.h"
#include "out12.h"
#include "out13.h"
#include "out14.h"
#include "out15.h"
#include "out16.h"
#include "out17.h"
#include "out18.h"
#include "out19.h"
#include "out20.h"
#include "out21.h"
#include "out22.h"
#include "out23.h"
#include "out24.h"
#include "out25.h"
#include "out26.h"
#include "out27.h"
#include "out28.h"
#include "out29.h"
#include "out30.h"
#include "out31.h"
#include "out32.h"
#include "out33.h"
#include "out34.h"
#include "out35.h"
#include "out36.h"
#include "out37.h"
#include "out38.h"
#include "out39.h"
#include "out40.h"
#include "out41.h"
#include "out42.h"
#include "out43.h"
#include "out44.h"
#include "out45.h"
#include "out46.h"
#include "out47.h"
#include "out48.h"
#include "out49.h"
#include "out50.h"
#include "out51.h"
#include "out52.h"
#include "out53.h"
#include "out54.h"
#include "out55.h"

u8 myMixingBuffer[ MM_MIXLEN_16KHZ ] __attribute((aligned(4)));

void maxmodInit( void )
{
    irqInit();
    irqSet( IRQ_VBLANK, mmVBlank );
    irqEnable( IRQ_VBLANK );

    u8* myData;
    mm_gba_system mySystem;

    // allocate data for channel buffers & wave buffer (malloc'd data goes to EWRAM)
    // Use the SIZEOF definitions to calculate how many bytes to reserve
    myData = (u8*)malloc( 8 * (MM_SIZEOF_MODCH
                               +MM_SIZEOF_ACTCH
                               +MM_SIZEOF_MIXCH)
                          +MM_MIXLEN_16KHZ );

    // setup system info
    // 16KHz software mixing rate, select from mm_mixmode
    mySystem.mixing_mode       = MM_MIX_16KHZ;

    // number of module/mixing channels
    // higher numbers offer better polyphony at the expense
    // of more memory and/or CPU usage.
    mySystem.mod_channel_count = 8;
    mySystem.mix_channel_count = 8;

    // Assign memory blocks to pointers
    mySystem.module_channels   = (mm_addr)(myData+0);
    mySystem.active_channels   = (mm_addr)(myData+(8*MM_SIZEOF_MODCH));
    mySystem.mixing_channels   = (mm_addr)(myData+(8*(MM_SIZEOF_MODCH
                                                      +MM_SIZEOF_ACTCH)));
    mySystem.mixing_memory     = (mm_addr)myMixingBuffer;
    mySystem.wave_memory       = (mm_addr)(myData+(8*(MM_SIZEOF_MODCH
                                                      +MM_SIZEOF_ACTCH
                                                      +MM_SIZEOF_MIXCH)));
    // Pass soundbank address
    mySystem.soundbank         = (mm_addr)soundbank_bin;

    // Initialize Maxmod
    mmInit( &mySystem );
}

u16 __currKeys, __prevKeys;

#define KEY_MASK 0x03FF

inline void PollKeys()
{
    __prevKeys = __currKeys;
    __currKeys = ~REG_KEYINPUT & KEY_MASK;
}

inline u16		currentKeyState()           { return __currKeys; }
inline u16		prevKeyState()              { return __prevKeys; }

inline u16		keyHeld(u16 a_key)       { return (__currKeys & __prevKeys) & a_key; }
inline u16		keyReleased(u16 a_key)   { return (~__currKeys & __prevKeys) & a_key; }
inline u16		keyHit(u16 a_key)        { return (__currKeys & ~__prevKeys) & a_key; }

inline u16		keyStateChange(u16 a_key){ return (__currKeys ^ __prevKeys) & a_key; }

void delayFrame(u16 frame){
    while(frame > 0){
        mmFrame();
        vsync();
        frame--;
    }
    return;
}

int main()
{

	//set GBA rendering context to MODE 4 Bitmap Rendering
	*(u16*)0x04000000 = 0x0404;

    maxmodInit();

    u8 bg = 3;

	while(1){
	    if(bg != 3) bg++;
	    else bg = 0;
	    mmEffect(bg);
        memcpy(0x05000000, out1Pal, out1PalLen);
        memcpy(0x06000000, out1Bitmap, out1BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out2Pal, out2PalLen);
        memcpy(0x06000000, out2Bitmap, out2BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out3Pal, out3PalLen);
        memcpy(0x06000000, out3Bitmap, out3BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out4Pal, out4PalLen);
        memcpy(0x06000000, out4Bitmap, out4BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out5Pal, out5PalLen);
        memcpy(0x06000000, out5Bitmap, out5BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out6Pal, out6PalLen);
        memcpy(0x06000000, out6Bitmap, out6BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out7Pal, out7PalLen);
        memcpy(0x06000000, out7Bitmap, out7BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out8Pal, out8PalLen);
        memcpy(0x06000000, out8Bitmap, out8BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out9Pal, out9PalLen);
        memcpy(0x06000000, out9Bitmap, out9BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out10Pal, out10PalLen);
        memcpy(0x06000000, out10Bitmap, out10BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out11Pal, out11PalLen);
        memcpy(0x06000000, out11Bitmap, out11BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out12Pal, out12PalLen);
        memcpy(0x06000000, out12Bitmap, out12BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out13Pal, out13PalLen);
        memcpy(0x06000000, out13Bitmap, out13BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out14Pal, out14PalLen);
        memcpy(0x06000000, out14Bitmap, out14BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out15Pal, out15PalLen);
        memcpy(0x06000000, out15Bitmap, out15BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out16Pal, out16PalLen);
        memcpy(0x06000000, out16Bitmap, out16BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out17Pal, out17PalLen);
        memcpy(0x06000000, out17Bitmap, out17BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out18Pal, out18PalLen);
        memcpy(0x06000000, out18Bitmap, out18BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out19Pal, out19PalLen);
        memcpy(0x06000000, out19Bitmap, out19BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out20Pal, out20PalLen);
        memcpy(0x06000000, out20Bitmap, out20BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out21Pal, out21PalLen);
        memcpy(0x06000000, out21Bitmap, out21BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out22Pal, out22PalLen);
        memcpy(0x06000000, out22Bitmap, out22BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out23Pal, out23PalLen);
        memcpy(0x06000000, out23Bitmap, out23BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out24Pal, out24PalLen);
        memcpy(0x06000000, out24Bitmap, out24BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out25Pal, out25PalLen);
        memcpy(0x06000000, out25Bitmap, out25BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out26Pal, out26PalLen);
        memcpy(0x06000000, out26Bitmap, out26BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out27Pal, out27PalLen);
        memcpy(0x06000000, out27Bitmap, out27BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out28Pal, out28PalLen);
        memcpy(0x06000000, out28Bitmap, out28BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out29Pal, out29PalLen);
        memcpy(0x06000000, out29Bitmap, out29BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out30Pal, out30PalLen);
        memcpy(0x06000000, out30Bitmap, out30BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out31Pal, out31PalLen);
        memcpy(0x06000000, out31Bitmap, out31BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out32Pal, out32PalLen);
        memcpy(0x06000000, out32Bitmap, out32BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out33Pal, out33PalLen);
        memcpy(0x06000000, out33Bitmap, out33BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out34Pal, out34PalLen);
        memcpy(0x06000000, out34Bitmap, out34BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out35Pal, out35PalLen);
        memcpy(0x06000000, out35Bitmap, out35BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out36Pal, out36PalLen);
        memcpy(0x06000000, out36Bitmap, out36BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out37Pal, out37PalLen);
        memcpy(0x06000000, out37Bitmap, out37BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out38Pal, out38PalLen);
        memcpy(0x06000000, out38Bitmap, out38BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out39Pal, out39PalLen);
        memcpy(0x06000000, out39Bitmap, out39BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out40Pal, out40PalLen);
        memcpy(0x06000000, out40Bitmap, out40BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out41Pal, out41PalLen);
        memcpy(0x06000000, out41Bitmap, out41BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out42Pal, out42PalLen);
        memcpy(0x06000000, out42Bitmap, out42BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out43Pal, out43PalLen);
        memcpy(0x06000000, out43Bitmap, out43BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out44Pal, out44PalLen);
        memcpy(0x06000000, out44Bitmap, out44BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out45Pal, out45PalLen);
        memcpy(0x06000000, out45Bitmap, out45BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out46Pal, out46PalLen);
        memcpy(0x06000000, out46Bitmap, out46BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out47Pal, out47PalLen);
        memcpy(0x06000000, out47Bitmap, out47BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out48Pal, out48PalLen);
        memcpy(0x06000000, out48Bitmap, out48BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out49Pal, out49PalLen);
        memcpy(0x06000000, out49Bitmap, out49BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out50Pal, out50PalLen);
        memcpy(0x06000000, out50Bitmap, out50BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out51Pal, out51PalLen);
        memcpy(0x06000000, out51Bitmap, out51BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out52Pal, out52PalLen);
        memcpy(0x06000000, out52Bitmap, out52BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out53Pal, out53PalLen);
        memcpy(0x06000000, out53Bitmap, out53BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out54Pal, out54PalLen);
        memcpy(0x06000000, out54Bitmap, out54BitmapLen);
        mmFrame();
        vsync();
        memcpy(0x05000000, out55Pal, out55PalLen);
        memcpy(0x06000000, out55Bitmap, out55BitmapLen);
        mmFrame();
        vsync();
	}
}