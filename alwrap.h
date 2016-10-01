// OpenAL wrapper for Windows
// by Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>.
// This file is public domain software (PDS).
#ifndef ALWRAP_H
#define ALWRAP_H

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

struct AlWrap
{
    AlWrap()
    {
        memset(this, 0, sizeof(*this));
    }

    template <typename TYPE>
    bool GetAddr(TYPE& fn, const char *name)
    {
        FARPROC fn = ::GetProcAddress(m_hInst, name);
        fn = (TYPE)fn;
        return fn != NULL;
    }

    bool Load()
    {
        if (m_hInst != NULL)
            return true;

        m_hInst = ::LoadLibraryA("OpenAL32.dll");
        if (m_hInst == NULL)
            return false;

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
            GetAddr(m_alDistanceModel, "alDistanceModel"))
        {
            return true;
        }

        Unload();
        return false;
    }

    void Unload()
    {
        ::FreeLibrary(m_hInst);
        memset(this, 0, sizeof(*this));
    }

    ~AlWrap()
    {
        Unload();
    }

    HINSTANCE                   m_hInst;

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
};

inline AlWrap *GetAlWrap(void)
{
    static AlWrap s_wrap;
    return &s_wrap;
}

#define alEnable GetAlWrap()->alEnable
#define alDisable GetAlWrap()->alDisable
#define alIsEnabled GetAlWrap()->alIsEnabled
#define alGetString GetAlWrap()->alGetString
#define alGetBooleanv GetAlWrap()->alGetBooleanv
#define alGetIntegerv GetAlWrap()->alGetIntegerv
#define alGetFloatv GetAlWrap()->alGetFloatv
#define alGetDoublev GetAlWrap()->alGetDoublev
#define alGetBoolean GetAlWrap()->alGetBoolean
#define alGetInteger GetAlWrap()->alGetInteger
#define alGetFloat GetAlWrap()->alGetFloat
#define alGetDouble GetAlWrap()->alGetDouble
#define alGetError GetAlWrap()->alGetError
#define alIsExtensionPresent GetAlWrap()->alIsExtensionPresent
#define alGetProcAddress GetAlWrap()->alGetProcAddress
#define alGetEnumValue GetAlWrap()->alGetEnumValue
#define alListenerf GetAlWrap()->alListenerf
#define alListener3f GetAlWrap()->alListener3f
#define alListenerfv GetAlWrap()->alListenerfv
#define alListeneri GetAlWrap()->alListeneri
#define alListener3i GetAlWrap()->alListener3i
#define alListeneriv GetAlWrap()->alListeneriv
#define alGetListenerf GetAlWrap()->alGetListenerf
#define alGetListener3f GetAlWrap()->alGetListener3f
#define alGetListenerfv GetAlWrap()->alGetListenerfv
#define alGetListeneri GetAlWrap()->alGetListeneri
#define alGetListener3i GetAlWrap()->alGetListener3i
#define alGetListeneriv GetAlWrap()->alGetListeneriv
#define alGenSources GetAlWrap()->alGenSources
#define alDeleteSources GetAlWrap()->alDeleteSources
#define alIsSource GetAlWrap()->alIsSource
#define alSourcef GetAlWrap()->alSourcef
#define alSource3f GetAlWrap()->alSource3f
#define alSourcefv GetAlWrap()->alSourcefv
#define alSourcei GetAlWrap()->alSourcei
#define alSource3i GetAlWrap()->alSource3i
#define alSourceiv GetAlWrap()->alSourceiv
#define alGetSourcef GetAlWrap()->alGetSourcef
#define alGetSource3f GetAlWrap()->alGetSource3f
#define alGetSourcefv GetAlWrap()->alGetSourcefv
#define alGetSourcei GetAlWrap()->alGetSourcei
#define alGetSource3i GetAlWrap()->alGetSource3i
#define alGetSourceiv GetAlWrap()->alGetSourceiv
#define alSourcePlayv GetAlWrap()->alSourcePlayv
#define alSourceStopv GetAlWrap()->alSourceStopv
#define alSourceRewindv GetAlWrap()->alSourceRewindv
#define alSourcePausev GetAlWrap()->alSourcePausev
#define alSourcePlay GetAlWrap()->alSourcePlay
#define alSourceStop GetAlWrap()->alSourceStop
#define alSourceRewind GetAlWrap()->alSourceRewind
#define alSourcePause GetAlWrap()->alSourcePause
#define alSourceQueueBuffers GetAlWrap()->alSourceQueueBuffers
#define alSourceUnqueueBuffers GetAlWrap()->alSourceUnqueueBuffers
#define alGenBuffers GetAlWrap()->alGenBuffers
#define alDeleteBuffers GetAlWrap()->alDeleteBuffers
#define alIsBuffer GetAlWrap()->alIsBuffer
#define alBufferData GetAlWrap()->alBufferData
#define alBufferf GetAlWrap()->alBufferf
#define alBuffer3f GetAlWrap()->alBuffer3f
#define alBufferfv GetAlWrap()->alBufferfv
#define alBufferi GetAlWrap()->alBufferi
#define alBuffer3i GetAlWrap()->alBuffer3i
#define alBufferiv GetAlWrap()->alBufferiv
#define alGetBufferf GetAlWrap()->alGetBufferf
#define alGetBuffer3f GetAlWrap()->alGetBuffer3f
#define alGetBufferfv GetAlWrap()->alGetBufferfv
#define alGetBufferi GetAlWrap()->alGetBufferi
#define alGetBuffer3i GetAlWrap()->alGetBuffer3i
#define alGetBufferiv GetAlWrap()->alGetBufferiv
#define alDopplerFactor GetAlWrap()->alDopplerFactor
#define alDopplerVelocity GetAlWrap()->alDopplerVelocity
#define alSpeedOfSound GetAlWrap()->alSpeedOfSound
#define alDistanceModel GetAlWrap()->alDistanceModel

#endif  // ndef ALWRAP_H
