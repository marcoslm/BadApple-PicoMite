# Bad Apple for PicoMite HDMI/USB

Bad Apple demo for the PicoMite HDMI/USB, in two versions:

- **HQ** (320x240, ~22 FPS) — uses a fast CSUB decoder written in C.
- **LQ** (160x120, ~6 FPS) — pure MMBasic, easy to read.

Includes everything needed to run the demo, plus the tools used to generate the video format.

## Demo video

[![Bad Apple on PicoMite HDMI/USB](https://img.youtube.com/vi/hlqbMI7XZ-w/hqdefault.jpg)](https://www.youtube.com/watch?v=hlqbMI7XZ-w)

https://www.youtube.com/watch?v=hlqbMI7XZ-w

## Files

```
badapple.bas        Main demo (menu + playback)
decode.c            CSUB line decoder for HQ mode
compilar_csub.cmd   Script to compile decode.c

csub/               Tools and headers needed for CSUB compilation
vidconv/            twinBASIC encoder (RAW to RLE)
```

## How to run

Download the ready-to-use package from Releases:

https://github.com/marcoslm/BadApple-PicoMite/releases

Copy these files to the SD card of your PicoMite:

```
badapple.bas
ba.jpg
ba.aud
ba.vid     (HQ)
balq.vid   (LQ)
```

Then run:

```
RUN "badapple.bas"
```

Controls:

- Up/Down: select mode
- Enter: start
- ESC: exit

## CPU speed / resolution

For proper audio/video sync this demo expects the CPU clock to be 315 MHz.

On a PicoMite HDMI/USB this is the default after:

```basic
OPTION RESET HDMIUSB
```

If you change the video resolution, the CPU speed may also change automatically.
Make sure CPUSPEED is still 315000000 Hz (for example with `PRINT MM.INFO$(CPUSPEED)` or `OPTION LIST`), or set it back with:

```basic
OPTION RESOLUTION 640x480,315000
```

## Tools included

- HQ decoder (CSUB) in `decode.c`
- RAW to RLE encoder (twinBASIC) in `/vidconv`
- Build script to regenerate the CSUB in `/compilar_csub.cmd`

These tools are optional. You only need them if you want to modify or rebuild the video files or the decoder.

## Notes (Spanish)

Este proyecto lo uso para compartir con mis colegas del grupo Pixels Party para que se animen a cacharrear.

## License

MIT

