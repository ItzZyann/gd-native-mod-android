# Geometry Dash Mod Template (Android)

## Requirements

-   Use **Android NDK r16 or r17 only**\
-   Versions below r16 or above r17 are **not supported**

Make sure you: - Know basic **C++** - Understand the **cocos2d API**

------------------------------------------------------------------------

## How to Use

1.  Clone the repository\

2.  Extract it\

3.  Add the NDK to your **environment path**

4.  Run:

    ``` bash
    ndk-build
    ```

------------------------------------------------------------------------

## Important Notes

-   This only works on **Geometry Dash v2.2081 (Android, 64-bit /
    arm64-v8a)**

Right now, this is required because: - **32-bit support is slowly being
removed by Google**

If you want a cleaner and more efficient way to make mods, you should
use **Geode-SDK**, since most developers use it for Geometry Dash
modding.

------------------------------------------------------------------------

## How to Inject the `.so`

1.  Download **Geometry Dash v2.2081**

2.  Delete the `armeabi-v7a` folder

3.  Open `classes.dex`

4.  Find the `GeometryJump` class\
    Path:

        com/robtopx/geometryjump/GeometryJump

5.  Inside the constructor, you will see library names like:

        cocos2dcpp

6.  Below `cocos2dcpp`, add this code:

        .line 69
        const-string v0, "gdmod"

        invoke-static {v0}, Ljava/lang/System->loadLibrary(Ljava/lang/String;)V

7.  Repack and sign the APK

8.  Done --- your mod should now work 🎉

------------------------------------------------------------------------

## For Geometry Dash 2.1

Check this repo instead:\
https://github.com/iAndyHD3/gd-mod-example-android

------------------------------------------------------------------------

## Contact

-   Discord: `itzzyann_`\
-   Gmail: `zyanndev@gmail.com`
