# 1
# Set bash script to exit immediately if any commands fail.
set -e

echo "Build Dir", ${BUILD_DIR}

cd ${BUILD_DIR}
cd ..
OUT_LIB_NAME="libGuidoARlib-iOS"
LIB_NAME="libguidoar"


# define output folder environment variable
#UNIVERSAL_OUTPUTFOLDER=${BUILD_DIR}/${CONFIGURATION}-universal
UNIVERSAL_OUTPUTFOLDER=${BUILD_DIR}/guidoarlib

# make sure the output directory exists
mkdir -p "${UNIVERSAL_OUTPUTFOLDER}"
mkdir -p "${UNIVERSAL_OUTPUTFOLDER}/${CONFIGURATION}"

# Step 1. Build Device and Simulator versions
xcodebuild -target guidoar ONLY_ACTIVE_ARCH=NO -configuration ${CONFIGURATION} -sdk iphoneos  BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}"
xcodebuild -target guidoar -configuration ${CONFIGURATION} -sdk iphonesimulator -arch i386 -arch x86_64 BUILD_DIR="${BUILD_DIR}" BUILD_ROOT="${BUILD_ROOT}"


# Step 2. Create universal binary file using lipo
lipo -create -output "${UNIVERSAL_OUTPUTFOLDER}/${CONFIGURATION}/${OUT_LIB_NAME}.a" "${BUILD_DIR}/${CONFIGURATION}-iphoneos/${LIB_NAME}.a" "${BUILD_DIR}/${CONFIGURATION}-iphonesimulator/${LIB_NAME}.a"

# Last touch. copy the header files. Just for convenience
cp "${BUILD_DIR}/../libguidoar/libguidoar.h" "${UNIVERSAL_OUTPUTFOLDER}/"