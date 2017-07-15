
/*
================================================================================

  MIT License

  Copyright (c) 2016 Dynamic_Static

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

================================================================================
*/

#pragma once

#include "Dynamic_Static/Core/Defines.hpp"

#include <ratio>
#include <chrono>

namespace Dynamic_Static
{
    /**
     * Represents the system wide real time wall clock.
     */
    typedef std::chrono::system_clock SystemClock;

    /**
     * Represents a monotonic clock.
     * \n NOTE : This clock is not related to wall clock time (for example, it can be time since last reboot)
     */
    typedef std::chrono::steady_clock SteadyClock;

    /**
     * Represents the clock with the smallest tick period provided by the implementation.
     */
    typedef std::chrono::high_resolution_clock HighResolutionClock;

    /**
     * Represents a time interval.
     * @param <TickType> This Duration's tick type
     * @param <Period>   This Duration's period in terms of a ratio of seconds
     */
    template <typename TickType, typename Period>
    using Duration = std::chrono::duration<TickType, Period>;

    /**
     * Represents an hour time interval.
     * @param <TickType> This hour's tick type (optional = double)
     */
    template <typename TickType = double>
    using Hour = Duration<TickType, std::ratio<3600>>;

    /**
     * Represents a minute time interval.
     * @param <TickType> This minute's tick type (optional = double)
     */
    template <typename TickType = double>
    using Minute = Duration<TickType, std::ratio<60>>;

    /**
     * Represents a second time interval.
     * @param <TickType> This second's tick type (optional = double)
     */
    template <typename TickType = double>
    using Second = Duration<TickType, std::ratio<1>>;

    /**
     * Represents a millisecond time interval.
     * @param <TickType> This millisecond's tick type (optional = double)
     */
    template <typename TickType = double>
    using Millisecond = Duration<TickType, std::milli>;

    /**
     * Represents a microsecond time interval.
     * @param <TickType> This microsecond's tick type (optional = double)
     */
    template <typename TickType = double>
    using Microsecond = Duration<TickType, std::micro>;

    /**
     * Represents a nanosecond time interval.
     * @param <TickType> This Nanosecond's tick type (optional = double)
     */
    template <typename TickType = double>
    using Nanosecond = Duration<TickType, std::nano>;

    /**
     * Converts a given Duration from one type to another.
     * @param <ToType>      The Duration type to convert to
     * @param <FromType>    The Duration type to convert from
     * @param [in] duration The Duration to convert
     * @return The converted Duration
     */
    template <typename ToType, typename FromType>
    constexpr ToType duration_cast(const FromType& duration)
    {
        return std::chrono::duration_cast<ToType>(duration);
    }

    /**
     * Represents a point in time.
     * @param <ClockType>    This TimePoint's clock type    (optional = HighResolutionClock)
     * @param <DurationType> This TimePoint's Duration type (optional = Nanosecond<>)
     */
    template <typename ClockType = HighResolutionClock, typename DurationType = Nanosecond<>>
    using TimePoint = std::chrono::time_point<HighResolutionClock, DurationType>;
} // namespace Dynamic_Static

namespace Dynamic_Static
{
    /**
     * Represents a running time keeper.
     */
    class Timer final
    {
    private:
        TimePoint<> mBegin { HighResolutionClock::now() };

    public:
        /**
         * Gets this Timer's total run time.
         * @param <DurationType> The type of Duration to use
         * @return This Clock's total run time
         */
        template <typename DurationType>
        auto total() const -> decltype(&DurationType::count())
        {
            return duration_cast<DurationType>(HighResolutionClock::now() - mBegin).count();
        }

        /**
         * Resets this Timer.
         */
        void reset()
        {
            mBegin = HighResolutionClock::now();
        }
    };
} // namespace Dynamic_Static

namespace Dynamic_Static
{
    /**
     * Represents a periodic time keeper.
     */
    class Clock final
    {
    private:
        TimePoint<> mBegin { HighResolutionClock::now() };
        TimePoint<> mCurrent { mBegin };
        TimePoint<> mPrevious { mBegin };

    public:
        /**
         * Gets this Clock's current TimePoint.
         * @return This Clock's current TimePoint
         */
        const TimePoint<>& current() const
        {
            return mCurrent;
        }

        /**
         * Gets this Clock's total run time.
         * @param <DurationType> The type of Duration to use
         * @return This Clock's total run time
         */
        template <typename DurationType>
        auto total() const -> decltype(&DurationType::count())
        {
            return duration_cast<DurationType>(mCurrent - mBegin).count();
        }

        /**
         * Gets the amount of time elapsed since this Clock's last update.
         * @param <DurationType> The type of Duration to use
         * @return This Clock's elapsed time
         */
        template <typename DurationType>
        auto elapsed() const -> decltype(&DurationType::count())
        {
            return dynamic_cast<DurationType>(mCurrent - mPrevious).count();
        }

        /**
         * Updates this Clock.
         */
        void update()
        {
            mPrevious = mCurrent;
            mCurrent = HighResolutionClock::now();
        }
    };
} // namespace Dynamic_Static