#
# This is the GPIO-DEMO apllication recipe
#
#

SUMMARY = "recipe file for tss"
SECTION = "PETALINUX/apps"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SRC_URI = "file://tss"
S = "${WORKDIR}/tss"

DEPENDS += " \
    openssl \
    pkgconfig \
    json-c \
    curl \
    pkgconfig-native \
"

#TMP = "/home/imcmy/peta/sdcard/build/tmp/work/aarch64-xilinx-linux/tss/1.0-r0/recipe-sysroot"

CFLAGS_prepend = "-I ${S}/include"
#export LIBCRYPTO_LIBS="-L${TMP}/usr/lib -lcrypto"
#export LIBCRYPTO_CFLAGS="-I${TMP}/usr/include"
#export JSONC_LIBS="-L${TMP}/usr/lib -ljson-c"
#export JSONC_CFLAGS="-I${TMP}/usr/include"
#export CURL_LIBS="-L${TMP}/usr/lib -lcurl"
#export CURL_CFLAGS="-I${TMP}/usr/include"
inherit autotools
