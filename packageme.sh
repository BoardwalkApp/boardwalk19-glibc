make install install_root=/media/zhuowei/redhd/docs/winprogress/glibc/glibc-2.21/dist/
cd ../dist
rm ../newglibc.tar.xz
tar cJf ../newglibc.tar.xz lib/*.so*
adb push ../newglibc.tar.xz /sdcard/
