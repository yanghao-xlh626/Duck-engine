#pragma once

#include "dcpch.h"

#include "Duck/Core.h"
#include "Duck/Events/Event.h"

namespace Duck
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Duck Engine",
            unsigned int width = 1280,
            unsigned int height = 720)
            :Title(title), Width(width), Height(height)
        {
        }
    };

    class DUCK_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}