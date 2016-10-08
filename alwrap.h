// OpenAL wrapper for Windows
// by Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>.
// This file is public domain software (PDS).
#ifndef ALWRAP_H
#define ALWRAP_H            4   // Version 4

#define AL_NO_PROTOTYPES    1

#if defined(_MSC_VER)
    #include <alc.h>
    #include <al.h>
#elif defined(__APPLE__)
    #include <OpenAL/alc.h>
    #include <OpenAL/al.h>
#else
    #include <AL/al.h>
    #include <AL/alc.h>
#endif

#ifdef _WIN32

struct AlWrap
{
    AlWrap()
    {
        ZeroMemory(this, sizeof(*this));
    }

    ~AlWrap()
    {
        Unload();
    }

    bool Load()
    {
        return Load("OpenAL32.dll");
    }

    bool Load(const char *pszFileName)
    {
        if (m_hAL != NULL)
            return true;

        return Load(::LoadLibraryA(pszFileName));
    }

    bool Load(const wchar_t *pszFileName)
    {
        if (m_hAL != NULL)
            return true;

        return Load(::LoadLibraryW(pszFileName));
    }

    void Unload()
    {
        if (m_hAL)
            ::FreeLibrary(m_hAL);

        ZeroMemory(this, sizeof(*this));
    }

    template <typename TYPE>
    bool GetAddr(TYPE& fn, const char *name)
    {
        fn = (TYPE)::GetProcAddress(m_hAL, name);
        return fn != NULL;
    }

    bool Load(HINSTANCE hInstance)
    {
        if (m_hAL != NULL)
            return true;

        if (hInstance == NULL)
            return false;

        m_hAL = hInstance;
        if (GetAddr(m_alEnable, "alEnable") &&
            GetAddr(m_alDisable, "alDisable") &&
            GetAddr(m_alIsEnabled, "alIsEnabled") &&
            GetAddr(m_alGetString, "alGetString") &&
            GetAddr(m_alGetBooleanv, "alGetBooleanv") &&
            GetAddr(m_alGetIntegerv, "alGetIntegerv") &&
            GetAddr(m_alGetFloatv, "alGetFloatv") &&
            GetAddr(m_alGetDoublev, "alGetDoublev") &&
            GetAddr(m_alGetBoolean, "alGetBoolean") &&
            GetAddr(m_alGetInteger, "alGetInteger") &&
            GetAddr(m_alGetFloat, "alGetFloat") &&
            GetAddr(m_alGetDouble, "alGetDouble") &&
            GetAddr(m_alGetError, "alGetError") &&
            GetAddr(m_alIsExtensionPresent, "alIsExtensionPresent") &&
            GetAddr(m_alGetProcAddress, "alGetProcAddress") &&
            GetAddr(m_alGetEnumValue, "alGetEnumValue") &&
            GetAddr(m_alListenerf, "alListenerf") &&
            GetAddr(m_alListener3f, "alListener3f") &&
            GetAddr(m_alListenerfv, "alListenerfv") &&
            GetAddr(m_alListeneri, "alListeneri") &&
            GetAddr(m_alListener3i, "alListener3i") &&
            GetAddr(m_alListeneriv, "alListeneriv") &&
            GetAddr(m_alGetListenerf, "alGetListenerf") &&
            GetAddr(m_alGetListener3f, "alGetListener3f") &&
            GetAddr(m_alGetListenerfv, "alGetListenerfv") &&
            GetAddr(m_alGetListeneri, "alGetListeneri") &&
            GetAddr(m_alGetListener3i, "alGetListener3i") &&
            GetAddr(m_alGetListeneriv, "alGetListeneriv") &&
            GetAddr(m_alGenSources, "alGenSources") &&
            GetAddr(m_alDeleteSources, "alDeleteSources") &&
            GetAddr(m_alIsSource, "alIsSource") &&
            GetAddr(m_alSourcef, "alSourcef") &&
            GetAddr(m_alSource3f, "alSource3f") &&
            GetAddr(m_alSourcefv, "alSourcefv") &&
            GetAddr(m_alSourcei, "alSourcei") &&
            GetAddr(m_alSource3i, "alSource3i") &&
            GetAddr(m_alSourceiv, "alSourceiv") &&
            GetAddr(m_alGetSourcef, "alGetSourcef") &&
            GetAddr(m_alGetSource3f, "alGetSource3f") &&
            GetAddr(m_alGetSourcefv, "alGetSourcefv") &&
            GetAddr(m_alGetSourcei, "alGetSourcei") &&
            GetAddr(m_alGetSource3i, "alGetSource3i") &&
            GetAddr(m_alGetSourceiv, "alGetSourceiv") &&
            GetAddr(m_alSourcePlayv, "alSourcePlayv") &&
            GetAddr(m_alSourceStopv, "alSourceStopv") &&
            GetAddr(m_alSourceRewindv, "alSourceRewindv") &&
            GetAddr(m_alSourcePausev, "alSourcePausev") &&
            GetAddr(m_alSourcePlay, "alSourcePlay") &&
            GetAddr(m_alSourceStop, "alSourceStop") &&
            GetAddr(m_alSourceRewind, "alSourceRewind") &&
            GetAddr(m_alSourcePause, "alSourcePause") &&
            GetAddr(m_alSourceQueueBuffers, "alSourceQueueBuffers") &&
            GetAddr(m_alSourceUnqueueBuffers, "alSourceUnqueueBuffers") &&
            GetAddr(m_alGenBuffers, "alGenBuffers") &&
            GetAddr(m_alDeleteBuffers, "alDeleteBuffers") &&
            GetAddr(m_alIsBuffer, "alIsBuffer") &&
            GetAddr(m_alBufferData, "alBufferData") &&
            GetAddr(m_alBufferf, "alBufferf") &&
            GetAddr(m_alBuffer3f, "alBuffer3f") &&
            GetAddr(m_alBufferfv, "alBufferfv") &&
            GetAddr(m_alBufferi, "alBufferi") &&
            GetAddr(m_alBuffer3i, "alBuffer3i") &&
            GetAddr(m_alBufferiv, "alBufferiv") &&
            GetAddr(m_alGetBufferf, "alGetBufferf") &&
            GetAddr(m_alGetBuffer3f, "alGetBuffer3f") &&
            GetAddr(m_alGetBufferfv, "alGetBufferfv") &&
            GetAddr(m_alGetBufferi, "alGetBufferi") &&
            GetAddr(m_alGetBuffer3i, "alGetBuffer3i") &&
            GetAddr(m_alGetBufferiv, "alGetBufferiv") &&
            GetAddr(m_alDopplerFactor, "alDopplerFactor") &&
            GetAddr(m_alDopplerVelocity, "alDopplerVelocity") &&
            GetAddr(m_alSpeedOfSound, "alSpeedOfSound") &&
            GetAddr(m_alDistanceModel, "alDistanceModel") &&
            GetAddr(m_alcCreateContext, "alcCreateContext") &&
            GetAddr(m_alcMakeContextCurrent, "alcMakeContextCurrent") &&
            GetAddr(m_alcProcessContext, "alcProcessContext") &&
            GetAddr(m_alcSuspendContext, "alcSuspendContext") &&
            GetAddr(m_alcDestroyContext, "alcDestroyContext") &&
            GetAddr(m_alcGetCurrentContext, "alcGetCurrentContext") &&
            GetAddr(m_alcGetContextsDevice, "alcGetContextsDevice") &&
            GetAddr(m_alcOpenDevice, "alcOpenDevice") &&
            GetAddr(m_alcCloseDevice, "alcCloseDevice") &&
            GetAddr(m_alcGetError, "alcGetError") &&
            GetAddr(m_alcIsExtensionPresent, "alcIsExtensionPresent") &&
            GetAddr(m_alcGetProcAddress, "alcGetProcAddress") &&
            GetAddr(m_alcGetEnumValue, "alcGetEnumValue") &&
            GetAddr(m_alcGetString, "alcGetString") &&
            GetAddr(m_alcGetIntegerv, "alcGetIntegerv") &&
            GetAddr(m_alcCaptureOpenDevice, "alcCaptureOpenDevice") &&
            GetAddr(m_alcCaptureCloseDevice, "alcCaptureCloseDevice") &&
            GetAddr(m_alcCaptureStart, "alcCaptureStart") &&
            GetAddr(m_alcCaptureStop, "alcCaptureStop") &&
            GetAddr(m_alcCaptureSamples, "alcCaptureSamples"))
        {
            return true;
        }

        Unload();
        return false;
    }

    HINSTANCE                   m_hAL;

    // al
    LPALENABLE                  m_alEnable;
    LPALDISABLE                 m_alDisable;
    LPALISENABLED               m_alIsEnabled;
    LPALGETSTRING               m_alGetString;
    LPALGETBOOLEANV             m_alGetBooleanv;
    LPALGETINTEGERV             m_alGetIntegerv;
    LPALGETFLOATV               m_alGetFloatv;
    LPALGETDOUBLEV              m_alGetDoublev;
    LPALGETBOOLEAN              m_alGetBoolean;
    LPALGETINTEGER              m_alGetInteger;
    LPALGETFLOAT                m_alGetFloat;
    LPALGETDOUBLE               m_alGetDouble;
    LPALGETERROR                m_alGetError;
    LPALISEXTENSIONPRESENT      m_alIsExtensionPresent;
    LPALGETPROCADDRESS          m_alGetProcAddress;
    LPALGETENUMVALUE            m_alGetEnumValue;
    LPALLISTENERF               m_alListenerf;
    LPALLISTENER3F              m_alListener3f;
    LPALLISTENERFV              m_alListenerfv;
    LPALLISTENERI               m_alListeneri;
    LPALLISTENER3I              m_alListener3i;
    LPALLISTENERIV              m_alListeneriv;
    LPALGETLISTENERF            m_alGetListenerf;
    LPALGETLISTENER3F           m_alGetListener3f;
    LPALGETLISTENERFV           m_alGetListenerfv;
    LPALGETLISTENERI            m_alGetListeneri;
    LPALGETLISTENER3I           m_alGetListener3i;
    LPALGETLISTENERIV           m_alGetListeneriv;
    LPALGENSOURCES              m_alGenSources;
    LPALDELETESOURCES           m_alDeleteSources;
    LPALISSOURCE                m_alIsSource;
    LPALSOURCEF                 m_alSourcef;
    LPALSOURCE3F                m_alSource3f;
    LPALSOURCEFV                m_alSourcefv;
    LPALSOURCEI                 m_alSourcei;
    LPALSOURCE3I                m_alSource3i;
    LPALSOURCEIV                m_alSourceiv;
    LPALGETSOURCEF              m_alGetSourcef;
    LPALGETSOURCE3F             m_alGetSource3f;
    LPALGETSOURCEFV             m_alGetSourcefv;
    LPALGETSOURCEI              m_alGetSourcei;
    LPALGETSOURCE3I             m_alGetSource3i;
    LPALGETSOURCEIV             m_alGetSourceiv;
    LPALSOURCEPLAYV             m_alSourcePlayv;
    LPALSOURCESTOPV             m_alSourceStopv;
    LPALSOURCEREWINDV           m_alSourceRewindv;
    LPALSOURCEPAUSEV            m_alSourcePausev;
    LPALSOURCEPLAY              m_alSourcePlay;
    LPALSOURCESTOP              m_alSourceStop;
    LPALSOURCEREWIND            m_alSourceRewind;
    LPALSOURCEPAUSE             m_alSourcePause;
    LPALSOURCEQUEUEBUFFERS      m_alSourceQueueBuffers;
    LPALSOURCEUNQUEUEBUFFERS    m_alSourceUnqueueBuffers;
    LPALGENBUFFERS              m_alGenBuffers;
    LPALDELETEBUFFERS           m_alDeleteBuffers;
    LPALISBUFFER                m_alIsBuffer;
    LPALBUFFERDATA              m_alBufferData;
    LPALBUFFERF                 m_alBufferf;
    LPALBUFFER3F                m_alBuffer3f;
    LPALBUFFERFV                m_alBufferfv;
    LPALBUFFERI                 m_alBufferi;
    LPALBUFFER3I                m_alBuffer3i;
    LPALBUFFERIV                m_alBufferiv;
    LPALGETBUFFERF              m_alGetBufferf;
    LPALGETBUFFER3F             m_alGetBuffer3f;
    LPALGETBUFFERFV             m_alGetBufferfv;
    LPALGETBUFFERI              m_alGetBufferi;
    LPALGETBUFFER3I             m_alGetBuffer3i;
    LPALGETBUFFERIV             m_alGetBufferiv;
    LPALDOPPLERFACTOR           m_alDopplerFactor;
    LPALDOPPLERVELOCITY         m_alDopplerVelocity;
    LPALSPEEDOFSOUND            m_alSpeedOfSound;
    LPALDISTANCEMODEL           m_alDistanceModel;

    // alc
    LPALCCREATECONTEXT          m_alcCreateContext;
    LPALCMAKECONTEXTCURRENT     m_alcMakeContextCurrent;
    LPALCPROCESSCONTEXT         m_alcProcessContext;
    LPALCSUSPENDCONTEXT         m_alcSuspendContext;
    LPALCDESTROYCONTEXT         m_alcDestroyContext;
    LPALCGETCURRENTCONTEXT      m_alcGetCurrentContext;
    LPALCGETCONTEXTSDEVICE      m_alcGetContextsDevice;
    LPALCOPENDEVICE             m_alcOpenDevice;
    LPALCCLOSEDEVICE            m_alcCloseDevice;
    LPALCGETERROR               m_alcGetError;
    LPALCISEXTENSIONPRESENT     m_alcIsExtensionPresent;
    LPALCGETPROCADDRESS         m_alcGetProcAddress;
    LPALCGETENUMVALUE           m_alcGetEnumValue;
    LPALCGETSTRING              m_alcGetString;
    LPALCGETINTEGERV            m_alcGetIntegerv;
    LPALCCAPTUREOPENDEVICE      m_alcCaptureOpenDevice;
    LPALCCAPTURECLOSEDEVICE     m_alcCaptureCloseDevice;
    LPALCCAPTURESTART           m_alcCaptureStart;
    LPALCCAPTURESTOP            m_alcCaptureStop;
    LPALCCAPTURESAMPLES         m_alcCaptureSamples;
}; // struct AlWrap

inline ALWRAP *GetAlWrap(void)
{
    static AlWrap s_wrap;
    return &s_wrap;
}

#define alEnable GetAlWrap()->m_alEnable
#define alDisable GetAlWrap()->m_alDisable
#define alIsEnabled GetAlWrap()->m_alIsEnabled
#define alGetString GetAlWrap()->m_alGetString
#define alGetBooleanv GetAlWrap()->m_alGetBooleanv
#define alGetIntegerv GetAlWrap()->m_alGetIntegerv
#define alGetFloatv GetAlWrap()->m_alGetFloatv
#define alGetDoublev GetAlWrap()->m_alGetDoublev
#define alGetBoolean GetAlWrap()->m_alGetBoolean
#define alGetInteger GetAlWrap()->m_alGetInteger
#define alGetFloat GetAlWrap()->m_alGetFloat
#define alGetDouble GetAlWrap()->m_alGetDouble
#define alGetError GetAlWrap()->m_alGetError
#define alIsExtensionPresent GetAlWrap()->m_alIsExtensionPresent
#define alGetProcAddress GetAlWrap()->m_alGetProcAddress
#define alGetEnumValue GetAlWrap()->m_alGetEnumValue
#define alListenerf GetAlWrap()->m_alListenerf
#define alListener3f GetAlWrap()->m_alListener3f
#define alListenerfv GetAlWrap()->m_alListenerfv
#define alListeneri GetAlWrap()->m_alListeneri
#define alListener3i GetAlWrap()->m_alListener3i
#define alListeneriv GetAlWrap()->m_alListeneriv
#define alGetListenerf GetAlWrap()->m_alGetListenerf
#define alGetListener3f GetAlWrap()->m_alGetListener3f
#define alGetListenerfv GetAlWrap()->m_alGetListenerfv
#define alGetListeneri GetAlWrap()->m_alGetListeneri
#define alGetListener3i GetAlWrap()->m_alGetListener3i
#define alGetListeneriv GetAlWrap()->m_alGetListeneriv
#define alGenSources GetAlWrap()->m_alGenSources
#define alDeleteSources GetAlWrap()->m_alDeleteSources
#define alIsSource GetAlWrap()->m_alIsSource
#define alSourcef GetAlWrap()->m_alSourcef
#define alSource3f GetAlWrap()->m_alSource3f
#define alSourcefv GetAlWrap()->m_alSourcefv
#define alSourcei GetAlWrap()->m_alSourcei
#define alSource3i GetAlWrap()->m_alSource3i
#define alSourceiv GetAlWrap()->m_alSourceiv
#define alGetSourcef GetAlWrap()->m_alGetSourcef
#define alGetSource3f GetAlWrap()->m_alGetSource3f
#define alGetSourcefv GetAlWrap()->m_alGetSourcefv
#define alGetSourcei GetAlWrap()->m_alGetSourcei
#define alGetSource3i GetAlWrap()->m_alGetSource3i
#define alGetSourceiv GetAlWrap()->m_alGetSourceiv
#define alSourcePlayv GetAlWrap()->m_alSourcePlayv
#define alSourceStopv GetAlWrap()->m_alSourceStopv
#define alSourceRewindv GetAlWrap()->m_alSourceRewindv
#define alSourcePausev GetAlWrap()->m_alSourcePausev
#define alSourcePlay GetAlWrap()->m_alSourcePlay
#define alSourceStop GetAlWrap()->m_alSourceStop
#define alSourceRewind GetAlWrap()->m_alSourceRewind
#define alSourcePause GetAlWrap()->m_alSourcePause
#define alSourceQueueBuffers GetAlWrap()->m_alSourceQueueBuffers
#define alSourceUnqueueBuffers GetAlWrap()->m_alSourceUnqueueBuffers
#define alGenBuffers GetAlWrap()->m_alGenBuffers
#define alDeleteBuffers GetAlWrap()->m_alDeleteBuffers
#define alIsBuffer GetAlWrap()->m_alIsBuffer
#define alBufferData GetAlWrap()->m_alBufferData
#define alBufferf GetAlWrap()->m_alBufferf
#define alBuffer3f GetAlWrap()->m_alBuffer3f
#define alBufferfv GetAlWrap()->m_alBufferfv
#define alBufferi GetAlWrap()->m_alBufferi
#define alBuffer3i GetAlWrap()->m_alBuffer3i
#define alBufferiv GetAlWrap()->m_alBufferiv
#define alGetBufferf GetAlWrap()->m_alGetBufferf
#define alGetBuffer3f GetAlWrap()->m_alGetBuffer3f
#define alGetBufferfv GetAlWrap()->m_alGetBufferfv
#define alGetBufferi GetAlWrap()->m_alGetBufferi
#define alGetBuffer3i GetAlWrap()->m_alGetBuffer3i
#define alGetBufferiv GetAlWrap()->m_alGetBufferiv
#define alDopplerFactor GetAlWrap()->m_alDopplerFactor
#define alDopplerVelocity GetAlWrap()->m_alDopplerVelocity
#define alSpeedOfSound GetAlWrap()->m_alSpeedOfSound
#define alDistanceModel GetAlWrap()->m_alDistanceModel

#define alcCreateContext GetAlWrap()->m_alcCreateContext
#define alcMakeContextCurrent GetAlWrap()->m_alcMakeContextCurrent
#define alcProcessContext GetAlWrap()->m_alcProcessContext
#define alcSuspendContext GetAlWrap()->m_alcSuspendContext
#define alcDestroyContext GetAlWrap()->m_alcDestroyContext
#define alcGetCurrentContext GetAlWrap()->m_alcGetCurrentContext
#define alcGetContextsDevice GetAlWrap()->m_alcGetContextsDevice
#define alcOpenDevice GetAlWrap()->m_alcOpenDevice
#define alcCloseDevice GetAlWrap()->m_alcCloseDevice
#define alcGetError GetAlWrap()->m_alcGetError
#define alcIsExtensionPresent GetAlWrap()->m_alcIsExtensionPresent
#define alcGetProcAddress GetAlWrap()->m_alcGetProcAddress
#define alcGetEnumValue GetAlWrap()->m_alcGetEnumValue
#define alcGetString GetAlWrap()->m_alcGetString
#define alcGetIntegerv GetAlWrap()->m_alcGetIntegerv
#define alcCaptureOpenDevice GetAlWrap()->m_alcCaptureOpenDevice
#define alcCaptureCloseDevice GetAlWrap()->m_alcCaptureCloseDevice
#define alcCaptureStart GetAlWrap()->m_alcCaptureStart
#define alcCaptureStop GetAlWrap()->m_alcCaptureStop
#define alcCaptureSamples GetAlWrap()->m_alcCaptureSamples

#endif  // def _WIN32
#endif  // ndef ALWRAP_H
