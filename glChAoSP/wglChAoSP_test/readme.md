# Debug page wglChAoS.P v.1.5.0 (alpha-release)

Following links launch a Debug version wglChAoS.P with a ErrorLog-box of to test TransformFeedback feature

This Debug version is slower to load (it's not WASMed: are about 15MB of .js) and is slower also to execute code (it's not optimized), so please be patient.

**Any feedback is welcome, thanks in advance!**

### Lorenz Attractor

    /wglChAoSP_test/wglChAoSP_lowres.html?width=1024&height=1024&maxbuffer=3&lowprec=1&intbuffer=2&tabletmode=1&glowOFF=1&lightGUI=2&Attractor=ChaoticAttractors/LorenzSM5.sca)

[**Lorenz mouse**](https://brutpitt.github.io/glChAoS.P/wglChAoSP_test/wglChAoSP_lowres.html?width=1024&height=1024&maxbuffer=3&lowprec=1&intbuffer=2&tabletmode=0&glowOFF=1&lightGUI=0&Attractor=ChaoticAttractors/LorenzSM5.sca)

### Multi-Chua II Attractor

[**MultiChua touchscreen**](https://brutpitt.github.io/glChAoS.P/wglChAoSP_test/wglChAoSP_lowres.html?width=1024&height=1024&maxbuffer=3&lowprec=1&intbuffer=2&tabletmode=1&glowOFF=1&lightGUI=2&Attractor=ChaoticAttractors/MultiChuaIISM.sca)

[**MultiChua mouse**](https://brutpitt.github.io/glChAoS.P/wglChAoSP_test/wglChAoSP_lowres.html?width=1024&height=1024&maxbuffer=3&lowprec=1&intbuffer=2&tabletmode=0&glowOFF=1&lightGUI=0&Attractor=ChaoticAttractors/MultiChuaIISM.sca)


### Report an error
- Contact me on twitter: [**BrutPitt**](https://twitter.com/BrutPitt) (also via PM)
- Open an *issue* [**here**](https://github.com/BrutPitt/glChAoS.P/issues), on glChAoS.P github webpage.

And copy the ErrorLogBox content, also adding: 
- Browser (brand and version #).
- Operating System and GPU (PCs) / brand and model (mobile devices)



If no error appear in ErrorLog-box, but nothing appear on the screen, before to contact me, try:

- On mobile devices watch if "lowResources" check is active (mobiles needs it): it is an auto-detect flag, but could fail.

- Close other tabs and/or other browser instances and reload page with the browser "reload button", or (better, on PC) try a "hard reload" using a Ctrl-F5

- Hit ESC key (PC) or double-tap on free canvas border (mobile devices) to hide GUI: if attractor was generated behind a GUI window, it get just a bit time before it appear (it's a SlowMotion feature and Attractor settings are not still complete)

