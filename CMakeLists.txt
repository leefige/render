cmake_minimum_required(VERSION 3.7)
project(render)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -pthread -fopenmp")

set(SOURCE_FILES
        main.cpp int4.h float3.h float3.cpp Bezier.h Bezier.cpp
        Object.h Light.h Scene.h Sphere.cpp Sphere.h Render.h PathTracing.cpp PathTracing.h
        Color.h Camera.h Film.h PureColor.h Material.h Grain.h)

include_directories(
        D:\\\\Develop\\\\opencv\\\\build\\\\include
)

add_executable(render ${SOURCE_FILES})

set(OpenCV_LIBS
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_calib3d320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_calib3d_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_core320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_core_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_features2d320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_features2d_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_flann320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_flann_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_highgui320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_highgui_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_imgcodecs320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_imgcodecs_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_imgproc320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_imgproc_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_ml320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_ml_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_objdetect320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_objdetect_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_calib3d_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_core_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_features2d_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_imgcodecs_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_imgproc_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_objdetect_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_photo_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_stitching_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_superres_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_videoio_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_perf_video_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_photo320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_photo_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_shape320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_shape_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_stitching320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_stitching_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_superres320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_superres_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_calib3d_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_core_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_features2d_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_flann_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_highgui_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_imgcodecs_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_imgproc_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_ml_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_objdetect_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_photo_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_shape_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_stitching_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_superres_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_videoio_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_test_video_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_ts320.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_ts_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_video320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_videoio320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_videoio_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_videostab320.dll.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_videostab_pch_dephelp.a"
        "D:\\\\Develop\\\\opencv\\\\build\\\\x86\\\\mingw\\\\lib\\\\libopencv_video_pch_dephelp.a"
        )

target_link_libraries(render ${OpenCV_LIBS})

