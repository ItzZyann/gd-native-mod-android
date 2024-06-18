# gd-native-mod-android
Basic Geometry Dash Native Mod example meant for beginners or as a template.
And now? It supports v2.2 (2.206)
A updated version of [gd-mod-example-android](https://github.com/iAndyHD3/gd-mod-example-android) for Android featuring a new and updated modloader.
<p align="center">
<img src="https://github.com/ItzZyann/gd-native-mod-android/blob/main/screenshots/shot1.jpg" alt="screenshot" width="48%">
<img src="https://github.com/ItzZyann/gd-native-mod-android/blob/main/screenshots/shot2.jpg" alt="screenshot" width="48%">
<img src="https://github.com/ItzZyann/gd-native-mod-android/blob/main/screenshots/shot3.jpg" alt="screenshot" width="48%">
<img src="https://github.com/ItzZyann/gd-native-mod-android/blob/main/screenshots/shot4.jpg" alt="screenshot" width="48%">
</p>

## Usage
### Build

- Clone the repo

- To build this project you will need the version r16b or r17 of the Native Development Kit for Android, but I recommend to use r16b.

[Windows 32-bit](https://dl.google.com/android/repository/android-ndk-r16b-windows-x86.zip)
[Windows 64-bit](https://dl.google.com/android/repository/android-ndk-r16b-windows-x86_64.zip)

- Edit the paths inside Build.bat and run it
- The compiled files should be in gd-mod-example-android/libs/armeabi-v7a

### Inject the shared libraries into the APK
To make the mod work we need to edit the java source code of the APK to load the compiled .so files

- Have a Geometry Dash APK ready
- Get an APK Editor that supports **smali**

There are many APK Edit tools available, personally I recommend [APK Editor Studio](https://qwertycube.com/apk-editor-studio/download/)

- Decompile the APK with **smali**

To enable smali on APK Editor Studio:
Settings -> Options (CTRL + P) -> Apktool -> Decompile source code (smali)

- Open the contents of the APK
- Go to this path`/smali/com/robtopx/geometryjump`
and open `GeometryJump.smali`


- Copy + Paste this code 3 times
- Change the string to match our .so file names.
Note: names are without `lib` and without `.so`

```smali
    .line 68
    const-string v0, "cocos2dcpp"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

 In the Geometry dash 2.2.142 (2.206) APK the method should look like this

```smali
# direct methods
.method static constructor <clinit>()V
    .registers 1

    const-string v0, "fmod"

    .line 68
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    const-string v0, "cocos2dcpp"

    .line 68
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    const-string v0, "dobby"

    .line 68
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    const-string v0, "hooking"

    .line 68
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    const-string v0, "game"

    .line 69
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    return-void
.end method
```
- Last, move the .so files to the `/lib/armeabi-v7a` folder
- Compile the APK and if sign it manually if necessary
(APK Editor Sutdio signs it for you)
- Install APK


---
After this one-time setup you only need to update the `libgame.so` file inside the `lib/armeabi-v7a/` folder.

All the source files contain a lot of comments which you should definitely read if you're just starting out :) (i recommend starting from main.cpp)
For more hacks or mod example you can go to [gd-example-mods](https://github.com/ItzZyann/gd-example-mods/)

## Resources
- [Ghidra](https://ghidra-sre.org/) - A free reverse engineering tool, which is almost mandatory for GD modding
- [GD Programming](https://discord.gg/jEwtDBK) - A discord server where you can ask a lot of questions :D
- [Awesome ADB](https://github.com/mzlogin/awesome-adb/blob/master/README.en.md) - Everything there's to know about how to use ADB to speed up development
- [ADB Logcat](https://developer.android.com/studio/command-line/logcat) - Powerful ADB command to print debug messages to console or to obtain crash logs
- [cocos2dx](https://hjfod.github.io/cocos-headers) - Documentation for the version of cocos robtop uses as a base (with robtop modifications documented)

## Credits
- [Italian APK Downloader](https://github.com/ItalianApkDownloader/) General help, modloader, project setup, gd.h
-  [mat](https://github.com/matcool/) - Original mod idea, example code, explanations
- [iAndyHD3](https://github.com/iAndyHD3/) - The original repo that i clone to update it and make better.