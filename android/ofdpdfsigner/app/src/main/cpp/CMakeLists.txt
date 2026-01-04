# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("ofdpdfsigner")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.



#ofdzip.so
add_library(ZIP_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/thirdparty/zlib/adler32.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/compress.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/crc32.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/deflate.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/gzclose.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/gzlib.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/gzread.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/gzwrite.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/infback.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/inffast.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/inflate.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/inftrees.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/trees.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/uncompr.c
        ../../../../../../ofdpdfsigner/thirdparty/zlib/zutil.c
)

target_include_directories(
        ZIP_LIB_SRC
        PRIVATE
        ../../../../../../ofdpdfsigner/thirdparty/zlib
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng
)

target_compile_definitions(
        ZIP_LIB_SRC
        PRIVATE
        -D_64_
        -DZLIB_COMPAT
        -DHAVE_ZLIB
        -DMZ_ZIP_NO_CRYPTO
)

add_library(MINIZIP_NG_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_compat.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_crypt.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_os_posix.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_os.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm_buf.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm_mem.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm_os_posix.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm_pkcrypt.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm_split.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm_zlib.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_strm.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_zip_rw.c
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/mz_zip.c
)

target_include_directories(
        MINIZIP_NG_LIB_SRC
        PRIVATE
        ../../../../../../ofdpdfsigner/thirdparty/zlib
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng
)

target_compile_definitions(
        MINIZIP_NG_LIB_SRC
        PRIVATE
        -D_64_
        -DZLIB_COMPAT
        -DHAVE_ZLIB
        -DMZ_ZIP_NO_CRYPTO
)

add_library( # Sets the name of the library.
        doczip

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        $<TARGET_OBJECTS:ZIP_LIB_SRC>
        $<TARGET_OBJECTS:MINIZIP_NG_LIB_SRC>

)

target_compile_definitions(
        doczip
        PRIVATE
        -D_64_
        -DZLIB_COMPAT
        -DHAVE_ZLIB
        -DMZ_ZIP_NO_CRYPTO
)

target_include_directories(
        doczip
        PRIVATE
        ../../../../../../ofdpdfsigner/thirdparty/zlib
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng
)

target_link_libraries( # Specifies the target library.
        doczip
        android
)
#---------------------------------------------------------------------------------------------------
#pdf.so
#运行 build_mupdf.sh
add_library(
        mupdf
        SHARED
        IMPORTED
)

set_target_properties(
        mupdf
        PROPERTIES
        IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../android/mupdf/libs/${CMAKE_ANDROID_ARCH_ABI}/libmupdf_java.so
)
#---------------------------------------------------------------------------------------------------
#ofdpdfsigner.so


add_library(GMSSL_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/aes.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/aes_modes.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/asn1.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/base64.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/block_cipher.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/chacha20.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/cms.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/debug.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/des.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/digest.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/ec.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/gcm.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/gf128.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/hash_drbg.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/hex.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/hkdf.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/hmac.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/md5.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/pbkdf2.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/pem.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/pkcs8.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/rand.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/rand_unix.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/rc4.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/rdrand.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/rsa.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sha1.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sha256.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sha512.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_alg.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_blind.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_commit.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_elgamal.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_key.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_key_share.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_lib.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_recover.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm2_ring.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm3.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm3_hmac.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm3_kdf.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm4_aesni_avx.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm4_cl.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm4_common.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm4_enc.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm4_modes.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm4_setkey.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm9_alg.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm9_key.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/sm9_lib.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/tlcp.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/tls.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/tls12.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/tls13.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/tls_ext.c
        #../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/tls_trace.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/u_time.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/version.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_alg.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_cer.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_crl.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_ext.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_oid.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_req.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/x509_str.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/zuc.c
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/src/zuc_modes.c
)

target_include_directories(GMSSL_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include
)

target_compile_definitions(
        GMSSL_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------
add_library(fzfont_LIB_SRC OBJECT
       ../../../../../../ofdpdfsigner/ofdpdfsigner/fzfont/FZZFontCache.cpp
       ../../../../../../ofdpdfsigner/ofdpdfsigner/fzfont/FZZFontConfig.cpp
       ../../../../../../ofdpdfsigner/ofdpdfsigner/fzfont/FZZSystemFontCache.cpp
       ../../../../../../ofdpdfsigner/ofdpdfsigner/fzfont/FZZSystemFontList.cpp
       ../../../../../../ofdpdfsigner/ofdpdfsigner/fzfont/FZZTempFontCache.cpp
       ../../../../../../ofdpdfsigner/ofdpdfsigner/fzfont/FZZTempFontList.cpp
)

target_include_directories(fzfont_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        fzfont_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------
add_library(basic_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZAtomicInteger.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZBytes.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZConst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZMatrix.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZOFDFilesContainer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZPath.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZString.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZStringItem.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/FZZZipTracks.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/basic/tinyxml2.cpp
)

target_include_directories(basic_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        basic_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------
add_library(ofd_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDAnnotsDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDAttachsDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDBaseDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDDocDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDPageDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDResDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDSignDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDSignsDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDTagsDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/container/FZZOFDTemplateDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/draw/FZZOFDDrawContext.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/encrypt/FZZOFDUserCertEncryptor.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/encrypt/FZZOFDUserPasswordEncryptor.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFD.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDConst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDEncrypt.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDProtectSign.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDSignCleaner.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDSigner.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDValidator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDXMLElementObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/FZZOFDXMLFileObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/keyword/FZZKeyWordInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/keyword/FZZOFDFindKeyWord.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDAction.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDActions.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDGoto.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDGotoA.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDMovie.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDRegion.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDSound.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/action/FZZOFDURI.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnot_Annotation.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAnnPage.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/annotation/FZZOFDAppearance.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/annotation/FZZOFDRemark.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/attachment/FZZOFDAttachment.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDAbbreviatedData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDArc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDArea.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDAxialShd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDBaseGraphic.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDBorder.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDBottom.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDCellContent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDCGTransform.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDClip.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDClipArea.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDClips.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDClose.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDColor.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDCompositeObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDCubicBezier.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDDest.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDExtendData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDFileLoc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDGlyphs.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDGouraudShd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDImage.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDImageObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDLaGouraudShd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDLayer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDLeft.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDLine.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDMove.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlock.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDPageBlockType.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDPath.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDPathObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDPattern.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDPoint.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDQuadraticBezier.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDRadialShd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDRight.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDSegment.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDText.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDTextCode.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDTextObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDTop.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDZoom.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/common/FZZOFDZoomMode.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/customTags/FZZOFDCustomTag.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDAnnot.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDApplicationBox.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDBleedBox.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmark.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDBookmarks.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDCommonData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDContentBox.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDCropBox.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDDefaultCS.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDDocumentRes.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Annotations.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Attachments.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_CustomTags.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDDocument_Extensions.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDEdit.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDExport.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDHideMenubar.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDHideToolbar.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDHideWindowUI.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDMaxUnitID.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDOutlineElem.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDOutlines.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPageArea.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPageElem.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPageLayout.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPageMode.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPages.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPermission.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPhysicalBox.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPrint.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPrintScreen.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDPublicRes.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDSignature_Permission.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDTabDisplay.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDTemplatePage.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDValidPeriod.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDVPreferences.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/document/FZZOFDWatermark.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDDecryptSeedLoc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncParameter.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptDate.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptEntry.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEncryptScope.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDEntriesMapLoc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDExtendParams.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDUserInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/encrypt/FZZOFDUserInfoItem.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/entries/FZZOFDFile.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/entries/FZZOFDFileList.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/entries/FZZOFDSignedValueLoc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/extensions/FZZOFDExtension.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/extensions/FZZOFDProperty.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDAbstract.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDAuthor.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCover.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreationDate.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCreatorVersion.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCustomData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDCustomDatas.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocBody.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocBody_Signatures.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocID.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo_Keyword.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocInfo_Keywords.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocRoot.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDDocUsage.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDModDate.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDSubjec.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/ofd/FZZOFDTitle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/page/FZZOFDContent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/page/FZZOFDPageRes.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/page/FZZOFDTemplate.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDColorSpace.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDColorSpaces.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDCompositeGraphicUnits.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDCV.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDDrawParam.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDDrawParams.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDFont.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDFontFile.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDFonts.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDMultiMedia.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDMultiMedias.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDPalette.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDSubstitution.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDThumbnail.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/res/FZZOFDVectorG.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDCheckValue.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDMaxSignId.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameter.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDParameters.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDProvider.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDReference.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDReferences.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSeal.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignature.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignatureDateTime.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignatureMethod.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDSignedValue.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/signatures/FZZOFDStampAnnot.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/versions/FZZOFDVersion.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/ofdxmlelement/basicStructure/versions/FZZOFDVersions.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/FZZNumberFormatAtomicSignID.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/FZZStampAnnotEntity.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/FZZStandFormatAtomicSignID.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/signcontainer/FZZGBT35275DSContainer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/signcontainer/FZZGBT35275PKCS9DSContainer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/signcontainer/FZZSESV4Container.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/stamppos/FZZCuttingRideStampPos.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/stamppos/FZZNormalStampPos.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/stamppos/FZZRidingStampPos.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/verify/container/FZZGBT35275ValidateContainer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/verify/container/FZZSESV1ValidateContainer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/sign/verify/container/FZZSESV4ValidateContainer.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDAnnotationsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDAttachmentsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDCustomTagsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDDecryptSeedXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDDocumentXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDEncryptionsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDEntriesMapXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDEntriesXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDExtensionsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDPageAnnotXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDPageXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDResXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDSignaturesXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDSignatureXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/ofd/xmlfiles/FZZOFDXML.cpp
)

target_include_directories(ofd_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        ofd_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------


add_library(office_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZBaseDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZDocPropsDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZDocXDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZMediaDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZRelsDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZThemeDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/container/FZZWordDir.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/FZZDocXConst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/FZZDocXDocument.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/FZZFileMagic.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZAppXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZContentTypesXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZCoreXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZDocumentXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZDocumentXMLRels.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZEndnotesXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZFontTableXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZFooterXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZFootnotesXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZHeaderXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZNumberingXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZRelsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZSettingsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZStylesXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZThemeXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/docx/xmlfiles/FZZWebSettingsXML.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/FZZOfficeObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/FZZXMLElementObject.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/drawing/x2010/main/FZZA14UseLocalDpi.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/office/FZZOLock.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/thememl/x2012/main/FZZThemeFamily.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/FZZW10Wrap.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordml/FZZW14Alpha.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordml/FZZW14DocId.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordml/FZZW14SolidFill.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordml/FZZW14SrgbClr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordml/FZZW14TextFill.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSBodyPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSCNvCnPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSSpPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSStyle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2010/wordprocessingShape/FZZWPSWsp.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2012/wordml/FZZW15ChartTrackingRefBased.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/office/word/x2012/wordml/FZZW15DocId.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVF.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVFill.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVFormulas.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVGroup.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVImageData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVLine.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVPath.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVRect.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVShape.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVShapeType.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVStroke.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVTextbox.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/microsoft/vml/FZZVTextpath.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAalpha.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAAvLst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZABlip.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAClrScheme_Item.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAeffectLst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAEffectRef.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAeffectStyle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExt.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtLst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAExtraClrSchemeLst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFillRect.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFillRef.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfmtScheme_Item.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAFontRef.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfontScheme.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfontScheme_Item.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAfont_ea_cs.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgradFill.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphic.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAGraphicFrameLocks.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgs.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAgsLst.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAlin.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZALn.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZALnRef.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAlumMod.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAmiter.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAObjectDefaults.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAOff.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAouterShdw.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAprstDash.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstGeom.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAPrstTxWarp.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsatMod.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAschemeClr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAshade.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAsolidFill.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZASrgbClr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAStretch.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZASysClr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAthemeElements.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAtint.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/main/FZZAXfrm.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICBlipFill.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICCNvPicPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICCNvPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICNvPicPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICPic.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/picture/FZZPICSpPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPAlign.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPAnchor.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPCNvGraphicFramePr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPDocPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPEffectExtent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPExtent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPInline.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPositionH.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPositionV.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPPosOffset.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPSimplePos.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/drawingml/x2006/wordprocessingDrawing/FZZWPWrapNone.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCAlternateContent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCChoice.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/markup_compatibility/x2006/FZZMCFallback.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMBrkBin.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMBrkBinSub.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMDefJc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMDispDef.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMIntLim.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMLMargin.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMMathFont.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMMathPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMNaryLim.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMRMargin.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMSmallFrac.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/officeDocument/x2006/math/FZZMWrapIndent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/package/x2006/content_types/CTContentTypes_Default.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/package/x2006/content_types/CTContentTypes_Override.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/package/x2006/FZZRelationship.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAbstractNum.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAbstractNumId.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAdjustLineHeightInTable.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAllowPNG.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAltName.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWAttr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWB.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBackGround.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBalanceSingleByteDoubleByteWidth.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBasedOn.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBCs.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBody.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBordersDoNotSurroundFooter.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBordersDoNotSurroundHeader.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBottom.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWBr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCharacterSpacingControl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCharset.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWClrSchemeMapping.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWColor.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCols.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCompat.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCompatSetting.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWContinuationSeparator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWCr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDecimalSymbol.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDefaultTabStop.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDisplayHorizontalDrawingGridEvery.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDisplayVerticalDrawingGridEvery.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDocDefaults.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDocGrid.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDoNotExpandShiftReturn.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDoNotLeaveBackslashAlone.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawing.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWDrawingGridVerticalSpacing.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWEndnote.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWEvenAndOddHeaders.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFamily.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFldChar.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFont.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFooterReference.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFootnote.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWFramePr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWGridCol.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWGridSpan.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWHeaderReference.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWHyperlink.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWId.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWIlvl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideH.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInsideV.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWInstrText.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWJc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWKern.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLang.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLastRenderedPageBreak.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLatentStyles.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLeft.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWListSeparator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLsdException.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvlJc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWLvlText.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWMultiLevelType.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWName.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNoProof.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNsid.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNum.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumFmt.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumId.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWNumPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWOptimizeForBrowser.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWP.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPanose1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPBdr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPgMar.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPgSz.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPict.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPitch.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPosition.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPPrDefault.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWProofState.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWPStyle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWQFormat.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWR.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRFonts.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRight.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRPrDefault.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsid.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsidRoot.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRsids.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWRStyle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdt.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtContent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtEndPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSdtPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSectPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSemiHidden.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSeparator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWShd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSig.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSmartTag.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSmartTagPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpaceForUL.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSpacing.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStart.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWStyle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSuff.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSz.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWSzCS.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWT.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTab.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTabs.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTbl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblBorders.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblCellMar.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblCellSpacing.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblGrid.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblHeader.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblInd.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblLayout.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblLook.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblOverlap.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblpPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblStyle.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblStylePr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTblW.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTc.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcBorders.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTcW.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWThemeFontLang.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTitlePg.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTl2br.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTmpl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTop.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTr2bl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrHeight.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTrPr.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWTxbxContent.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWU.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUiPriority.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUlTrailSpace.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUnhideWhenUsed.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWUseFELayout.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVAlign.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVanish.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVertAlign.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWVMerge.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWW.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWWidowControl.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/office/ooxml/openxmlformats/wordprocessingml/x2006/main/FZZWZoom.cpp
)

target_include_directories(office_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        office_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------

add_library(font_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/FZZGenFont.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/utils.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/merger.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/stats.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/font_info.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/subsetter.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/font_assembler.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/subtly/character_predicate.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/truetype/loca_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/truetype/glyph_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/generic_table_builder.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/byte_array_table_builder.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/table_based_table_builder.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/header.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/font_data_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/subtable.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/eblc_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/bitmap_glyph.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/composite_bitmap_glyph.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/glyph_metrics.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/small_glyph_metrics.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/bitmap_size_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/ebdt_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/simple_bitmap_glyph.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/index_sub_table_format1.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/index_sub_table_format2.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/ebsc_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/index_sub_table_format3.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/index_sub_table_format4.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/big_glyph_metrics.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/index_sub_table_format5.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/bitmap_glyph_info.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/bitmap/index_sub_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/post_script_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/cmap_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/font_header_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/maximum_profile_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/horizontal_header_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/horizontal_device_metrics_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/name_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/os2_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/table/core/horizontal_metrics_table.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/port/memory_output_stream.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/port/lock.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/port/memory_input_stream.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/port/file_input_stream.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/font_output_stream.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/memory_byte_array.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/readable_font_data.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/font_input_stream.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/writable_font_data.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/growable_memory_byte_array.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/font_data.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/data/byte_array.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/tag.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/font_factory.cc
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/sfntly/font.cc
)

target_include_directories(font_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        font_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------

add_library(gm_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/crypto/FZZCert.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/crypto/FZZCertGenerator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/crypto/FZZGMCrypto.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/crypto/FZZKey.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/crypto/FZZKeyPair.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/data/FZZAuthenticatedAttributes.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/data/FZZContentInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/data/FZZSignedData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/data/FZZSignerInfo.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/data/FZZUnAuthenticatedAttributes.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/parse/FZZSESVersionHolder.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/parse/FZZVersionParser.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v1/FZZSESeal_V1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v1/FZZSES_ESPropertyInfo_V1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v1/FZZSES_SealInfo_V1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v1/FZZSES_Signature_V1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v1/FZZSES_SignInfo_V1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v1/FZZTBS_Sign_V1.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZCertDigestList.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZCertDigestObj.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZCertInfoList.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZExtData.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZExtensionDatas.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSESeal_V4.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSES_CertList.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSES_ESPictrueInfo_V4.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSES_ESPropertyInfo_V4.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSES_Header.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSES_SealInfo_V4.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZSES_Signature_V4.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/gm/ses/v4/FZZTBS_Sign_V4.cpp
)

target_include_directories(gm_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        gm_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------
add_library(converter_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/image/FZZOFDToImage.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/image/FZZPDFToImage.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/toofd/FZZOFDDevice.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/toofd/FZZPDF2OFD.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/topdf/FZZOFDToPDF.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/tosvg/FZZOFDToSvg.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/tosvg/FZZPDF2SVG.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/tosvg/FZZSVGDevice.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/utils/FZZCommonUtil.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/utils/FZZImageUtil.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/utils/FZZSVGUtil.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/converter/utils/FZZWaterMark.cpp
)

target_include_directories(converter_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        converter_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------
add_library(interface_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZCInterface.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZKeyWordRule.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/interface/FZZJNIInterface.cpp
)

target_include_directories(interface_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        interface_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------
add_library(pdfsign_LIB_SRC OBJECT
        ../../../../../../ofdpdfsigner/ofdpdfsigner/pdfsign/FZZPDF.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/pdfsign/FZZPDFCreator.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/pdfsign/FZZPDFSigner.cpp
        ../../../../../../ofdpdfsigner/ofdpdfsigner/pdfsign/FZZPkcs7_GM.cpp
)

target_include_directories(pdfsign_LIB_SRC PUBLIC
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include
)

target_compile_definitions(
        pdfsign_LIB_SRC
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)
#---------------------------------------------------------------------------------------------------

add_library( # Sets the name of the library.
        ofdpdfsigner
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        $<TARGET_OBJECTS:GMSSL_LIB_SRC>
        $<TARGET_OBJECTS:basic_LIB_SRC>
        $<TARGET_OBJECTS:fzfont_LIB_SRC>
        $<TARGET_OBJECTS:ofd_LIB_SRC>
        #$<TARGET_OBJECTS:office_LIB_SRC>
        $<TARGET_OBJECTS:font_LIB_SRC>
        $<TARGET_OBJECTS:gm_LIB_SRC>
        $<TARGET_OBJECTS:pdfsign_LIB_SRC>
        $<TARGET_OBJECTS:interface_LIB_SRC>
        $<TARGET_OBJECTS:converter_LIB_SRC>
)

target_compile_definitions(
        ofdpdfsigner
        PRIVATE
        -D_64_ -DLIBICONV_PLUG -DSFNTLY_EXPERIMENTAL -DSFNTLY_NO_EXCEPTION -DU_COMMON_IMPLEMENTATION -DMINIZIPNG -DU_DISABLE_RENAMING=1 -DU_DISABLE_VERSION_SUFFIX=1
)

target_include_directories(
        ofdpdfsigner
        PRIVATE
        ../../../../../../ofdpdfsigner/ofdpdfsigner/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/
        ../../../../../../ofdpdfsigner/ofdpdfsigner/font/sfntly/common/
        ../../../../../../ofdpdfsigner/thirdparty/zlib/
        ../../../../../../ofdpdfsigner/thirdparty/minizip-ng/
        ../../../../../../ofdpdfsigner/thirdparty/gmssl-v3/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf_lib/include/
        ../../../../../../ofdpdfsigner/thirdparty/mupdf/thirdparty/freetype/include

)

set_target_properties(ofdpdfsigner PROPERTIES
        CXX_FLAGS "-O3"
        LINK_FLAGS "-Wl,--gc-sections"
#        LINK_FLAGS "--gc-sections"
)

target_link_libraries( # Specifies the target library.
        ofdpdfsigner
        doczip
        mupdf
#        android
#        log
)
#---------------------------------------------------------------------------------------------------