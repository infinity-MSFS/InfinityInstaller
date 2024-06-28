# Infinity Installer

## Dependencies

the only dependencies that are not included are [vulkan](https://vulkan.lunarg.com/sdk/home#windows) and the Windows
SDK (just make it easy on yourself and use VS)

you might have to update the vulkan sdk path in the CMakeLists.txt #46 if you dont install Vulkan in the default
location, No dynamic non system libs are used, so it should just run on any Windows machine with
the [cpp 2022/2019 redist](https://aka.ms/vs/17/release/vc_redist.x64.exe)

## Building

```bash
git clone --recursive https://github.com/infinity-MSFS/InfinityInstaller.git
cd InfinityInstaller
mkdir build
cd build
cmake ..
cmake --build .
```
