#pragma once
#include <functional>
#include <thread>
#include <vector>
#include <list>
#include <unordered_map>
#include <condition_variable>
#include <shared_mutex>

namespace Pilot
{
    enum class JobType
    {
        LOAD_ASSET,
        GENERATE_COMMAND_BUFFER
    };

    struct Job
    {
        JobType type;
        std::function<void()> content;
    };

    class JobSystem
    {
    public:
        JobSystem();
        void registerJobType(JobType jobType);
        void init();
        void addJob(Job job);
        void wait(JobType jobType);

    private:
        std::list<Job> jobQueue;
        mutable std::shared_mutex queueMutex;
        std::condition_variable queueCv;

        std::vector<std::thread> workerPool;
        std::unordered_map<JobType, std::unique_ptr<std::condition_variable>> jobTypeCvMap;
        std::unordered_map<JobType, uint32_t> jobTypeNumMap;
        mutable std::shared_mutex numMapMutex;

        bool isInit;
        void loop();

        bool getJob(Job& job);

        bool queueEmpty();
        bool jobEmpty(JobType jobType);


    };

}

