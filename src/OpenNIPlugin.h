﻿#ifndef OPENNIPLUGIN_H
#define OPENNIPLUGIN_H

#include "PluginBase.h"
#include <OpenNI.h>

namespace sensekit
{
    namespace openni
    {
        class OpenNIPlugin : public sensekit::PluginBase
        {
        public:
            OpenNIPlugin(SenseKitContext& context, PluginService& service)
                : sensekit::PluginBase(context, service) {}

            virtual void temp_update() override;

            // disable copying
            OpenNIPlugin(const OpenNIPlugin&) = delete;
            OpenNIPlugin& operator=(const OpenNIPlugin&) = delete;

        protected:
            virtual void on_initialize() override;
            virtual void on_cleanup() override;

        private:
            sensekit_status_t open_depth_stream();
            sensekit_status_t close_depth_stream();
            void set_new_buffer(buffer* nextBuffer);
            sensekit_status_t read_next_depth_frame(sensekit_depthframe_t* frame);

            ::openni::Device m_device;
            ::openni::VideoStream m_depthStream;
            ::openni::DeviceInfo m_deviceInfo;

            int m_frameIndex{0};

            buffer* m_currentBuffer{nullptr};
            sensekit_depthframe_t* m_currentFrame{nullptr};
            stream_handle m_handle{nullptr};
        };
    }
}

#endif /* OPENNIPLUGIN_H */