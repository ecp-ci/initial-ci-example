//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// 1Dheat_exports.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#ifndef 1DHEAT_EXPORTS_H
#define 1DHEAT_EXPORTS_H

//-----------------------------------------------------------------------------
// -- define proper lib exports for various platforms -- 
//-----------------------------------------------------------------------------
#if defined(_WIN32)
    #if defined(WIN32_SHARED_LIBS)
        #if defined(1DHEAT_EXPORTS) || defined(1Dheat_EXPORTS)
            #define 1DHEAT_API __declspec(dllexport)
        #else
            #define 1DHEAT_API __declspec(dllimport)
        #endif
    #else
        #define 1DHEAT_API /* not needed for static on windows */
    #endif
    #if defined(_MSC_VER)
        /* Turn off warning about lack of DLL interface */
        #pragma warning(disable:4251)
        /* Turn off warning non-dll class is base for dll-interface class. */
        #pragma warning(disable:4275)
        /* Turn off warning about identifier truncation */
        #pragma warning(disable:4786)
    #endif
#else
# if __GNUC__ >= 4 && (defined(1DHEAT_EXPORTS) || defined(1Dheat_EXPORTS))
#   define 1DHEAT_API __attribute__ ((visibility("default")))
# else
#   define 1DHEAT_API /* hidden by default */
# endif
#endif

#endif
