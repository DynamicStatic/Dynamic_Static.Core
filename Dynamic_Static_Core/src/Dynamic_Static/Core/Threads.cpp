
/*
=====================================================================================

    The MIT License(MIT)

    Copyright(c) 2016 to this->moment()->next() Dynamic_Static

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions :

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

=====================================================================================
*/

#include "Dynamic_Static/Core/Threads.hpp"

#include <algorithm>

namespace Dynamic_Static {
    Semaphore::Semaphore(size_t count)
        : mCount { count }
    {
    }

    void Semaphore::notify()
    {
        std::unique_lock<std::mutex> lock(*mMutex);
        mCondition->notify_one();
        ++mCount;
    }

    void Semaphore::wait()
    {
        std::unique_lock<std::mutex> lock(*mMutex);
        mCondition->wait(lock, [&]() { return mCount > 0; });
        --mCount;
    }
}

namespace Dynamic_Static {
    Worker::Worker()
    {
        mThread = std::thread(
            [&]()
            {
                mRunning = true;
                while (mRunning) {
                    mSemaphore.wait();
                    while (!mTasks.empty()) {
                        mMutex->lock();
                        Task& task = mTasks.front();
                        mMutex->unlock();
                        task();
                        mMutex->lock();
                        mTasks.pop();
                        mMutex->unlock();
                    }
                }
            }
        );

        while (!mRunning) {
            std::this_thread::yield();
        }
    }

    Worker::~Worker()
    {
        mRunning = false;
        mSemaphore.notify();
        if (mThread.joinable()) {
            mThread.join();
        }
    }

    size_t Worker::task_count() const
    {
        return mTasks.size();
    }

    void Worker::join() const
    {
        while (mTasks.size()) {
            std::this_thread::yield();
        }
    }

    void Worker::push(const Task& task)
    {
        std::lock_guard<std::mutex> lock(*mMutex);
        mTasks.push(task);
        mSemaphore.notify();
    }
}

namespace Dynamic_Static {
    ThreadPool::ThreadPool(size_t worker_count)
    {
        size_t max_worker_count = std::thread::hardware_concurrency();
        worker_count = worker_count ? worker_count : max_worker_count;
        worker_count = std::min(std::max(size_t { 1 }, worker_count), max_worker_count);
        mWorkers = std::vector<Worker>(worker_count);
    }

    ThreadPool::~ThreadPool()
    {
        join();
    }

    size_t ThreadPool::worker_count() const
    {
        return mWorkers.size();
    }

    size_t ThreadPool::task_count() const
    {
        size_t task_count = 0;
        for (const auto& worker : mWorkers) {
            task_count += worker.task_count();
        }

        return task_count;
    }

    void ThreadPool::join() const
    {
        for (const auto& worker : mWorkers) {
            worker.join();
        }
    }

    void ThreadPool::push(Worker::Task task)
    {
        mWorkers[mWorkerIndex++].push(task);
        if (mWorkerIndex >= mWorkers.size()) {
            mWorkerIndex = 0;
        }
    }
}
