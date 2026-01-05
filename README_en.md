# ofdpdfsigner  
A powerful OFD/PDF signing tool that supports format conversion, document encryption,electronic signature, digital seal, and integrity protection.  

✍️ Signature Features:  
Electronic Seal : Supports electronic seals by position, across pages (seam stamps), and by keyword for both OFD and PDF formats.  

Document Encryption:  

PDF: Supports standard PDF document encryption.  

OFD: Supports national standard (China) document encryption.  

Integrity Protection:  

OFD: Supports integrity protection based on Chinese national standards.  

Encryption & Signature Algorithms:  

Supports SM2, SM3, SM4 algorithms.  

Supports integration with Ukey, hardware cryptographic modules, and mobile-side secondary password modules via callback functions.  

## 🧑‍💻 Development Standards:  
C0119: Unified eSeal technical requirements for the National Government Service Platform  

GB/T 38540-2020: Information Security Technology — Cryptographic Technical Specifications for Secure Electronic Signatures  

GBT 33190-2016: Format Document for Electronic Document Storage and Exchange  

GM/T 0099-2020: Technical Specifications for Cryptographic Application in OFD Format Documents  

GM/T 0031-2014: Cryptographic Technical Specifications for Secure Electronic Signatures  

## 🔄 Format Conversion Support:  
OFD ➝ PDF  

OFD ➝ PNG  

OFD ➝ JPEG  

OFD ➝ SVG  

PDF ➝ OFD  

PDF ➝ PNG  

PDF ➝ JPEG  

PDF ➝ SVG  

## 🖥️ Cross-Platform Support:  
Desktop: Windows, Linux, macOS  

Mobile: iOS, Android, HarmonyOS  

🧱 Development Language:  
Core: C++  

Interfaces provided:  

C Interface  

Java Interface (JNI for Android and Java)  

TypeScript Interface (for HarmonyOS)  

Swift Interface (for iOS)  

## 📬 Contact  
For any needs or suggestions, feel free to reach out: fzzfzz2025@163.com  

## 📜 License  
This project is licensed under the Business Source License 1.1 (BSL-1.1).  

✅ Free for personal, educational, and non-commercial use  
❌ Commercial or production use requires a commercial license  

You can read the full license terms in the LICENSE file.  

## 💼 Commercial License  
If you intend to use this project in a commercial environment (e.g., internal business tools, customer-facing products, paid services, etc.), you must obtain a commercial license.
📧 Email: fzzfzz2025@163.com  

## 🧾 License Badge  
License: BSL-1.1  

# Linux and Windows Build

For Visual C++ (VC) builds and Linux builds, please refer to the Android build files and create the VC project and Linux CMake files yourself.
The codebase itself is cross-platform and does not require platform-specific modifications.

# Directory Structure

## DocReader
A PC-side demo tool developed with Qt.
It can run on Linux, Windows, and macOS.

## harmonyos
Build and demo for the ofdpdfsigner library on Huawei HarmonyOS.

## android
Build and demo for the ofdpdfsigner library on Android.

## ios
Build and demo for the ofdpdfsigner library on iOS.

## java
Build and demo of the ofdpdfsigner library in Java, intended for server-side use.

## ofdpdfsigner
The source code of ofdpdfsigner, along with the macOS build project.

## webext
Browser extensions compatible with IE6 and later, Firefox, Chrome, and other browsers.

## 演示 (Demos)
Demo videos and images.
