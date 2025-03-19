## `journalctl` core-dumped

### Crash w/o patch
```
Module libdrm.so.2 from rpm libdrm-2.4.124-1.fc41.x86_64
Module libX11-xcb.so.1 from rpm libX11-1.8.11-1.fc41.x86_64
Module libxcb-dri3.so.0 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libxcb-randr.so.0 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libxcb-glx.so.0 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libXrandr.so.2 from rpm libXrandr-1.5.4-4.fc41.x86_64
Module libXi.so.6 from rpm libXi-1.8.2-1.fc41.x86_64
Module libXfixes.so.3 from rpm libXfixes-6.0.1-4.fc41.x86_64
Module libXrender.so.1 from rpm libXrender-0.9.12-1.fc41.x86_64
Module libXcursor.so.1 from rpm libXcursor-1.2.3-1.fc41.x86_64
Module libXext.so.6 from rpm libXext-1.3.6-2.fc41.x86_64
Module libXau.so.6 from rpm libXau-1.0.11-7.fc41.x86_64
Module libxcb.so.1 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libX11.so.6 from rpm libX11-1.8.11-1.fc41.x86_64
Module libcap.so.2 from rpm libcap-2.70-4.fc41.x86_64
Module libsystemd.so.0 from rpm systemd-256.12-1.fc41.x86_64
Module libdbus-1.so.3 from rpm dbus-1.14.10-4.fc41.x86_64
Module libSDL2-2.0.so.0 from rpm SDL2-2.30.11-1.fc41.x86_64
Stack trace of thread 61145:
#0  0x00007fe3fbcbea34 _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_ (libstdc++.so.6 + 0xbea34)
#1  0x00007fe3fc549864 _ZN4dawn6native13ApiObjectBase8SetLabelENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE (libwebgpu_dawn.so + 0x4ab864)
#2  0x00007fe3fc64962b _ZNK4dawn6native13SwapChainBase13SetChildLabelEPNS0_13ApiObjectBaseE (libwebgpu_dawn.so + 0x5ab62b)
#3  0x00007fe3fc648b4a _ZN4dawn6native13SwapChainBase17GetCurrentTextureEv (libwebgpu_dawn.so + 0x5aab4a)
#4  0x00007fe3fc63b650 _ZNK4dawn6native7Surface17GetCurrentTextureEPNS0_14SurfaceTextureE (libwebgpu_dawn.so + 0x59d650)
#5  0x00007fe3fc63bcf0 _ZNK4dawn6native7Surface20APIGetCurrentTextureEPNS0_14SurfaceTextureE (libwebgpu_dawn.so + 0x59dcf0)
#6  0x00007fe3fc3243d4 _ZN4dawn6native30NativeSurfaceGetCurrentTextureEP15WGPUSurfaceImplP18WGPUSurfaceTexture (libwebgpu_dawn.so + 0x2863d4)
#7  0x00007fe3fd530d12 wgpuSurfaceGetCurrentTexture (libwebgpu_dawn.so + 0x1492d12)
#8  0x000000000040ba12 _ZNK4wgpu7Surface17GetCurrentTextureEPNS_14SurfaceTextureE (imguizmo_quat_wgpuLightCube + 0xba12)
#9  0x0000000000403a5e _Z8mainLoopv (imguizmo_quat_wgpuLightCube + 0x3a5e)
#10 0x0000000000404167 main (imguizmo_quat_wgpuLightCube + 0x4167)
#11 0x00007fe3fb92a248 __libc_start_call_main (libc.so.6 + 0x3248)
#12 0x00007fe3fb92a30b __libc_start_main@@GLIBC_2.34 (libc.so.6 + 0x330b)
#13 0x0000000000401aa5 _start (imguizmo_quat_wgpuLightCube + 0x1aa5)

Stack trace of thread 61169:
#0  0x00007fe3fb9947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fe3fb997191 pthread_cond_timedwait@@GLIBC_2.3.2 (libc.so.6 + 0x70191)
#2  0x00007fe3ebc1afbc n/a (libnvidia-glcore.so.570.124.04 + 0xa1afbc)
#3  0x00007fe3ec03a5cd n/a (libnvidia-glcore.so.570.124.04 + 0xe3a5cd)
#4  0x00007fe3ebc1b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fe3fb997ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fe3fba1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 61165:
#0  0x00007fe3fb9e4153 clock_nanosleep@GLIBC_2.2.5 (libc.so.6 + 0xbd153)
#1  0x00007fe3fb9f0247 __nanosleep (libc.so.6 + 0xc9247)
#2  0x00007fe3ebc1b427 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b427)
#3  0x00007fe3ec04a376 n/a (libnvidia-glcore.so.570.124.04 + 0xe4a376)
#4  0x00007fe3ebc1b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fe3fb997ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fe3fba1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 61166:
#0  0x00007fe3fb9947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fe3fb997191 pthread_cond_timedwait@@GLIBC_2.3.2 (libc.so.6 + 0x70191)
#2  0x00007fe3ebc1afbc n/a (libnvidia-glcore.so.570.124.04 + 0xa1afbc)
#3  0x00007fe3ec06cdf2 n/a (libnvidia-glcore.so.570.124.04 + 0xe6cdf2)
#4  0x00007fe3ebc1b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fe3fb997ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fe3fba1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 61167:
#0  0x00007fe3fb9947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fe3fb996f8e pthread_cond_wait@@GLIBC_2.3.2 (libc.so.6 + 0x6ff8e)
#2  0x00007fe3ebc1af5c n/a (libnvidia-glcore.so.570.124.04 + 0xa1af5c)
#3  0x00007fe3ec059945 n/a (libnvidia-glcore.so.570.124.04 + 0xe59945)
#4  0x00007fe3ebc1b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fe3fb997ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fe3fba1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 61171:
#0  0x00007fe3fb9947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fe3fb997191 pthread_cond_timedwait@@GLIBC_2.3.2 (libc.so.6 + 0x70191)
#2  0x00007fe3ebc1afbc n/a (libnvidia-glcore.so.570.124.04 + 0xa1afbc)
#3  0x00007fe3ec15efac n/a (libnvidia-glcore.so.570.124.04 + 0xf5efac)
#4  0x00007fe3ec154e66 n/a (libnvidia-glcore.so.570.124.04 + 0xf54e66)
#5  0x00007fe3ebc1b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#6  0x00007fe3fb997ba8 start_thread (libc.so.6 + 0x70ba8)
#7  0x00007fe3fba1bb8c __clone3 (libc.so.6 + 0xf4b8c)
ELF object binary architecture: AMD x86-64
```

### Crash with patch
```
Module libdrm.so.2 from rpm libdrm-2.4.124-1.fc41.x86_64
Module libcap.so.2 from rpm libcap-2.70-4.fc41.x86_64
Module libsystemd.so.0 from rpm systemd-256.12-1.fc41.x86_64
Module libdbus-1.so.3 from rpm dbus-1.14.10-4.fc41.x86_64
Module libxcb-dri3.so.0 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libxcb-randr.so.0 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libxcb-glx.so.0 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libX11-xcb.so.1 from rpm libX11-1.8.11-1.fc41.x86_64
Module libXinerama.so.1 from rpm libXinerama-1.1.5-7.fc41.x86_64
Module libXfixes.so.3 from rpm libXfixes-6.0.1-4.fc41.x86_64
Module libXcursor.so.1 from rpm libXcursor-1.2.3-1.fc41.x86_64
Module libXrender.so.1 from rpm libXrender-0.9.12-1.fc41.x86_64
Module libXrandr.so.2 from rpm libXrandr-1.5.4-4.fc41.x86_64
Module libXi.so.6 from rpm libXi-1.8.2-1.fc41.x86_64
Module libXext.so.6 from rpm libXext-1.3.6-2.fc41.x86_64
Module libXxf86vm.so.1 from rpm libXxf86vm-1.1.6-1.fc41.x86_64
Module libXau.so.6 from rpm libXau-1.0.11-7.fc41.x86_64
Module libxcb.so.1 from rpm libxcb-1.17.0-3.fc41.x86_64
Module libX11.so.6 from rpm libX11-1.8.11-1.fc41.x86_64
Stack trace of thread 56785:
#0  0x00007fabe574321a _ZNK4dawn6native10ObjectBase9GetDeviceEv (libwebgpu_dawn.so + 0x4ab21a)
#1  0x00007fabe551e5a2 _ZN4dawn6native23NativeTextureCreateViewEP15WGPUTextureImplPK25WGPUTextureViewDescriptor (libwebgpu_dawn.so + 0x2865a2)
#2  0x00007fabe672ae68 wgpuTextureCreateView (libwebgpu_dawn.so + 0x1492e68)
#3  0x000000000040bae0 _ZNK4wgpu7Texture10CreateViewEPKNS_21TextureViewDescriptorE (imguizmo_quat_wgpuCube + 0xbae0)
#4  0x0000000000403c60 _Z8mainLoopv (imguizmo_quat_wgpuCube + 0x3c60)
#5  0x0000000000404301 main (imguizmo_quat_wgpuCube + 0x4301)
#6  0x00007fabe4d2a248 __libc_start_call_main (libc.so.6 + 0x3248)
#7  0x00007fabe4d2a30b __libc_start_main@@GLIBC_2.34 (libc.so.6 + 0x330b)
#8  0x0000000000401bf5 _start (imguizmo_quat_wgpuCube + 0x1bf5)

Stack trace of thread 56788:
#0  0x00007fabe4d947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fabe4d97191 pthread_cond_timedwait@@GLIBC_2.3.2 (libc.so.6 + 0x70191)
#2  0x00007fabd521afbc n/a (libnvidia-glcore.so.570.124.04 + 0xa1afbc)
#3  0x00007fabd566cdf2 n/a (libnvidia-glcore.so.570.124.04 + 0xe6cdf2)
#4  0x00007fabd521b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fabe4d97ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fabe4e1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 56787:
#0  0x00007fabe4de4153 clock_nanosleep@GLIBC_2.2.5 (libc.so.6 + 0xbd153)
#1  0x00007fabe4df0247 __nanosleep (libc.so.6 + 0xc9247)
#2  0x00007fabd521b427 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b427)
#3  0x00007fabd564a376 n/a (libnvidia-glcore.so.570.124.04 + 0xe4a376)
#4  0x00007fabd521b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fabe4d97ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fabe4e1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 56789:
#0  0x00007fabe4d947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fabe4d96f8e pthread_cond_wait@@GLIBC_2.3.2 (libc.so.6 + 0x6ff8e)
#2  0x00007fabd521af5c n/a (libnvidia-glcore.so.570.124.04 + 0xa1af5c)
#3  0x00007fabd5659945 n/a (libnvidia-glcore.so.570.124.04 + 0xe59945)
#4  0x00007fabd521b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fabe4d97ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fabe4e1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 56793:
#0  0x00007fabe4d947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fabe4d97191 pthread_cond_timedwait@@GLIBC_2.3.2 (libc.so.6 + 0x70191)
#2  0x00007fabd521afbc n/a (libnvidia-glcore.so.570.124.04 + 0xa1afbc)
#3  0x00007fabd575efac n/a (libnvidia-glcore.so.570.124.04 + 0xf5efac)
#4  0x00007fabd5754e66 n/a (libnvidia-glcore.so.570.124.04 + 0xf54e66)
#5  0x00007fabd521b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#6  0x00007fabe4d97ba8 start_thread (libc.so.6 + 0x70ba8)
#7  0x00007fabe4e1bb8c __clone3 (libc.so.6 + 0xf4b8c)

Stack trace of thread 56791:
#0  0x00007fabe4d947e9 __futex_abstimed_wait_common (libc.so.6 + 0x6d7e9)
#1  0x00007fabe4d97191 pthread_cond_timedwait@@GLIBC_2.3.2 (libc.so.6 + 0x70191)
#2  0x00007fabd521afbc n/a (libnvidia-glcore.so.570.124.04 + 0xa1afbc)
#3  0x00007fabd563a5cd n/a (libnvidia-glcore.so.570.124.04 + 0xe3a5cd)
#4  0x00007fabd521b174 n/a (libnvidia-glcore.so.570.124.04 + 0xa1b174)
#5  0x00007fabe4d97ba8 start_thread (libc.so.6 + 0x70ba8)
#6  0x00007fabe4e1bb8c __clone3 (libc.so.6 + 0xf4b8c)
ELF object binary architecture: AMD x86-64
```
