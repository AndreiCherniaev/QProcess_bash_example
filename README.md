How start FFmpeg using QProcess with bash example. Output
```
new QProcess state= QProcess::Starting
new QProcess state= QProcess::Running
new QProcess state= QProcess::NotRunning
QProcess should finish
QProcess finish ok;msg;libGL error: No matching fbConfigs or visuals found
libGL error: failed to load driver: swrast
X Error:  GLXBadContext
  Request Major code 152 (GLX)
  Request Minor code 6 ()
  Error Serial #63
  Current Serial #62
ffmpeg version n4.3.1 Copyright (c) 2000-2020 the FFmpeg developers
  built with gcc 7 (Ubuntu 7.5.0-3ubuntu1~18.04)
  configuration: --prefix= --prefix=/usr --disable-debug --disable-doc --disable-static --enable-cuda --enable-cuda-sdk --enable-cuvid --enable-libdrm --enable-ffplay --enable-gnutls --enable-gpl --enable-libass --enable-libfdk-aac --enable-libfontconfig --enable-libfreetype --enable-libmp3lame --enable-libnpp --enable-libopencore_amrnb --enable-libopencore_amrwb --enable-libopus --enable-libpulse --enable-sdl2 --enable-libspeex --enable-libtheora --enable-libtwolame --enable-libv4l2 --enable-libvorbis --enable-libvpx --enable-libx264 --enable-libx265 --enable-libxcb --enable-libxvid --enable-nonfree --enable-nvenc --enable-omx --enable-openal --enable-opencl --enable-runtime-cpudetect --enable-shared --enable-vaapi --enable-vdpau --enable-version3 --enable-xlib
  libavutil      56. 51.100 / 56. 51.100
  libavcodec     58. 91.100 / 58. 91.100
  libavformat    58. 45.100 / 58. 45.100
  libavdevice    58. 10.100 / 58. 10.100
  libavfilter     7. 85.100 /  7. 85.100
  libswscale      5.  7.100 /  5.  7.100
  libswresample   3.  7.100 /  3.  7.100
  libpostproc    55.  7.100 / 55.  7.100
Input #0, lavfi, from 'testsrc=size=1280x720:rate=1:duration=10':
  Duration: N/A, start: 0.000000, bitrate: N/A
    Stream #0:0: Video: rawvideo (RGB[24] / 0x18424752), rgb24, 1280x720 [SAR 1:1 DAR 16:9], 1 fps, 1 tbr, 1 tbn, 1 tbc
Stream mapping:
  Stream #0:0 -> #0:0 (rawvideo (native) -> mjpeg (native))
Press [q] to stop, [?] for help
[swscaler @ 0x6438de58b780] deprecated pixel format used, make sure you did set range correctly
Output #0, mjpeg, to 'input.yuvj422p':
  Metadata:
    encoder         : Lavf58.45.100
    Stream #0:0: Video: mjpeg, yuvj422p(pc), 1280x720 [SAR 1:1 DAR 16:9], q=2-31, 200 kb/s, 1 fps, 1 tbn, 1 tbc
    Metadata:
      encoder         : Lavc58.91.100 mjpeg
    Side data:
      cpb: bitrate max/min/avg: 0/0/200000 buffer size: 0 vbv_delay: N/A
[Parsed_testsrc_0 @ 0x6438de576b80] EOF timestamp not reliable
frame=   10 fps=0.0 q=1.6 Lsize=     324kB time=00:00:10.00 bitrate= 265.0kbits/s speed= 173x    
video:324kB audio:0kB subtitle:0kB other streams:0kB global headers:0kB muxing overhead: 0.000000%
```

If I change code to `process->setArguments({"-c", "mistake here"})` then output
```
new QProcess state= QProcess::Starting
new QProcess state= QProcess::Running
new QProcess state= QProcess::NotRunning
QProcess should finish
QProcess finish with code;127;exitStatus;QProcess::NormalExit;msg;/usr/bin/bash: line 1: mistake: command not found
```
