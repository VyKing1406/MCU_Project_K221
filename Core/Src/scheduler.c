/*
 * scheduler.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Vuong
 */
#include "scheduler.h"

typedef struct {
	void (*pTask)(void);
	double Delay;
	double Period;
	int RunMe;
	double TaskID;
} sTask;

sTask SCH_tasks_G[SCH_MAX_TASKS];
void SCH_Update(void) {
	unsigned char index;
	for (index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].pTask) {
			if (SCH_tasks_G[index].Delay == 0) {
				SCH_tasks_G[index].RunMe += 1;
				if (SCH_tasks_G[index].Period) {
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
				}
			} else {
				SCH_tasks_G[index].Delay -= 1;
			}
		}
	}
}

int SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
	unsigned char index = 0;
	while ((SCH_tasks_G[index].pTask != 0) && (index < SCH_MAX_TASKS)) {
		index++;
	}

	if (index == SCH_MAX_TASKS) {
		return -1;
	}
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY;
	SCH_tasks_G[index].Period = PERIOD;
	SCH_tasks_G[index].RunMe = 0;
	return index;
}

void SCH_Dispatch_Tasks(void) {
	unsigned char index;
	for (index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].RunMe > 0) {
			(*SCH_tasks_G[index].pTask)();
			SCH_tasks_G[index].RunMe -= 1;
			if (SCH_tasks_G[index].Period == 0) {
				SCH_Delete_Task(index);
			}
		}
	}
}

int SCH_Delete_Task(const int TASK_INDEX) {
	unsigned char Return_code;
	if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
		Return_code = 0;
	} else {
		Return_code = 1;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	return Return_code;
}
