
/*
==========================================
  Copyright (c) 2011-2020 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#pragma once

#include "dynamic_static/core/defines.hpp"

#include <chrono>
#include <ctime>
#include <ratio>

namespace dst {

/**
Alias for std::chrono::system_clock
*/
using SystemClock = std::chrono::system_clock;

/**
Alias for std::chrono::steady_clock
*/
using SteadyClock = std::chrono::steady_clock;

/**
Alias for std::chrono::high_resolution_clock
*/
using HighResolutionClock = std::chrono::high_resolution_clock;

/**
Alias for std::chrono::duration<Rep, std::ratio<3600>>
@param <CountType = double> The type of value of this Hours<> object's count() member
*/
template <typename CountType = double>
using Hours = std::chrono::duration<CountType, std::ratio<3600>>;

/**
Alias for std::chrono::duration<Rep, std::ratio<60>>
@param <CountType = double> The type of value of this Minutes<> object's count() member
*/
template <typename CountType = double>
using Minutes = std::chrono::duration<CountType, std::ratio<60>>;

/**
Alias for std::chrono::duration<Rep, std::ratio<1>>
@param <CountType = double> The type of value of this Seconds<> object's count() member
*/
template <typename CountType = double>
using Seconds = std::chrono::duration<CountType, std::ratio<1>>;

/**
Alias for std::chrono::duration<Rep, std::milli>
@param <CountType = double> The type of value of this Milliseconds<> object's count() member
*/
template <typename CountType = double>
using Milliseconds = std::chrono::duration<CountType, std::milli>;

/**
Alias for std::chrono::duration<Rep, std::micro>
@param <CountType = double> The type of value of this Microseconds<> object's count() member
*/
template <typename CountType = double>
using Microseconds = std::chrono::duration<CountType, std::micro>;

/**
Alias for std::chrono::duration<Rep, std::nano>
@param <CountType = double> The type of value of this Nanoseconds<> object's count() member
*/
template <typename CountType = double>
using Nanoseconds = std::chrono::duration<CountType, std::nano>;

/**
Alias for std::chrono::time_point<ClockType, DurationType>
@param <ClockType = HighResolutionClock> The type of clock to use for this TimePoint<>
@param <DurationType = Nanoseconds<>> The type of std::chrono::duration<> to use for this TimePoint<>
*/
template <typename ClockType = HighResolutionClock, typename DurationType = Nanoseconds<>>
using TimePoint = std::chrono::time_point<ClockType, DurationType>;

/**
Converts a given std::chrono::duration<> to a specified std::chrono::duration<> type
@param <ToDurationType> The type of std::chrono::duration<> to convert the given std::chrono::duration<> to
@param <FromDurationType> The type of std::chrono::duration<> to convert
@param [in] duration The std::chrono::duration<> to convert
@return The converted std::chrono::duration<>
*/
template <typename ToDurationType, typename FromDurationType>
inline constexpr ToDurationType duration_cast(const FromDurationType& duration)
{
    return std::chrono::duration_cast<ToDurationType>(duration);
}

/**
Represents the date and time of a specific moment
*/
struct DateTime final
{
public:
    /**
    Enumerates calender months
    */
    enum class Month
    {
        January   = 1,
        February  = 2,
        March     = 3,
        April     = 4,
        May       = 5,
        June      = 6,
        July      = 7,
        August    = 8,
        September = 9,
        October   = 10,
        November  = 11,
        December  = 12,
    };

    /**
    Enumerates calender days
    */
    enum class Day
    {
        Sunday    = 1,
        Monday    = 2,
        Tuesday   = 3,
        Wednesday = 4,
        Thursday  = 5,
        Friday    = 6,
        Saturday  = 7,
    };

    /**
    Gets the DateTime for the current moment
    @return The DateTime for the current moment
    */
    inline static DateTime now()
    {
        DateTime dateTime { };
        auto systemClockNow = SystemClock::to_time_t(SystemClock::now());
        const tm* pLocalTime = nullptr;
        #ifdef DYNAMIC_STATIC_PLATFORM_WINDOWS
        tm localTime { };
        auto error = localtime_s(&localTime, &systemClockNow);
        if (!error) {
            pLocalTime = &localTime;
        }
        #else
        pLocalTime = localtime(&systemClockNow);
        #endif // DYNAMIC_STATIC_PLATFORM_WINDOWS
        if (pLocalTime) {
            dateTime.year = 1900 + pLocalTime->tm_year;
            dateTime.month = (Month)(1 + pLocalTime->tm_mon);
            dateTime.dayOfTheMonth = pLocalTime->tm_mday;
            dateTime.dayOfTheWeek = (Day)(1 + pLocalTime->tm_wday);
            dateTime.hour = pLocalTime->tm_hour;
            dateTime.minute = pLocalTime->tm_min;
            dateTime.second = pLocalTime->tm_sec;
        }
        return dateTime;
    }

    int year { };          //!< This DateTime object's year
    Month month { };       //!< This DateTime object's calender month
    int dayOfTheMonth { }; //!< This DateTime object's numeric day of the month
    Day dayOfTheWeek { };  //!< This DateTime object's calender day of the week
    int hour { };          //!< This DateTime object's hour
    int minute { };        //!< This DateTime object's minute
    int second { };        //!< This DateTime object's second
};

/**
Provides facilities for getting the std::chrono::duration<> representation of the delta between moments
*/
class Timer final
{
public:
    /**
    Gets the std::chrono::duration<> representation of the delta from when this Timer was constructed, or from the last call to reset(), to the current moment
    @param <Duration = Milliseconds<>> The type of std::chrono::duration<> to get
    @return The std::chrono::duration<> representation of the delta from when this Timer was constructed, or from the last call to reset(), to the current moment
    */
    template <typename DurationType = Milliseconds<>>
    inline auto total() const
    {
        return duration_cast<DurationType>(HighResolutionClock::now() - mBegin).count();
    }

    /**
    Resets this Timer
    */
    inline void reset()
    {
        mBegin = HighResolutionClock::now();
    }

private:
    TimePoint<> mBegin { HighResolutionClock::now() };
};

/**
Provides facilities for getting the std::chrono::duration<> representation of the delta between snapshots of moments
*/
class Clock final
{
public:
    /**
    Gets the TimePoint<> of the moment of this Clock object's last call to update()
    @return The TimePoint<> of the moment of this Clock object's last call to update()
    */
    inline const TimePoint<>& current() const
    {
        return mCurrent;
    }

    /**
    Gets the std::chrono::duration<> of the delta between this Clock object's last call to update() and the previous call to update()
    @return The std::chrono::duration<> of the delta between this Clock object's last call to update() and the previous call to update()
    */
    template <typename DurationType>
    inline auto elapsed() const
    {
        return duration_cast<DurationType>(mCurrent - mPrevious).count();
    }

    /**
    Gets the std::chrono::duration<> of the delta between this Clock object's last call to update() and the moment of its construction or the last call to reset()
    @return The std::chrono::duration<> of the delta between this Clock object's last call to update() and the moment of its construction or the last call to reset()
    */
    template <typename DurationType>
    inline auto total() const
    {
        return duration_cast<DurationType>(mCurrent - mBegin).count();
    }

    /**
    Updates this Clock object
    */
    inline void update()
    {
        mPrevious = mCurrent;
        mCurrent = HighResolutionClock::now();
    }

    /**
    Resets this Clock object
    */
    inline void reset()
    {
        mBegin = HighResolutionClock::now();
        mCurrent = mBegin;
        mPrevious = mBegin;
    }

private:
    TimePoint<> mBegin { HighResolutionClock::now() };
    TimePoint<> mPrevious { mBegin };
    TimePoint<> mCurrent { mBegin };
};

} // namespace dst
