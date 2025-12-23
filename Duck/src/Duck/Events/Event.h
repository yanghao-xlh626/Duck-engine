#pragma once

#include "dcpch.h"
#include "Duck/Core.h"

namespace Duck
{
	//单个事件模板
	enum class EventType
	{
		None=0,
		WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
	};

	//事件归类。
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication= BIT(0),
		EventCategoryInput      = BIT(1),
		EventCategoryKeyboard   = BIT(2),
		EventCategoryMouse      = BIT(3),
		EventCategoryMouseButton= BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override{return category;}

	class DUCK_API Event
	{
		friend class EventDispatcher;
	public:
		bool Handled = false;//标记这个事件是否被消费掉了(决定是否将这个事件向底层传递，比如点击事件发生，如果在按钮范围内就直接由按钮逻辑消费掉它）

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName();}
		
		inline bool IsInCategory(EventCategory category)//GetCategoryFlags是纯虚函，所以应该是派生出来返回自身的类型的。
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};


	inline std::ostream& operator<<(std::ostream& os,const Event& e)
	{
		return os<< e.ToString();
	}
}
