#include "job_system.h"
#include <iostream>
using namespace Pilot;

int main()
{
     JobSystem jobhub;
     jobhub.registerJobType(JobType::LOAD_ASSET);
     jobhub.registerJobType(JobType::GENERATE_COMMAND_BUFFER);
     jobhub.init();
     Job job1 = { JobType::LOAD_ASSET,[&] {/*do sth;*/ } };
     jobhub.addJob(job1);
     jobhub.wait(JobType::LOAD_ASSET);
}