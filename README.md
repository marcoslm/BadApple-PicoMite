# 🦇 Bad Apple for PicoMite HDMI/USB

This repository contains a **Bad Apple** demo for the PicoMite HDMI/USB, featuring both:

- **HQ version (320×240, ~22 FPS)**  
  Uses a fast **CSUB decoder in C**

- **LQ version (160×120, ~6 FPS)**  
  Pure **MMBasic**, easy to read and learn from

It includes everything needed to run the demo and the tools used to generate the video format.

---

## 📦 Files

```
badapple.bas        → Main demo (menu + playback)
decode.c            → CSUB line decoder for HQ mode
compilar_csub.cmd   → Script to compile decode.c

csub/               → Tools and headers needed for CSUB compilation
vidconv/            → twinBASIC encoder (RAW → RLE)
```

---

## ▶️ How to Run

Download the ready-to-use package from **Releases**:

👉 https://github.com/marcoslm/BadApple-PicoMite/releases

Copy these files to the SD card of your PicoMite:

```
badapple.bas
ba.jpg
ba.aud
ba.vid     (HQ)
balq.vid   (LQ)
```

Then run:

`RUN "badapple.bas"`

**Controls:**

- Up/Down → Select mode

- Enter → Start

- ESC → Exit

---

## 🛠️ Tools Included

- **HQ decoder (CSUB)** in `decode.c`

- **RAW → RLE encoder** (twinBASIC) in `/vidconv`

- **Build script** to regenerate the CSUB in `/compilar_csub.cmd`

These tools are optional; you only need them if you want to modify or rebuild the video files or the decoder.

---

## 👥 Notes (Spanish)

Este proyecto lo uso para compartir con mis colegas del grupo Pixels Party para que se animen a cacharrear.

---

## 📜 License

MIT

---

Created by Marcos López Merayo (2025)
