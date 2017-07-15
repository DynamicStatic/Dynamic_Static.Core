
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
#include "Dynamic_Static/Core/NonCopyable.hpp"

#include <vector>
#include <utility>
#include <algorithm>

namespace Dynamic_Static
{
    namespace detail
    {
        template <typename ...Args>
        class Event;
    } // namespace detail
} // namespace Dynamic_Static

namespace Dynamic_Static
{
    namespace detail
    {
        template <typename ...Args>
        class Subscribable
            : NonCopyable
        {
            friend Event<Args...>;
        private:
            struct DefferedCommand
            {
                enum class Type
                {
                    Clear,
                    Subscribe,
                    Unsubscribe,
                };

                Type type;
                Subscribable<Args...>* subscription;
            };

        private:
            typedef typename std::vector<Subscribable<Args...>*>::iterator Iterator;
            std::vector<Subscribable<Args...>*> mSubscriptions;
            std::vector<DefferedCommand> mDefferedCommands;
            bool mLocked { false };

        protected:
            Subscribable() = default;

            Subscribable(Subscribable<Args...>&& other)
            {
                *this = std::move(other);
            }

            virtual ~Subscribable() = 0;

            Subscribable<Args...>& operator=(Subscribable<Args...>&& other)
            {
                if (this != &other) {
                    other.remove_all_reciprocal_subscriptions();
                    mSubscriptions = std::move(other.mSubscriptions);
                    for (auto& subscription : mSubscriptions) {
                        create_reciprocal_subscription(*subscription);
                    }
                }

                return *this;
            }

            Subscribable<Args...>& operator+=(Subscribable<Args...>& subscription)
            {
                if (mLocked) {
                    create_deffered_command(DefferedCommand::Type::Subscribe, &subscription);
                } else {
                    if (!subscribed(subscription)) {
                        mSubscriptions.push_back(&subscription);
                        create_reciprocal_subscription(subscription);
                    }
                }

                return *this;
            }

            Subscribable<Args...>& operator-=(Subscribable<Args...>& subscription)
            {
                if (mLocked) {
                    create_deffered_command(DefferedCommand::Type::Unsubscribe, &subscription);
                } else {
                    auto itr = find(subscription);
                    if (subscribed(itr)) {
                        remove_reciprocal_subscription(subscription);
                        mSubscriptions.erase(itr);
                    }
                }

                return *this;
            }

            virtual void operator()(Args... args) = 0;

        public:
            /**
             * Gets this Subscribable's subscriptions.
             * @return This Subscribable's subscriptions
             */
            const std::vector<Subscribable<Args...>*>& subscriptions() const
            {
                return mSubscriptions;
            }

        protected:
            bool subscribed(const Subscribable<Args...>& subscription)
            {
                return subscribed(find(subscription));
            }

            void clear()
            {
                if (mLocked) {
                    create_deffered_command(DefferedCommand::Type::Clear);
                } else {
                    remove_all_reciprocal_subscriptions();
                    mSubscriptions.clear();
                }
            }

        private:
            bool subscribed(const Iterator& subscription) const
            {
                return subscription != mSubscriptions.end();
            }

            Iterator find(const Subscribable<Args...>& subscription)
            {
                return std::find(mSubscriptions.begin(), mSubscriptions.end(), &subscription);
            }

            void create_deffered_command(typename DefferedCommand::Type type, Subscribable<Args...>* subscribable = nullptr)
            {
                mDefferedCommands.push_back(DefferedCommand { type, subscribable });
            }

            void create_reciprocal_subscription(Subscribable<Args...>& subscription)
            {
                subscription.mSubscriptions.push_back(this);
            }

            void remove_reciprocal_subscription(Subscribable<Args...>& subscription)
            {
                subscription.mSubscriptions.erase(subscription.find(*this));
            }

            void remove_all_reciprocal_subscriptions()
            {
                for (auto& subscription : mSubscriptions) {
                    remove_reciprocal_subscription(*subscription);
                }
            }

            void lock()
            {
                mLocked = true;
            }

            void unlock()
            {
                mLocked = false;
                for (const auto& command : mDefferedCommands) {
                    switch (command.type) {
                        case DefferedCommand::Type::Clear:
                            clear();
                            break;

                        case DefferedCommand::Type::Subscribe:
                            operator+=(*command.subscription);
                            break;

                        case DefferedCommand::Type::Unsubscribe:
                            operator-=(*command.subscription);
                            break;
                    }
                }

                mDefferedCommands.clear();
            }
        };

        template <typename ...Args>
        Subscribable<Args...>::~Subscribable()
        {
            remove_all_reciprocal_subscriptions();
        }

        /**
         * Compares two Subscribables for equality.
         * @param [in] obj0 The first object to compare
         * @param [in] obj1 The second object to compare
         * @return Whether or not the two Subscribables are the same object
         */
        template <typename ...Args>
        bool operator==(const Subscribable<Args...>& obj0, const Subscribable<Args...>& obj1)
        {
            return &obj0 == &obj1;
        }

        /**
         * Compares two Subscribables for inequality.
         * @param [in] obj0 The first object to compare
         * @param [in] obj1 The second object to compare
         * @return Whether or not the two Subscribables are not the same object
         */
        template <typename ...Args>
        bool operator!=(const Subscribable<Args...>& obj0, const Subscribable<Args...>& obj1)
        {
            return !(obj0 == obj1);
        }
    } // namespace detail
} // namespace Dynamic_Static