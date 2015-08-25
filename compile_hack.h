#pragma once

#include <windows.h>
#include <functional>
#include <memory>
#include <vector>

typedef std::vector<struct audio_chunk*> dsp_chunk_list_impl;

typedef std::function<void()> abort_callback;
typedef float audio_sample;

struct audio_chunk
{
    enum
    {
        channel_front_left,
        channel_front_right,
        channel_back_left,
        channel_back_right,

        channel_config_mono,
        channel_config_stereo,
        channel_config_4point0
    };

    unsigned int get_sample_count()
    {
        return 0;
    }

    int get_channel_config()
    {
        return 0;
    }

    int get_srate()
    {
        return 0;
    }

    int get_channels()
    {
        return 0;
    }

    audio_sample* get_data()
    {
        return nullptr;
    }

    void set_data(audio_sample*, int, int ,int, int)
    {

    }

    void set_channels(int, int)
    {

    }

    void set_sample_count(int)
    {

    }

    void set_srate(int)
    {

    }

    void grow_data_size(int size)
    {
        // if size() < size then resize
    }
};

class dsp_impl_base
{
public:

};

class dsp_preset
{
public:

};

class dsp
{
public:
};
