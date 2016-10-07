////////////////////////////////////////////////////////
ALWRAP --- OpenAL wrapper for Windows
by Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
////////////////////////////////////////////////////////

This library wraps OpenAL of a sound library.
It can control the timing of loading/unloading the OpenAL.

    GetAlWrap()->Load("OpenAL32.dll");
    ...
    alEnable(...);
    ...
    GetAlWrap()->Unload();
