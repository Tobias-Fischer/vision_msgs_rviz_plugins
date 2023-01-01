#ifndef VISION_MSGS_RVIZ_PLUGINS_VISIBILITY_CONTROL_HPP
#define VISION_MSGS_RVIZ_PLUGINS_VISIBILITY_CONTROL_HPP

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
    #ifdef __GNUC__
        #define DETECTION_3D_DISPLAY_HPP_EXPORT __attribute__((dllexport))
        #define DETECTION_3D_DISPLAY_HPP_IMPORT __attribute__((dllimport))

        #define DETECTION_3D_ARRAY_DISPLAY_HPP_EXPORT __attribute__((dllexport))
        #define DETECTION_3D_ARRAY_DISPLAY_HPP_IMPORT __attribute__((dllimport))
    #else
        #define DETECTION_3D_DISPLAY_HPP_EXPORT __declspec(dllexport)
        #define DETECTION_3D_DISPLAY_HPP_IMPORT __declspec(dllimport)

        #define DETECTION_3D_ARRAY_DISPLAY_HPP_EXPORT __declspec(dllexport)
        #define DETECTION_3D_ARRAY_DISPLAY_HPP_IMPORT __declspec(dllimport)
    #endif

    #ifdef DETECTION_3D_DISPLAY_HPP_BUILDING_LIBRARY
        #define DETECTION_3D_DISPLAY_HPP_PUBLIC DETECTION_3D_DISPLAY_HPP_EXPORT
    #else
        #define DETECTION_3D_DISPLAY_HPP_PUBLIC DETECTION_3D_DISPLAY_HPP_IMPORT
    #endif
    #define DETECTION_3D_DISPLAY_HPP_PUBLIC_TYPE DETECTION_3D_DISPLAY_HPP_PUBLIC
    #define DETECTION_3D_DISPLAY_HPP_LOCAL

    #ifdef DETECTION_3D_ARRAY_DISPLAY_HPP_BUILDING_LIBRARY
    #define DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC DETECTION_3D_ARRAY_DISPLAY_HPP_EXPORT
    #else
        #define DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC DETECTION_3D_ARRAY_DISPLAY_HPP_IMPORT
    #endif
    #define DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC_TYPE DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC
    #define DETECTION_3D_ARRAY_DISPLAY_HPP_LOCAL

#else
    #define DETECTION_3D_DISPLAY_HPP_EXPORT __attribute__((visibility("default")))
    #define DETECTION_3D_DISPLAY_HPP_IMPORT

    #define DETECTION_3D_ARRAY_DISPLAY_HPP_EXPORT __attribute__((visibility("default")))
    #define DETECTION_3D_ARRAY_DISPLAY_HPP_IMPORT
    #if __GNUC__ >= 4
        #define DETECTION_3D_DISPLAY_HPP_PUBLIC __attribute__((visibility("default")))
        #define DETECTION_3D_DISPLAY_HPP_LOCAL __attribute__((visibility("hidden")))

        #define DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC __attribute__((visibility("default")))
        #define DETECTION_3D_ARRAY_DISPLAY_HPP_LOCAL __attribute__((visibility("hidden")))
    #else
        #define DETECTION_3D_DISPLAY_HPP_PUBLIC
        #define DETECTION_3D_DISPLAY_HPP_LOCAL

        #define DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC
        #define DETECTION_3D_ARRAY_DISPLAY_HPP_LOCAL
    #endif
    #define DETECTION_3D_DISPLAY_HPP_PUBLIC_TYPE
    #define DETECTION_3D_ARRAY_DISPLAY_HPP_PUBLIC_TYPE
#endif

#endif // VISION_MSGS_RVIZ_PLUGINS_VISIBILITY_CONTROL_HPP