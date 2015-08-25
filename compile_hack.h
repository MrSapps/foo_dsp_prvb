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
        return mData.size();
    }

    int get_channel_config()
    {
        return mChanConfig;
    }

    int get_srate()
    {
        return mRate;
    }

    int get_channels()
    {
        return mChans;
    }

    audio_sample* get_data()
    {
        return mData.data();
    }

    void set_data(audio_sample*, int, int ,int, int)
    {

    }

    void set_channels(int chans, int config)
    {
        mChans = chans;
        mChanConfig = config;
    }

    void set_sample_count(int count)
    {
        mData.resize(count);
    }

    void set_srate(int rate)
    {
        mRate = rate;
    }

    void grow_data_size(int size)
    {
        if (mData.size() < size)
        {
            mData.resize(size);
        }
    }

private:
    int mRate = 38700;
    int mChans = 2;
    int mChanConfig = channel_config_stereo;
    std::vector<float> mData;
};

class dsp_impl_base
{
public:
    audio_chunk* insert_chunk(int size)
    {
        return new audio_chunk;
    }
};

class dsp_preset
{
public:

};

class dsp
{
public:
};
