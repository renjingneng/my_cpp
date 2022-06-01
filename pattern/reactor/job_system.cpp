#include "job_system.h"

namespace Pilot
{
#pragma region public
    JobSystem::JobSystem() {
        isInit = false;
    }
    void JobSystem::registerJobType(JobType jobType)
    {
        if (isInit) {
            return;
        }
        jobTypeCvMap[jobType] = std::move(std::make_unique<std::condition_variable>());
        jobTypeNumMap[jobType] = 0;
    }
    void JobSystem::init()
    {
        auto numCores = std::thread::hardware_concurrency();
        auto numThreads = std::max(4u, numCores * 2);
        for (uint32_t threadID = 0; threadID < numThreads; ++threadID)
        {
            workerPool.push_back(std::move(std::thread(&JobSystem::loop, this)));
            workerPool[threadID].detach();
        }
        isInit = true;
    }
    void JobSystem::addJob(Job job)
    {
        std::unique_lock lockQueueMutex(queueMutex, std::defer_lock);
        std::unique_lock lockNumMapMutex(numMapMutex, std::defer_lock);
        std::lock(lockQueueMutex, lockNumMapMutex);

        jobQueue.push_back(std::move(job));
        jobTypeNumMap[job.type]++;

        lockQueueMutex.unlock();
        lockNumMapMutex.unlock();

        queueCv.notify_all();
    }
    void JobSystem::wait(JobType jobType)
    {
        std::mutex dummyMutex;
        std::unique_lock dummyLock(dummyMutex);

        jobTypeCvMap[jobType]->wait(dummyLock, [=] {return this->jobEmpty(jobType); });
    }
#pragma endregion
#pragma region private
    void JobSystem::loop() {
        std::mutex dummyMutex;
        std::unique_lock dummyLock(dummyMutex);
        Job job;
        while (true) {
            if (this->getJob(job)) {
                job.content();
                std::unique_lock lockNumMapMutex(this->numMapMutex);
                this->jobTypeNumMap[job.type]--;
                lockNumMapMutex.unlock();
                if (this->jobEmpty(job.type)) {
                    this->jobTypeCvMap[job.type]->notify_all();
                }
            }
            else {
                queueCv.wait(dummyLock, [=] { return !this->queueEmpty(); });
            }
        }
    }

    bool JobSystem::getJob(Job& job)
    {
        std::unique_lock lockQueueMutex(queueMutex);
        if (jobQueue.empty()) {
            return false;
        }
        Job& temp = jobQueue.front();
        job.content = temp.content;
        job.type = temp.type;
        jobQueue.pop_front();
        lockQueueMutex.unlock();
        return true;
    }

    bool JobSystem::queueEmpty()
    {
        std::shared_lock lock(queueMutex);
        if (jobQueue.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
    bool JobSystem::jobEmpty(JobType jobType)
    {
        std::shared_lock lock(numMapMutex);
        if (jobTypeNumMap[jobType] == 0) {
            return true;
        }
        else {
            return false;
        }
    }
#pragma endregion


}